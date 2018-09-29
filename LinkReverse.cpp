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
	Item *head;                               //����ͷָ��
	Link (){head=NULL;}                       //���캯��
	~Link(){DeleteAll();}
	void Initiate();
	void DeleteAll();
	void HeadCreate(int n);                   //�ӱ�β����ͷ������
	void TailCreate(int n);                   //�ӱ�ͷ����β������
	void HeadCreateWithHead(int n);           //��������ͷ��������ͷ��
    void TailCreateWithHead(int n);            //��������ͷ��������β��
	int Length();
	Item *Locatex(DataType x);             //����ֵΪx������Ԫ��
	Item *Locate(int i);                    //���ҵ�i��Ԫ��
	DataType Get(int i);
	bool Insert (DataType x,int i);         //�������i�����֮ǰ����x
	bool Deleted(int i);                    //ɾ�������е�i�����
	void Print();
	void reverse(Link &H);              //������ĵ���
	void merge(Link &A,Link &B,Link &C);//������Ĺ鲢
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

void Link::HeadCreateWithHead (int n)   //�ӱ�β����ͷ�������������пհ�ͷ��㣩
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

void Link::TailCreateWithHead (int n)     //�ӱ�ͷ����β�������������пհ�ͷ��㣩
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

Item *Link::Locatex (DataType x)    //��ֵ���Ҽ���λ
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

bool Link::Insert(DataType x,int i)            //ǰ����
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

void Link::merge(Link &A,Link &B,Link &C)//C��Ϊ�ǵ�������
{
	//�������÷�ʽ���ݲ���
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
		s->next=C.head->next;      //����C���ͷ��
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
	B.head=NULL;                          //������A��B��headָ���ÿ�
}

int main()
{
	return 0;
}