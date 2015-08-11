#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

typedef struct _tagTeacher
{
	LinkNode p;
	int year;
}Teacher;

int main()
{
	Teacher t1;
	Teacher t2;
	t1.year = 10;
	t2.year = 20;
	LinkList *pLinkList = NULL;
	pLinkList = InitLinkList();
	InsertLinkNode(pLinkList, (LinkNode *)&t1, 0);
	InsertLinkNode(pLinkList, (LinkNode *)&t2, 0);
	int i;
	for (i = 0; i < GetLen(pLinkList); i++)
	{
		Teacher *t = (Teacher *)GetNode(pLinkList, i);
		if (t)
			printf("%d\n", t->year);
	}
	DeleteLinkNode(pLinkList, 0);
	DeleteLinkNode(pLinkList, 0);
	DestoryLink(pLinkList);
	return 0;
}