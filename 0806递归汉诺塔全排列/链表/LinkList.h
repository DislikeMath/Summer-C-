#pragma once

typedef void LinkList;
typedef struct _tagLinkListNode
{
	struct _tagLinkListNode *pNext;
}LinkNode;
typedef struct _tagLink
{
	int m_nLength;
	LinkNode m_LHead;
}Link;

LinkList *InitLinkList();
void InsertLinkNode(LinkList *pLink, LinkNode *pNode, int pos);
LinkNode *DeleteLinkNode(LinkList *pLink, int pos);
int GetLen(LinkList *pLink);
void DestoryLink(LinkList *pLink);
LinkNode *GetNode(LinkList *pLink, int pos);
