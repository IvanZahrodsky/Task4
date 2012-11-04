/**
*@file		Tree.cpp
*@brief		This file contains implementations of function according to task 4
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/

#include "stdafx.h"
#include "Tree.h"
/**
*@brief		This function added item to tree
*@param		[nd,item] 
*@return	void 
*/
void Add ( Node *& nd, UC item )
{
	if ( !nd )
	{
		nd = (Node * ) malloc ( sizeof ( Node ) );
		if ( !nd )
		{
			printf ( "\nError !! Element not Added!\n" );
			return;
		}
		nd->item = item;
		nd->lson = NULL;
		nd->rson = NULL;
	}
	else if ( item >= nd->item )
	{
		Add ( nd->rson , item );
	}
	else
	{
		Add ( nd->lson , item );
	}
}
/**
*@brief		This function print tree in PreOrder
*@param		[nd] 
*@return	void 
*/
void PreOrder ( Node *nd )
{
	if ( !nd )
	{
		return;
	}
	printf ( "%d  ", nd->item );
	PreOrder ( nd->lson );
	PreOrder ( nd->rson );
}
/**
*@brief		This function print tree in InOrder
*@param		[nd] 
*@return	void 
*/
void InOrder ( Node *nd )
{
	if ( !nd )
	{
		return;
	}
	InOrder ( nd->lson );
	printf ( "%d  ", nd->item );
	InOrder ( nd->rson );
}
/**
*@brief		This function print tree in PostOrder
*@param		[nd] 
*@return	void 
*/
void PostOrder ( Node *nd )
{
	if ( !nd )
	{
		return;
	}
	PostOrder ( nd->lson );
	PostOrder ( nd->rson );
	printf ( "%d  ", nd->item );
}
/**
*@brief		This function implements interface
*@param		[void] 
*@return	void 
*/
void Running ( void )
{
	UC action, temp;
	Node *root = NULL;
	printf ( "\nNOTE: Remember please! All the input numbers should be in the range of [0-99]\
			 If you enter more than 2 characters other  will be ignored!!\n\n" );
	while ( true )
	{
		PrintHelp () ;
		Scaning ( action );
		switch ( action )
		{
			case 1:
				printf ( "\nEnter element to add - " );
				Scaning ( temp );
				Add ( root, temp );
				printf ( "Element added!" );
				break;
			case 2:
				if ( root )
				{
					printf ( "\nTree in pre-order traversal :\n" );
					PreOrder ( root );
				}
				else
				{
					printf ( "\nThe tree is empty\n");
				}
				break;
			case 3:
				if ( root )
				{
					printf ( "\nTree in in-order traversal :\n" );
					InOrder (root);
				}
				else
				{
					printf ( "\nThe tree is empty\n");
				}
				break;
			case 4:
				if ( root )
				{
					printf ( "\nTree in post-order traversal :\n" );
					PostOrder (root);
				}
				else
				{
					printf ( "\nThe tree is empty\n");
				}
				break;
			case 7:
				Generate ( root );
				break;
			case 8:
				if ( root )
				{
					printf ( "\nTree in right-traversal :\n" );
					RightTraversal (root);
				}
				else
				{
					printf ( "\nThe tree is empty\n");
				}
				break;
			case 9:
				if ( root )
				{
					Delete ( root );
					printf ( "\nTree is deleted!\n" );
					root = NULL;
				}
				else
				{
					printf ( "\nThe tree is empty\n");
				}
				break;
			case 0:
				printf ( "Thank you =)))\n" );
				Delete ( root );
				root = NULL;
				return;
			default :
				break;
			
		}
	}
}
/**
*@brief		This function scan number
*@param		[temp] 
*@return	void 
*/
void Scaning ( UC &temp)
{
	UC *buf;
	buf = ( UC* ) malloc ( 3 );
	if ( !buf )
	{
		printf ( "\nMemory allocation failed!!\n" );
		return;
	}
	while ( !scanf( "%2[0-9]s" , buf ) )
	{
		printf ( "\nError in scaning number!\n" );
		fflush ( stdin );
	}
	fflush ( stdin );
	temp = atoi ( ( const char* ) buf );
	free ( buf );
}
/**
*@brief		This function print help-text
*@param		[void] 
*@return	void 
*/
void PrintHelp ( void )
{
	printf ( "\nSelect action:\
			  \n1 - Add item\
			  \n2 - PreOrder traversal\
			  \n3 - InOrder traversal\
			  \n4 - PostOrder traversal\
			  \n7 - Generate tree by his left-traversal\
			  \n8 - Print elements of tree in right-traversal\
			  \n9 - Delete tree\
			  \n0 - Exit\n" );
}
/**
*@brief		This function removes tree
*@param		[nd] 
*@return	void 
*/
void Delete ( Node *& nd)
{
	if ( !nd )
	{
		return;
	}
	Delete ( nd->lson );
	Delete ( nd->rson );
	free ( nd );
}
/**
*@brief		This function generate tree
*@param		[nd] 
*@return	void 
*/
void Generate ( Node *& root)
{
	register UC i;
	UC count, temp;
	UC *buf;
	printf ( "\nEnter the count of elements - " );
	Scaning ( count );
	printf ( "\nPlease enter elements in left-traversal\n" );
	Delete ( root );
	root = NULL;
	try
	{
		buf = ( UC* ) malloc ( count );
	}
	catch (...)
	{
		printf ( "\nMemory allocation failed!!\n" );
		return;
	}
	for ( i = 0; i < count; ++i )
	{
		Scaning ( temp );
		buf [ i ] = temp;
	}
	for ( i = count; i > 0; --i )
	{
		Add ( root, buf [ i - 1 ] );
	}
	printf ( "\nTree created!\n " );
	free ( buf );
}
/**
*@brief		This function print tree in RightTraversal
*@param		[temp] 
*@return	void 
*/
void RightTraversal ( Node * nd )
{
	if ( !nd )
	{
		return;
	}
	RightTraversal ( nd->rson );
	RightTraversal ( nd->lson );
	printf ( "%d  ", nd->item );
}


