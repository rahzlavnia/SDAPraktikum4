/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */

#include "spnrsll.h"
#include <stdio.h>
#include "BodyNRSL.cpp"

int main()
{
	/* Kamus Lokal */
		List MyList, List2, List3;
		int i;
		infotype isi;
		address P, Prec;

	/* Program */
	CreateList (&MyList);
/* Menambah List di awal */
	i = 1;
	while (i <= 5)
	{
		InsVLast (&MyList, (char)i+64);
		i++;
	}
	printf ("Hasil InsVLast 5 x adalah : "); PrintInfo (MyList);

/* Mencari suatu elemen di list */

	P = Search(MyList, 'C');
	printf ("Search yang berhasil (C) : P = %x, Ketemu = %d \n",P,FSearch(MyList,P));
	DelP (&MyList, 'C');

/* Insert di Last */
	printf ("Insert di akhir nilai 'X' : ");
	InsVLast (&MyList, 'X');
	PrintInfo (MyList);

/* Insert diantara 2 elemen */
	printf ("Insert sebelum elemen 'B'  : ");
	Prec = SearchPrec (MyList, 'B');
	P = Alokasi ('S');
	if (P != Nil)
	{   InsertAfter (&MyList, P, Prec);	}
	PrintInfo (MyList);

/* Menghapus elemen List */
	printf ("\tHasil Delete dari elemen List :\n");
	DelVFirst (&MyList, &isi);
	printf ("DelVFirst adalah %c\t", isi);

	DelVLast (&MyList, &isi);
	printf ("DelVLast adalah %c\t", isi);

/* Menghapus elemen di tengah-tengah */
	Prec = SearchPrec (MyList, 'B');	/* Node yang akan dihapus */
	if (Prec != Nil)
	{
		 DelAfter (&MyList, &P, Prec);
		 isi = Info(P);
		 DeAlokasi (P);
		 printf ("DelAfter adalah %c\n", isi);
	}
	printf ("Hasil setelah delete : ");
		  PrintInfo (MyList);

	printf ("Insert sebelum elemen 5 : ");
	Prec = SearchPrec (MyList, 'E');
	P = Alokasi ('G');
	if (P != Nil)
	{   InsertAfter (&MyList, P, Prec);	}
	PrintInfo (MyList);

/* Finishing */
	P = First(MyList);
	DeAlokasi (P);
	P = First(List2);
	DeAlokasi (P);
	P = First(List3);
	DeAlokasi (P);
	return 0;
}
