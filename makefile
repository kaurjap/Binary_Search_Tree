runBST: TreeNode.o main.o
	g++ -g -Wall TreeNode.o main.o -o runBST

main.o: TreeNode.h main.cpp
	g++ -g -Wall -c main.cpp

TreeNode.o: TreeNode.h TreeNode.cpp
	g++ -g -Wall -c TreeNode.cpp

debug: runBST
	gdb -tui ./runBST

clean: 
	rm *.o
	rm runBST

run: runBST
	./runBST

valgrind: runBST
	valgrind ./runBST
