#include "SeqList.h"

int main()
{
	CSeqList<int,6> a;
	CSeqList<int, 6> b;
	cin >> a;
	cin >> b;
	a.or(b);
	return 0;
}