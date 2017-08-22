#include <stdexcept>

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
	private:
		BSTNode<dataType> * left;
		BSTNode<dataType> * right;
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
