#include"Tri.h"
using namespace std;

int main(){
	string input;
	TriTree *tree=new TriTree;
	cout<<"**************************************************"<<endl<<endl;
	cout<<"This is a program for test the Tri-nary Tree class"<<endl;
	cout<<"The program iteratively take input"<<endl;
	cout<<"Please closely follow the instruction. since it is"<<endl;
	cout<<"just for test, it cannot check if input is valid"<<endl;
	cout<<"**************************************************"<<endl<<endl;
	while(1){
		cout<<"i for insert, d for delete, f for find and any other input for quit: ";
		cin>>input;
		if(input=="i"){
			int val;
			cout<<"Please input the value you want to insert: ";
			cin>>val;
			tree->insertVal(val);
		}else if (input=="d"){
			int val;
			cout<<"Please input the value you want to delete: ";
			cin>>val;
			tree->deleteVal(val);
		}else if(input=="f"){
			int val;
			cout<<"Please input the value you want to find: ";
			cin>>val;
			if(tree->find(val))
				cout<<"Value "<<val<<" is in tree"<<endl;
			else
				cout<<"Cannot find value "<<val<<endl;
		}
		else
			break;
	}
	return 0;
}
