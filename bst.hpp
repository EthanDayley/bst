#include <stdexcept>
#include <iostream>

using namespace std;

template<class dataType>
class BSTNode {
	public:
		BSTNode();
		~BSTNode();
		dataType getRight();
		dataType getLeft();
		dataType getValue();
		void setRight(BSTNode<dataType> *);
		void setLeft(BSTNode<dataType> *);
		void setValue(dataType);
		BSTNode<dataType> * left = nullptr;
		BSTNode<dataType> * right = nullptr;
		dataType * value;
};


template<class dataType>
BSTNode<dataType>::BSTNode() {}

template<class dataType>
BSTNode<dataType>::~BSTNode() {}

template<class dataType>
dataType BSTNode<dataType>::getRight() {
	return right->getValue();
}

template<class dataType>
dataType BSTNode<dataType>::getLeft() {
	return left->getValue();
}

template<class dataType>
dataType BSTNode<dataType>::getValue() {
	return *value;
}

template<class dataType>
void BSTNode<dataType>::setRight(BSTNode<dataType> * val) {
	right = val;
}

template<class dataType>
void BSTNode<dataType>::setLeft(BSTNode<dataType> * val) {
	left = val;
}

template<class dataType>
void BSTNode<dataType>::setValue(dataType val) {
	dataType * v1 = new dataType;
	*v1 = val;
	value = v1;
}


//now for the actual BST class

template<class dataType>
class BST {
	public:
		BST(){};
		~BST(){};
		//methods
		void addNode(dataType);
		void addNodeRecurse(BSTNode<dataType> *, dataType); //recursively adds a node to the tree
	//private:
		//properties
		size_t numNodes = 0;
		BSTNode<dataType> * rootNode = nullptr;
		//methods
		BSTNode<dataType> * getNodeRecurse(BSTNode<dataType> *, dataType); //root, value
		BSTNode<dataType> * getNode(dataType);               //value
};

template<class dataType>
void BST<dataType>::addNodeRecurse(BSTNode<dataType> * currRoot, dataType value) {
	//std::cout << "in addNodeRecurse\n";
	//std::cout << "value: " << value << std::endl;
	if (currRoot == nullptr) {
		//std::cout << "currRoot == nullptr\n";
		BSTNode<dataType> * n = new BSTNode<dataType>;
		n->setValue(value);
		currRoot = n;
	}
	else if (currRoot->getValue() >= value) {
		addNodeRecurse(currRoot->left, value);
	} 
	else {
		addNodeRecurse(currRoot->right, value);
	}
}
template<class dataType>
void BST<dataType>::addNode(dataType value) {
	/*if (numNodes == 0) {
		BSTNode<dataType> * n1 = new BSTNode<dataType>;
		n1->setValue(value);
		rootNode = n1;
	}*/
	addNodeRecurse(rootNode, value);
}

//recursively fetches a node from the BST based upon a given value and root node
template<class dataType>
BSTNode<dataType> * BST<dataType>::getNodeRecurse(BSTNode<dataType> * currRoot, dataType value) {
	std::cout << "in getNodeRecurse\n";
	//first base case, returns true or a nullptr depending on what it is given
	if (currRoot == nullptr || currRoot->getValue() == value) {
		return currRoot;
	}
	BSTNode<dataType> * right = getNodeRecurse(currRoot->right, value);
	BSTNode<dataType> * left = getNodeRecurse(currRoot->left, value);
	if (right) {
		return right;
	}
	else if (left) {
		return left;
	}
	else {
		return nullptr;
	}
}

//calls the method getNodeRecurse to fetch the node from the BST root
template<class dataType>
BSTNode<dataType> * BST<dataType>::getNode(dataType value) {
	return getNodeRecurse(rootNode, value);
}
