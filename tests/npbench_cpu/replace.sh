# !/bin/bash

for d in */;
do
	for f in $d/*.py;
	do
		if ! grep -Fxq "\@pytest.mark.cpu" $f; then
			sed -i '' -e "s/def test_cpu(/\@pytest.mark.cpu\\
def test_cpu(/g" $f
		fi
	done
done
