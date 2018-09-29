#include <iostream>
using namespace std;


typedef int DataType;
class Item
{
public:
	DataType data;
	Item *next;
	Item(){next=NULL;}
};
class Link
{
public:
	Item *head;                               //链表头指针
	Link (){head=NULL;}                       //构造函数
	~Link(){DeleteAll();}
	void Initiate();
	void DeleteAll();
	void HeadCreate(int n);                   //从表尾到表头建链表
	void TailCreate(int n);                   //从表头到表尾建链表
	void HeadCreateWithHead(int n);           //建立带表头的链表（从头）
    void TailCreateWithHead(int n);            //建立带表头的链表（从尾）
	int Length();
	Item *Locatex(DataType x);             //查找值为x的数据元素
	Item *Locate(int i);                    //查找第i个元素
	DataType Get(int i);
	bool Insert (DataType x,int i);         //在链表第i个结点之前插入x
	bool Deleted(int i);                    //删除链表中第i个结点
	void Print();
	void reverse(Link &H);              //单链表的倒置
	void merge(Link &A,Link &B,Link &C);//单链表的归并
};

void Link::DeleteAll ()
{
	Item *p=head,*q;
	while(p!=NULL)
	{
		q=p->next;
		delete p;
		p=q;
	}
	head=NULL;
}

void Link::Initiate ()
{
	DeleteAll();
	head=NULL;
}
void Link::HeadCreate (int n)
{
	DeleteAll();
	Item *s,*p;
	int i;
	p=NULL;
	for(i=1;i<=n;i++)
	{
		s=new Item();
		cin>>s->data ;
		s->next =p;
		p=s;
	}
	head=p;
}

void Link::TailCreate (int n)
{
	Item *s,*r,*p;
	int i;
	DeleteAll();
	p=NULL;
	for(i=1;i<=n;i++)
	{
		s=new Item();
		cin>>s->data;
		s->next =NULL;
		if(p==NULL)p=r=s;
		else
		{
			r->next=s;
			r=s;
		}
	}
	head=p;

}

void Link::HeadCreateWithHead (int n)   //从表尾到表头建立单链表（带有空白头结点）
{
	Item *s,*p;
	int i;
	DeleteAll();
	p=new Item();
	p->next=NULL;
	for(i=1;i<=n;i++)
	{
		s=new Item();
		cin>>s->data;
		s->next=p->next;
		p->next=s;
	}
	head=p;
}

void Link::TailCreateWithHead (int n)     //从表头到表尾建立单链表（带有空白头结点）
{
	Item *s,*r,*p;
	int i;
	DeleteAll();
	p=new Item();
	p->next =NULL;
	r=p;
	for(i=1;i<=n;i++)
	{
		s=new Item();
		cin>>s->data;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	head=p;
}

int Link::Length ()
{
	int j;
	Item *p;
	j=1;
	p=head->next;
	while(p!=NULL)
	{
		j++;
		p=p->next;
	}
	return --j;
}

Item *Link::Locate (int i)
{
	int j=1;
	Item *p;
	if(i==0)return head;
	p=head->next;
	while((p!=NULL)&&(j<i))
	{
		p=p->next;
		j++;
	}
	if(j==i)return p;
	else
	{
		cout<<"position is not correct!"<<endl;
		return NULL;
	}
}

Item *Link::Locatex (DataType x)    //按值查找即定位
{
	Item *p;
	p=head->next;
	while((p!=NULL)&&(p->data !=x))p=p->next;
	if(p)
		return p;
	else
	{
		cout<<"is not exist!"<<endl;
		return NULL;
	}
}

DataType Link::Get (int i)
{
	int j;
	Item *p;
	j=1;
	p=head->next;
	while((j<i)&&(p!=NULL))
	{
		j++;
		p=p->next;
	}
	if((p=NULL)||(j>i))
	{
		cout<<"position is not correct!<<endl";
		return NULL;
	}
	else return p->data ;
}

bool Link::Insert(DataType x,int i)            //前插结点
{
	Item *p,*s;
	p=Locate(i-1);
	if(p==NULL)
	{
		cout<<"position is not correct!"<<endl;
		return false;
	}
	s= new Item();
	s->data=x;
	s->next=p->next;
	p->next=s;
	return true;
}

bool Link::Deleted (int i)
{
	Item *p=Locate(i-1);
	Item *q;
	if(p==NULL)
	{
		cout<<"position is not correct!"<<endl;
		return false;
	}
	q=p->next;
	if(q!=NULL)
	{
		p->next=q->next;
		delete q;return true;
	}
	else
	{
		cout<<"position is not correct!"<<endl;
		return false;
	}
}

void Link::Print ()
{
	Item *p;
	p=head->next;
	while(p!=NULL)
	{
		cout<<p->data<<"   ";
		p=p->next;
	}
	cout<<endl;
}
void Link::reverse(Link &H)
{
	Item *p,*q;
	p=H.head->next;
	H.head->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		q->next=H.head->next;                
		H.head->next=q;
	}
}

void Link::merge(Link &A,Link &B,Link &C)//C表为非递增有序
{
	//采用引用方式传递参数
	Item *p,*q,*s;
	p=A.head->next;q=B.head->next;
	C.head->next=NULL;
	while((p!=NULL)&&(q!=NULL))
	{
		if(p->data<=q->data)
		{
			s=p;
			p=p->next;
		}
		else
		{
			s=q;
			q=q->next;
		}
		s->next=C.head->next;      //插入C表的头部
		C.head->next=s;
	}  
	if(p==NULL)p=q;
	while(p!=NULL)
	{
		s=p;
		p=p->next;
		s->next=C.head->next;
		C.head->next=s;
	}
	A.head=NULL;
	B.head=NULL;                          //将链表A和B的head指针置空
}

int main()
{
	return 0;
}