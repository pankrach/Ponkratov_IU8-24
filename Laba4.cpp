#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
class Rch
{

public:
	int chis, znam ;
	Rch()
	{
		chis = 0;
		znam = 0;
	}
	Rch( const Rch& r) 
	{
		chis = r.chis;
		znam = r.znam;
	}
	void print() 
	{
		cout << chis << "/"<< znam << " ";
	}
	void Evklid()
	{
		int k;
		if (chis > znam)
		{
			k = chis;
		}
		else
		{
			k = znam;
		}
		for (int i=2; i < k; i++)
		{
			if (chis%i == 0 && znam%i == 0)
			{
				chis = chis / i;
				znam = znam / i;
			}
		}
	}
	Rch & operator =(Rch& a) 
	{
		chis = a.chis;
		znam = a.znam;
		return *this;
	}
	Rch & operator *(Rch& a) 
	{
		a.chis = chis*a.chis;
		a.znam = znam*a.znam;
		int k;
		if (a.chis > a.znam)
		{
			k = a.chis;
		}
		else
		{
			k = a.znam;
		}
		for (int i = 2; i < k; i++)
		{
			if (a.chis%i == 0 && a.znam%i == 0)
			{
				a.chis = a.chis / i;
				a.znam = a.znam / i;
			}
		}
		return a;
	}
	Rch & operator +(Rch& a) 
	{
		a.chis = chis*a.znam+a.chis*znam;
		a.znam = znam*a.znam;
		int k;
		if (a.chis > a.znam)
		{
			k = a.chis;
		}
		else
		{
			k = a.znam;
		}
		for (int i = 2; i < k; i++)
		{
			if (a.chis%i == 0 && a.znam%i == 0)
			{
				a.chis = a.chis / i;
				a.znam = a.znam / i;
			}
		}
		return a;
	}
	 ~Rch()
	{
	}

};


class matrix {
		Rch** T;
		int M;
		int N;
	public:
		matrix(int m, int n) : T(NULL), M(m), N(n)
		{
			T = new Rch*[M]; 
			for (int i = 0; i < M; i++)
			{
				T[i] = new Rch[N]; 
				for (int j = 0; j < N; j++)
					T[i][j] = Rch();
			}
		}
		Rch& operator () (int i, int j)
		{
			return T[i][j];
		}

		void print()
		{
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
					T[i][j].print();
				cout << endl;
			}
			cout << endl << endl;
		}
		matrix & operator &()
		{
			matrix U(N, M);

			for (int i = 0; i<N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					U(i, j) = T[j][i];
				}
			}
			return U;
		}
		matrix  operator *(int a) 
		{
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
					T[i][j].chis = T[i][j].chis*a;
			}
			matrix U(M, N);

			for (int i = 0; i<M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					U(i, j) = T[i][j];
				}
			}
			return U;
		}
		matrix  operator |(matrix& a) 
		{
			
			matrix U(M, N+a.N);

			for (int i = 0; i<M; i++)
			{
				for (int j = 0; j < N+a.N; j++)
				{
					if (j < N)
					{
						U(i, j) = T[i][j];
					}
					else
					{
						U(i, j) = a.T[i][j-N];
					}
				}
			}
			return U;
		}
		~matrix()
		{

		}

};

int main()
{
	int n, m, k, x, y;
	cout << "Kol-vo chisel:";
	cin >> n;

	Rch  *r;
	r = new Rch[n+2];


	cout << "Vvedite drobi:\n ";
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cout << "/\n";
		cin >> y;
		cout << endl;
		r[i].chis = x;
		r[i].znam = y;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "\nChislo №" << (i + 1)<< " ";
		r[i].print();
	}
	cout << "\nVvedite nomera chisel, kotorye budem umnozhat'";
	cin >> m >> k;
	m = m - 1;
	k = k - 1;
	r[n] = r[m] * r[k];
	cout << "\nRezultat";
	r[n].print();
	cout << "\nVvedite nomera chisel, kotorye budem skladyvat''";
	cin >> m >> k;
	m = m - 1;
	k = k - 1;
	r[n + 1] = r[m] + r[k];
	cout << "\nRezultat";
	r[n + 1].print();
	cout << "\n__________\n";
	matrix M(5, 6);

	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			r[i].chis = i+1;
			r[i].znam = j+1;
			M(i, j) = r[i];
		}
	}

	M.print();
	cout << "umnozhenie na chislo\n";
	M = M*7;
	M.print();
	cout << "transponirovanie\n";
	M = &M;
	M.print();
	cout << "kon'uktinaciya\n";
	M = M | M;
	M.print();
	system("pause");
    return 0;
}
