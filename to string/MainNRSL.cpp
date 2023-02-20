/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */

/*Praktikum 4 pengubahan pointer menjadi char*/

#include "spnrsll.h"
#include <stdio.h>
#include "BodyNRSL.cpp"

int main()
{
	/* Kamus Lokal */
		List MyList, List2, List3;
		char *(*s);
		infotype isi;
		address P, Prec;
		int i;

	/* Program */
	CreateList (&MyList);

/* Menambah List di awal */
    s = (char **) malloc (sizeof(char *));
	/* Alokasi string yang merupakan elemen tabel */
	for (i=0; i<5; i++) {	
		*(s + i) = (char *) malloc (sizeof(char)); 
		printf("Input s[%d] : ", i);
		scanf(" %[^\n]%*c", *(s+i)); 

	}

	i=0;
	while (i < 5)
	{
		InsVFirst (&MyList, s[i]);
		i++;
	}
	printf ("Hasil InsVFirst 5 x adalah : "); PrintInfo (MyList);



/* Mencari suatu elemen di list */

	P = Search(MyList, "Spiderman");
	printf ("Search yang berhasil (Spiderman) : P = %x, Ketemu = %d \n",P,FSearch(MyList,P));
	DelP (&MyList, "Spiderman");

/* Insert di Last */
	printf ("Insert di akhir nilai Hulk : ");
	InsVLast (&MyList, "Hulk");
	PrintInfo (MyList);

/* Insert diantara 2 elemen */
	printf ("Insert sebelum elemen Iron Man  : ");
	Prec = SearchPrec (MyList, "Iron Man");
	P = Alokasi ("Thor");
	if (P != Nil)
	{   InsertAfter (&MyList, P, Prec);	}
	PrintInfo (MyList);

/* Menghapus elemen List */
	printf ("\tHasil Delete dari elemen List :\n");
	DelVFirst (&MyList, &isi);
	printf ("DelVFirst adalah %s\t", isi);

	DelVLast (&MyList, &isi);
	printf ("DelVLast adalah %s\t", isi);

/* Menghapus elemen di tengah-tengah */
	Prec = SearchPrec (MyList, "Iron Man");	/* Node yang akan dihapus */
	if (Prec != Nil)
	{
		 DelAfter (&MyList, &P, Prec);
		 isi = Info(P);
		 DeAlokasi (P);
		 printf ("DelAfter adalah %s\n", isi);
	}
	printf ("Hasil setelah delete : ");
		  PrintInfo (MyList);

	printf ("Insert sebelum elemen Captain America : ");
	Prec = SearchPrec (MyList, "Captain America");
	P = Alokasi ("Doctor Strange");
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
