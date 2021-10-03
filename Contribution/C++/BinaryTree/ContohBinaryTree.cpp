#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <windows.h>

using namespace std;

struct Node{
      int data;
      Node *kiri;
      Node *kanan;
};

struct pegawai
{
    int nik;
    char nama[50];
    char jekel;
};

void tambah(Node **root, int databaru)
{
      if((*root) == NULL)
      {
            Node *baru;
            baru = new Node;
            baru->data = databaru;
            baru->kiri = NULL;
            baru->kanan = NULL;
            (*root) = baru;
            (*root)->kiri = NULL;
            (*root)->kanan = NULL;
      }
      else if(databaru<(*root)->data)
            tambah(&(*root)->kiri, databaru);
      else if(databaru>(*root)->data)
            tambah(&(*root)->kanan, databaru);
      else if(databaru == (*root)->data) {
            cout<<"\nNIK pegawai sudah ada."<<endl<<endl;
            system("PAUSE");
      }
}

void preOrder(Node *root)
{
      if(root != NULL){
            cout<<endl<<root->data;
            preOrder(root->kiri);
            preOrder(root->kanan);
      }
}

void inOrder(Node *root)
{
      if(root != NULL){
            inOrder(root->kiri);
            cout<<endl<<root->data;
            inOrder(root->kanan);
      }
}

void postOrder(Node *root)
{
      if(root != NULL){
            postOrder(root->kiri);
            postOrder(root->kanan);
            cout<<endl<<root->data;
      }
}

int main()
{
      int data;// c;
      int data2 = 0;
      char pil;
      Node *pohon; //*t;
      pohon = NULL;
      pegawai pgw[15]; //data pegawai yang bisa disimpan di set hanya sampai 15
      //perulangan do-while
      do
      {
            system("cls"); //bersihkan layar
            cout<<"\n\t\t ============================";
            cout<<"\n\t\t ||  PROGRAM BINARY TREE   ||";
            cout<<"\n\t\t ============================";
            cout<<"\n\nMENU PILIHAN";
            cout<<"\n-------------\n";
            cout<<"1. Tambah Data\n";
            cout<<"2. Cek PreOrder\n";
            cout<<"3. Cek InOrder\n";
            cout<<"4. Cek PostOrder\n";
            cout<<"5. Keluar\n";
            cout<<"Masukkan pilihan Anda (1-5) = ";
            cin>>pil;
            if (pil != '1' && pil != '2' && pil != '3' && pil != '4' && pil != '5') {
                cout<<"Anda salah memasukkan pilihan. Coba lagi.\n\n";
                system("PAUSE");
            } else {
                if (pil == '1') {
                    system("cls"); //bersihkan layar
                    cout<<"\n\t\t ============================";
                    cout<<"\n\t\t ||  PROGRAM BINARY TREE   ||";
                    cout<<"\n\t\t ============================";
                    cout<<"\n\nMasukkan NIK Pegawai : ";
                    cin>>pgw[data2].nik;
                    cin.ignore();
                    cout<<"Masukkan Nama Pegawai : "<<flush;
                    gets(pgw[data2].nama);
                    ulang:
                    cout<<"Pilih Jenis Kelamin : ";
                    cout<<"\n\tA. Laki-laki";
                    cout<<"\n\tB. Perempuan\n";
                    cout<<"Pilih : ";
                    cin>>pgw[data2].jekel;

                    if (pgw[data2].jekel != 'a' && pgw[data2].jekel != 'A' && pgw[data2].jekel != 'b' && pgw[data2].jekel != 'B') {
                        cout<<"\nAnda salah memilih jenis kelamin. Coba lagi.\n\n";
                        cout<<"\n\n";
                        goto ulang;
                    }

                    //panggil fungsi untuk menambah node yang berisi data pada tree
                    data = pgw[data2].nik;
                    tambah(&pohon, data);
                    data2++;
                } else if (pil == '2') {
                    system("cls"); //bersihkan layar
                    cout<<"\n\t\t ============================";
                    cout<<"\n\t\t ||  PROGRAM BINARY TREE   ||";
                    cout<<"\n\t\t ============================";
                    cout<<"\n\nOUTPUT PRE ORDER : ";
                    cout<<"\n------------------\n";
                    if(pohon!=NULL) {
                        cout<<"\nNIK Pegawai sesuai PRE ORDER : ";
                        //panggil fungsi untuk mencetak data secara preOrder
                        preOrder(pohon);
                        for (int x=0; x < data2; x++) {
                            cout<<"\n\nData Ke - "<<x+1;
                            cout<<"\nNIK Pegawai : "<<pgw[x].nik;
                            cout<<"\nNama Pegawai : "<<pgw[x].nama<<endl;
                            cout<<"Jenis Kelamin : ";
                            if (pgw[x].jekel == 'a' || pgw[x].jekel == 'A') {
                                cout<<"Laki-laki";
                            } else if (pgw[x].jekel == 'b' || pgw[x].jekel == 'b') {
                                cout<<"Perempuan";
                            }
                            cout<<endl;
                        }
                        cout<<"\n\n";
                        system("PAUSE");
                    } else {
                        cout<<"Data masih kosong.";
                        cout<<endl<<endl;
                        system("PAUSE");
                    }
                } else if (pil == '3') {
                    system("cls"); //bersihkan layar
                    cout<<"\n\t\t ============================";
                    cout<<"\n\t\t ||  PROGRAM BINARY TREE   ||";
                    cout<<"\n\t\t ============================";
                    cout<<"\n\nOUTPUT IN ORDER : ";
                    cout<<"\n------------------\n";
                    if(pohon!=NULL) {
                        //panggil fungsi untuk mencetak data secara inOrder
                        cout<<"\nNIK Pegawai sesuai IN ORDER : ";
                        inOrder(pohon);
                        for (int x=0; x < data2; x++) {
                            cout<<"\n\nData Ke - "<<x+1;
                            cout<<"\nNIK Pegawai : "<<pgw[x].nik;
                            cout<<"\nNama Pegawai : "<<pgw[x].nama<<endl;
                            cout<<"Jenis Kelamin : ";
                            if (pgw[x].jekel == 'a' || pgw[x].jekel == 'A') {
                                cout<<"Laki-laki";
                            } else if (pgw[x].jekel == 'b' || pgw[x].jekel == 'b') {
                                cout<<"Perempuan";
                            }
                            cout<<endl;
                        }
                        cout<<"\n\n";
                        system("PAUSE");
                    } else {
                        cout<<"Data masih kosong.";
                        cout<<endl<<endl;
                        system("PAUSE");
                    }
                } else if (pil == '4') {
                    system("cls"); //bersihkan layar
                    cout<<"\n\t\t ============================";
                    cout<<"\n\t\t ||  PROGRAM BINARY TREE   ||";
                    cout<<"\n\t\t ============================";
                    cout<<"\n\nOUTPUT POST ORDER : ";
                    cout<<"\n------------------\n";
                    if(pohon!=NULL) {
                        //panggil fungsi untuk mencetak data secara postOrder
                        cout<<"\nNIK Pegawai sesuai POST ORDER : ";
                        postOrder(pohon);
                        for (int x=0; x < data2; x++) {
                            cout<<"\n\nData Ke - "<<x+1;
                            cout<<"\nNIK Pegawai : "<<pgw[x].nik;
                            cout<<"\nNama Pegawai : "<<pgw[x].nama<<endl;
                            cout<<"Jenis Kelamin : ";
                            if (pgw[x].jekel == 'a' || pgw[x].jekel == 'A') {
                                cout<<"Laki-laki";
                            } else if (pgw[x].jekel == 'b' || pgw[x].jekel == 'b') {
                                cout<<"Perempuan";
                            }
                            cout<<endl;
                        }
                        cout<<"\n\n";
                        system("PAUSE");
                    } else {
                        cout<<"Data masih kosong.";
                        cout<<endl<<endl;
                        system("PAUSE");
                    }
                }
            }
      }while(pil != '5'); //akan diulang jika input tidak sama dengan 5
}
