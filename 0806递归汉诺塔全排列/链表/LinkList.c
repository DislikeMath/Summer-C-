#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

LinkList *InitLinkList()
{
	Link *pLink = (Link *)malloc(sizeof(Link));
	pLink->m_nLength = 0;
	pLink->m_LHead.pNext = NULL;
	return pLink;
}

void InsertLinkNode(LinkList *pLink, LinkNode *pNode, int pos)
{
	Link *pTem = (Link *)pLink;
	LinkNode *pCurrent = &pTem->m_LHead;
	int i = 0;
	while (i < pos && pCurrent->pNext != NULL)
	{
		pCurrent = pCurrent->pNext;
		i++;
	}
	
	pNode->pNext = pCurrent->pNext;
	pCurrent->pNext = pNode;
	pTem->m_nLength++;
}

LinkNode *DeleteLinkNode(LinkList *pLink, int pos)
{
	Link *pTem = (Link *)pLink;
	LinkNode *pCurrent = &pTem->m_LHead;
	int i = 0;
	while (i < pos && pCurrent->pNext != NULL)
	{
		pCurrent = pCurrent->pNext;
		i++;
	}

	LinkNode *node = pCurrent->pNext;
	pCurrent->pNext = node->pNext;
	pTem->m_nLength--;
	return node;
}

int GetLen(LinkList *pLink)
{
	Link *pTem = (Link *)pLink;
	return pTem->m_nLength;
}

void DestoryLink(LinkList *pLink)
{
	Link *pTem = (Link *)pLink;
	if (pTem)
	{
		free(pTem);
	}
}

LinkNode *GetNode(LinkList *pLink, int pos)
{
	Link *pTem = (Link *)pLink;
	LinkNode *pCurrent = &pTem->m_LHead;
	int i = 0;
	while (i < pos && pCurrent->pNext != NULL)
	{
		pCurrent = pCurrent->pNext;
		i++;
	}
	return pCurrent->pNext;
}
