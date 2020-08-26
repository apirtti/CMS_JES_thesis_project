#!bin/bash/

file=greedy_pythia8/settings.py

#sed -i 's/f.write("Random:seed = 12\n\n")/f.write("Random:seed = 13\n\n")/g' $file

old_seed=1

for i in {1..50}
do
	echo $old_seed $i
	sed -i "s/Random:seed = $old_seed/Random:seed = $i/g" $file
	old_seed=$i

make gpythia8
make run_gpythia8

mv pjets_pythia8_dijet_9000000.root dijet_9000000_$i.root

done

#sed -i 's/Random:seed = 2/Random:seed = 3/g' $file


#mv pjets_pythia8_dijet_2000.root dijet_2000_1.root

#sed -i 's/Random:seed = 3/Random:seed = 4/g' $file

#make gpythia8
#make run_gpythia8

#mv pjets_pythia8_dijet_2000.root dijet_2000_2.root
