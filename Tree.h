/**
*@file		Tree.h
*@brief		This file contains interface of function according to task 4
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/
#ifndef _TREE_H_
#define _TREE_H_
#include "stdafx.h"

typedef unsigned char UC;

struct Node
{
	UC item;
	Node *lson;
	Node *rson;
};

/**
*@brief		This function added item to tree
*@param		[nd,item] 
*@return	void 
*/
void Add ( Node *& , UC );
/**
*@brief		This function print tree in PreOrder
*@param		[nd] 
*@return	void 
*/
void PreOrder ( Node* );
/**
*@brief		This function print tree in InOrder
*@param		[nd] 
*@return	void 
*/
void InOrder ( Node* );
/**
*@brief		This function print tree in PostOrder
*@param		[nd] 
*@return	void 
*/
void PostOrder ( Node* );
/**
*@brief		This function implements interface
*@param		[void] 
*@return	void 
*/
void Running ( void );
/**
*@brief		This function scan number
*@param		[temp] 
*@return	void 
*/
void Scaning ( UC &);
/**
*@brief		This function print help-text
*@param		[void] 
*@return	void 
*/
void PrintHelp ( void );
/**
*@brief		This function removes tree
*@param		[nd] 
*@return	void 
*/
void Delete ( Node *& );
/**
*@brief		This function generate tree
*@param		[nd] 
*@return	void 
*/
void Generate ( Node *& );
/**
*@brief		This function print tree in RightTraversal
*@param		[temp] 
*@return	void 
*/
void RightTraversal ( Node * );

#endif //_TREE_H_