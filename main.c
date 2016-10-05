#include <iostream>  
using namespace std;  
  
/*实现一元多项式的加法*/  
  
struct PolyNode  
{  
    int coef;  //多项式的系数 
    int expn;    //多项式的指数 
    PolyNode *next;   //指向下一个结点的指针 
};  
  
void InitList(PolyNode *&L)     //初始化多项式单链表  
{  
    L = new PolyNode;        //生成一个头结点
    L->next = NULL;  
}  
  
void InsertNode(PolyNode *&L, int c, int e, int i)  //在多项式链表的第i个位置插入结点  
{  
    PolyNode *p, *q;  
    q = new PolyNode;  
    q->coef = c;  
    q->expn = e;  
    q->next = NULL;  
    p = L;  
    int j = 1;  
    while (j < i)     //i到第i-1个结点，在它的后面插入结点  
    {  
        p = p->next;  
        ++j;  
    }  
    q->next = p->next;  
    p->next = q;  
}  
  
void printt(PolyNode *L,int arr[])   //打印多项式  
{  
    PolyNode *p;
    int i=0;
    p = L->next;  
    while (p != NULL)  
    {  
    	arr[i]=p->coef;
    	i++;
    	p=p->next;
    }  
}  

void print(PolyNode *L)   //按指数非递减给多项式排序  
{  
    PolyNode *p;  
    p = L->next;  
    while (p != NULL)  
    {  
        cout << "(" << p->coef <<","<<p->expn<< ") ";  
        p = p->next;  
    }  
    cout << endl;  
}  

  
void SortList(PolyNode *&L)     //°´Ö¸Êý·ÇµÝ¼õ¸ø¶àÏîÊ½ÅÅÐò  
{   
    PolyNode *p, *q, *pre;  
    p = L->next;  
    L->next = NULL;  
    while (p != NULL)  
    {  
        if (L->next == NULL)       //处理第一个结点   
        {  
            L->next = p;  
            p = p->next;  
            L->next->next = NULL;  
        }  
        else         //处理剩余其他结点  
        {  
            pre = L;  
            q = pre->next;  
            while (q && q->expn < p->expn)  
            {  
                pre = q;  
                q = q->next;  
            }  
            q = p->next;  
            p->next = pre->next;  
            pre->next = p;  
            p = q;  
        }  
    }  
}  
  
void CreateList(PolyNode *&L, int C[], int E[], int n)     //创建多项式单链表  
{  
    int i;  
    InitList(L);  
    for (i = 0; i < n; i++)  
    {  
        InsertNode(L, C[i], E[i], i+1);  
    }  
}  
  
PolyNode *AddPoly(PolyNode *L1, PolyNode *L2)       //一元多项式相加  
{  
    PolyNode *pa, *pb, *s, *pc,*p;   
    PolyNode *tc;   //创建尾节点  
    pc = new PolyNode;  
    pc->next = NULL;    /*pc为新建单链表的头结点*/  
    tc = pc;            /*tc始终指向新建单链表的最后结点*/  
    pa = L1->next;  
    pb = L2->next;   //获得多项式单链表的第一个结点 
    while (pa!=NULL && pb!=NULL)    //pa,pb都不为空，就进行比较，否则，跳出while 
    {  
        if (pa->expn < pb->expn)         //将*pa结点复制到*s并链到pc尾  
        {  
            s = new PolyNode;  
            s->coef = pa->coef;  
            s->expn = pa->expn;  
            s->next = NULL;  
            tc->next = s;  
            tc = s;  
            pa = pa->next;  
        }  
        else if (pa->expn > pb->expn)      //将*pb结点复制到*s并链到pc尾  
        {  
            s = new PolyNode;  
            s->coef = pb->coef;  
            s->expn = pb->expn;  
            s->next = NULL;  
            tc->next = s;  
            tc = s;  
            pb = pb->next;  
        }  
        else         //pa->expn=pa->expn时的情况 
        {  
            if (pa->coef+pb->coef!=0)     //如果相加系数之和不为0，则将新结点插在tc后面  
            {  
                s= new PolyNode;  
                s->coef = pa->coef + pb->coef;  
                s->expn = pa->expn;  
                s->next = NULL;  
                tc->next = s;   
                tc = s;  
            }  
            pa = pa->next;   //跳过当前的结点，继续后面的结点的比较  
            pb = pb->next;  
        }  
    }  
    //将尚未扫描完的余下结点复制并链接到pc单链表之后 
    if (pa != NULL)          
        p = pa;  
    else                  
        p = pb;  
    while (p != NULL)     
    {  
        s = new PolyNode;  
        s->coef = p->coef;  
        s->expn = p->expn;  
        s->next = NULL;  
        tc->next = s;  
        tc = s;  
        p = p->next;  
    }  
    return pc;  
}  
  
void inttoarr(int i,int arr[]){     
	int in=0,j;
	while(i)
	{
	arr[in]=i%10;
	in++;
	i/=10;
	}
	while(in--) cout<<arr[in]<<" ";
}
  
int num_first(int i){         //位数 
	int i_first,j,in=0;
	while(i) {
	i_first = i%10;
	in++;
	i/=10;	
	}
	cout << "i first:" << i_first << endl;
	return i_first;
}  
  
void change(int array[],int n){     //转换显示格式
    int i,temp;
    for( i=0 ; i<n/2 ; i++ ) 
    {
        temp=array[i];
        array[i]=array[n-1-i];
        array[n-1-i]=temp;
    }
} 
  
int main()  
{  
    int i = 510012;
    int N = num_first(i);
    int arr[N];    
    inttoarr(i,arr);
    int c1[N-1];
    change(arr,N);
    for(int j=0;j<N;j++){
    	cout<<arr[j];
    }
    cout<<endl;
    for(int j=0;j<N;j++){
    	c1[j]=arr[j];
    }
    int e1[N];
    for(int j=0;j<N;j++){
    	e1[j]=N-1-j;
    }
    for(int j=0;j<N;j++){
    	cout<<e1[j];
    }
    cout<<endl;

    int i2=3102;
    int N2 = num_first(i2);
    int arr2[N2];    
    inttoarr(i2,arr2);
    int c2[N2-1];
    change(arr2,N2);
    for(int j=0;j<N2;j++){
    	cout<<arr2[j];
    }
    cout<<endl;
    for(int j=0;j<N2;j++){
    	c2[j]=arr2[j];
    }
    int e2[N2];
    for(int j=0;j<N2;j++){
    	e2[j]=N2-1-j;
    }
    for(int j=0;j<N2;j++){
    	cout<<e2[j];
    }
    cout<<endl;
    
    PolyNode *La, *Lb, *Lc;  
    InitList(La);  
    InitList(Lb);  
    InitList(Lc);  
    CreateList(La, c1, e1, N);  
    CreateList(Lb, c2, e2, N2);  
//    cout << "原多项式为：" << endl;  
//    print(La);  
//    print(Lb);  
    SortList(La);  
    SortList(Lb);  
//    cout << "按指数非递减排序后的多项式：" << endl;  
//    print(La);  
//    print(Lb);  
//    cout << "多项式相加的结果为：" << endl;  
    Lc = AddPoly(La,Lb);
    int N3 = ((N>N2)?N:N2)+1;
    int arr3[N3];
//    print(Lc); 
    printt(Lc,arr3);
    arr3[N3-1]=N3-1;
    change(arr3,N3);
    for(int j=0;j<N3;j++){
    cout<<arr3[j];
    }
    cout<<endl;
    
    return 0;  
}  