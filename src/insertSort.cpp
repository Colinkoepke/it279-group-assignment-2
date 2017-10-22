#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct Node {
    long data;
    Node *next;
    Node(long x) : data(x), next(NULL) {}
};

Node * Add(Node *head, long num)
{
    Node *temp = new Node(num);
    temp->next = head;
    return temp;
}

Node * SortedInsert(Node * head, Node *newNode )
{
	
  if( head == NULL || head->data >= newNode->data)
  {
    newNode->next = head;
    head = newNode;
    return head;
  }	
  Node *ptr = head;
  Node *prev = NULL;
  while ( ptr != NULL && ptr->data < newNode->data )
  {
    prev = ptr;
    ptr = ptr->next;
  }
  newNode->next = ptr;
  prev->next = newNode;
  return head;
}

Node* InsertionSort(Node *head)
{
  if( !head || !head->next )
    return head;
	  
  Node * ptr = head->next;
  Node * result = head;
  result->next = NULL;

  while ( ptr )
  {
    Node *temp = ptr;
    ptr = ptr->next;
    result = SortedInsert(result,temp);
  }
  
  return result;
}

void Print(Node *head)
{
	while( head )
	{
	  cout << head->data << endl;
	  head = head->next;
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	string fileName = argv[1];
	string outputFile = argv[2];
	ifstream longsFile;
	longsFile.open(fileName.c_str());
	long readVal; 
	bool firstVal = true;
	Node* head;
	
	if(!longsFile){
	  cerr << "Unable to open file";
	  exit(1);
	  
	}else{
	  while(!longsFile.eof()){
	    if(firstVal == true){
	      longsFile >> readVal;
	      head = new Node(readVal);
	      firstVal = false;
	    }else{
	      longsFile >> readVal;
	      head = Add(head,readVal);
	    }
	  }
	}
	head = InsertionSort(head);
	
	ofstream outFile;
	outFile.open(outputFile.c_str());
	if(outFile.is_open()){
	  while( head )
	  {
	    outFile << head->data << endl;
	    head = head->next;
	  }
	  outFile.close();
	}else{
	  cout<< "Unable to create file";
	}
	return 0;
}
