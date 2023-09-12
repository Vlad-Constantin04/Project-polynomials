//Suma si produsul a 2 polinoame prin alta metoda fata de cea de la curs
#include <iostream>
#include <stdio.h>//biblioteca pentru printf,scanf
#include <conio.h>
#include <ctype.h>
#include <malloc.h>
using namespace std;
typedef struct
{
    int grad;       // structura de tip polinom
    int* coef;   //avem gradul polinomului si vect coef pol
} polinom;

//citim gradul si coef unui pol
void citpol(polinom* pol,char ch)
{
    int i;

    printf("Gradul lui %c = ",ch);
    scanf("%d",&pol->grad);

    pol->coef=(int*)malloc( sizeof(int) *(pol->grad+1));

    if (pol->coef==NULL)
    {
        cout<<"Memorie insuficienta!\n";
        exit(1);
    }

    for (i=0; i<=pol->grad; i++)
    {
        printf("coef[%d] = ",i);
        scanf("%d",&pol->coef[i]);
    }
}

//Afisam un polinom
void afispol(polinom p)
{
    int i;

    cout<<"P=";

    for (i=p.grad; i>0; i--) //Afisam pol descrescator
        if (p.coef[i] != 0)
            printf("%d*X^%d+",p.coef[i],i);//Afisam doar termenii cu coeficient diferit de 0

    if (p.coef[0] != 0 || p.grad == 0)
        printf("%d",p.coef[0]);
    cout<<endl;
    //Daca coef ultimului termen,x^0,e nenul,afisam doar coef(in loc de 3*x^0 afisam 3 pentru ca x^0 e 1)
}


//Calculam suma a 2 polinoame
void suma(polinom p,polinom q,polinom* r)
{
    int i;

    if (q.grad != p.grad) //daca nu au acelasi grad
    {
        r->grad = (p.grad>q.grad) ? p.grad : q.grad; //maximul celor 2 grade
        r->coef=(int*)malloc( sizeof(int) * (r->grad+1) );

        if (r->coef==NULL)
        {
            cout<<"Memorie insuficienta!\n";
            exit(1);
        }
        //Se determina polinomul cu gradul cel mai mic
        if (p.grad < q.grad)
            for (i=0; i<=q.grad; i++)
                if (i<=p.grad)
                    r->coef[i]=p.coef[i]+q.coef[i];
                else r->coef[i]=q.coef[i];

        else //q.grad<p.grad
            for (i=0; i<=p.grad; i++)
                if (i<=q.grad)
                    r->coef[i]=p.coef[i]+q.coef[i];
                else r->coef[i]=p.coef[i];
    }
    else  //Daca au gradele egale
    {
        i=p.grad;
        //Se afla gradul polinomului rezultat
        while (i>0 && p.coef[i]+q.coef[i]==0)
            i--;
        r->grad=i;
        r->coef=(int*)malloc( sizeof(int) * (r->grad+1) );
        if (r->coef==NULL)
        {
            cout<<"Memorie insuficienta!\n";
            exit(1);
        }
        for (i=0; i<=r->grad; i++)
            r->coef[i]=p.coef[i]+q.coef[i];
    }
}



//Calculam produsul a 2 polinoame de grade diferite,rezultatul punandu-l intr-un al 3-lea polinom
void produs(polinom p,polinom q,polinom* r)
{
    int i,j;

    r->grad=p.grad+q.grad;
    r->coef=(int*)malloc( sizeof(int) * (r->grad+1) );

    if (r->coef==NULL)
    {
        cout<<"Memorie insuficienta !";
        exit(1);
    }
    for (i=0; i<=r->grad; i++)
        r->coef[i]=0;
    //Am initializat coef pol produs cu 0
    for (i=0; i<=p.grad; i++)
        for(j=0; j<=q.grad; j++)
            r->coef[i+j]+=p.coef[i]*q.coef[j];
}


int main()
{
    char ch;
    int a;
    polinom p,q,c,r;

    while(1)
    {

        cout<<"1. Suma a doua polinoame\n";
        cout<<"2. Produsul a doua polinoame\n";
        cout<<"3. Exit \n";
        ch = toupper(getch());

        switch(ch)
        {
        case '1':
            citpol(&p,'f'); //polinom 1
            citpol(&q,'q');	//polinom 2
            suma(p,q,&r);
            afispol(r);
            free(p.coef);
            free(q.coef);
            free(r.coef);
            break;
        case '2':
            citpol(&p,'f'); //polinom 1
            citpol(&q,'q');	//polinom 2
            produs(p,q,&r);
            afispol(r);
            free(p.coef);
            free(q.coef);
            free(r.coef);
            break;

        case '3':
            return 0;
        }
    }
}
