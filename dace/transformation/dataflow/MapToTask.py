# Copyright 2019-2021 ETH Zurich and the DaCe authors. All rights reserved.
""" Contains classes that implement the trivial map range elimination transformation. """

import sys
from dace import registry
from dace.dtypes import OMPTaskingBlockType, OMPTaskingScopeType, ScheduleType
from dace.sdfg import nodes
from dace.sdfg import utils as sdutil
from dace.transformation import transformation
from dace.properties import make_properties


@make_properties
class MapToTask(transformation.SingleStateTransformation):
    """ Converts a tree of maps rooted at an access node to tasks.

        Example: A->M1-> //todo
    """

    access_node = transformation.PatternNode(nodes.AccessNode)
    map_entry = transformation.PatternNode(nodes.MapEntry)

    @classmethod
    def expressions(cls):
        return [sdutil.node_path_graph(cls.access_node, cls.map_entry)]

    def can_be_applied(self, graph, expr_index, sdfg, permissive=False):
        successors = graph.successors(self.access_node)
        if len(successors) < 2: return False
        for node in successors:
            if not isinstance(node, nodes.MapEntry):
                return False
        return True

    def apply(self, graph, sdfg):
        successors = graph.successors(self.access_node)
        print(successors, file=sys.stderr)
        for i, node in enumerate(successors):
            node.map.schedule = ScheduleType.CPU_Multicore_Tasking_Block
            node.map.omp_tasking_block = OMPTaskingBlockType.StartAndEnd
        if i == 0:
            node.map.omp_tasking_scope = OMPTaskingScopeType.Start
        if i == len(successors) - 1:
            node.map.omp_tasking_scope = OMPTaskingScopeType.End