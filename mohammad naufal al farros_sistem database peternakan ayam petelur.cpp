#include <bits/stdc++.h>
#include <fstream>
using namespace std;

typedef struct {
    string kodekandang;
    string jenisayam;
    string banyaktelur;
    string umurayam;
    string jumlahpakan;
    string pemberianvitamin;
}peternakan;

bool cmp(peternakan a, peternakan b)
{
    if(a.kodekandang.size() == b.kodekandang.size())
    return (a.kodekandang<b.kodekandang); 
    return (a.kodekandang.size() < b.kodekandang.size());
}

bool cmp_first_elemen(peternakan a, peternakan b)
{
    return (a.kodekandang < b.kodekandang); 
}

int upperBound(string acuan, vector <peternakan> ternak, int l, int r)
{
	int mid = l + (r - l) / 2;
	while(l < r)
	{
		if(ternak[mid].kodekandang<=acuan)
			l = mid + 1;
		else
			r=mid;
		mid = l + (r - l) / 2;
	}
    return mid - 1;
}
void simpan(ofstream &data, vector <peternakan> ternak){
    data.open("database.txt", fstream::out);
    int index = 0;
    for (auto it:ternak)
    {
        data << it.kodekandang<<endl
             << it.jenisayam<<endl
             << it.banyaktelur<<endl
             << it.umurayam<<endl
             << it.jumlahpakan<<endl
             << it.pemberianvitamin;
        if (index<ternak.size()-1)
        {
            data << endl;
        }
        index++;
    }
    data.close();
}
int main()
{
    vector <peternakan> ternak;
    peternakan temp;
    ofstream writedata;
    ifstream readdata;

    readdata.open("database.txt", fstream::in);
    if(readdata)
    {
        while(!readdata.eof())
        {
            readdata >> temp.kodekandang
                     >> temp.jenisayam
                     >> temp.banyaktelur
                     >> temp.umurayam
                     >> temp.jumlahpakan
                     >> temp.pemberianvitamin;
            ternak.push_back(temp);
        }
        
    }
    readdata.close();
    cout << ternak.size() << endl;

    while (1)
    {
        cout<<"masuk\n";
        int input;
        cout << "\nProgram Database Peternakan" << endl;
        cout << "=============================" << endl;
        cout << "1. Tambah data" << endl;
        cout << "2. Tampilkan data" << endl;
        cout << "3. Ubah data" << endl;
        cout << "4. Hapus data" << endl;
        cout << "5. Urutkan data" << endl;
        cout << "6. Cari data" << endl;
        cout << "7. Simpan data dalam .txt" << endl;
        cout << "8. Selesai" << endl;
        cout << "=============================" << endl;
        cout << "pilih [1-8]? : ";
        cin >> input;
        if(input == 1)
        {
            // tambahkan data
            cout << "Masukkan Data\n";
            cout << "kode kandang : ";
            cin >> temp.kodekandang;
            cout << "jenis ayam : ";
            cin >> temp.jenisayam;
            cout << "banyak telur : ";
            cin >> temp.banyaktelur;
            cout << "umur ayam : ";
            cin >> temp.umurayam;
            cout << "jumlah pakan : ";
            cin >> temp.jumlahpakan;
            cout << "pemberian vitamin : ";
            cin >> temp.pemberianvitamin;
            ternak.push_back(temp);
            sort(ternak.begin(), ternak.end(), cmp);
        }
        else if(input == 2)
        {
            //tampilkan data secara terurut
            sort(ternak.begin(), ternak.end(), cmp);
            for(int i = 0; i < ternak.size(); i++ )
            {
                cout << "\nkode kandang : " << ternak[i].kodekandang;
                cout << "\njenis ayam : " << ternak[i].jenisayam;
                cout << "\nbanyak telur : " << ternak[i].banyaktelur;
                cout << "\numur ayam : " << ternak[i].umurayam;
                cout << "\njumlah pakan : " << ternak[i].jumlahpakan;
                cout << "\npemberian vitamin : " << ternak[i].pemberianvitamin;
                cout << endl << endl << endl;
            }
        }
        else if(input == 3)
        {
            // edit data yang akan diubah
            string edit;
            cout << "masukkan kode kandang yang akan diubah datanya: ";
            cin >> edit;
            int pilih;
            sort(ternak.begin(), ternak.end(), cmp_first_elemen);
            int index = upperBound(edit, ternak, 0, ternak.size());
            if(ternak[index].kodekandang==edit)
            {
                cout << "Pilih data yang akan diubah: " << endl;
                cout << "1. kode kandang" << endl;
                cout << "2. jenis ayam" << endl;
                cout << "3. banyak telur" << endl;
                cout << "4. umur ayam" << endl;
                cout << "5. jumlah pakan" << endl;
                cout << "6. pemberian vitamin" << endl;
                cout << "pilih [1-6] : ";
                cin >> pilih;
                if (pilih == 1)
                {
                    cout << "masukkan data yang akan diubah : ";
                    cin >> edit;
                    ternak[index].kodekandang = edit;
                }
                else if (pilih == 2)
                {
                    cout << "masukkan data yang akan diubah : ";
                    cin >> edit;
                    ternak[index].jenisayam = edit;
                }
                else if (pilih == 3)
                {
                    cout << "masukkan data yang akan diubah : ";
                    cin >> edit;
                    ternak[index].banyaktelur = edit;
                }
                else if (pilih == 4)
                {
                    cout << "masukkan data yang akan diubah : ";
                    cin >> edit;
                    ternak[index].umurayam = edit;
                }
                else if (pilih == 5)
                {
                    cout << "masukkan data yang akan diubah : ";
                    cin >> edit;
                    ternak[index].jumlahpakan = edit;
                }
                else if (pilih == 6)
                {
                    cout << "masukkan data yang akan diubah : ";
                    cin >> edit;
                    ternak[index].pemberianvitamin = edit;
                }
                cout << "Data Telah Diubah\n";
            }
            else
                cout << "DATA TIDAK TERSEDIA\n";
        }
        else if(input == 4)
        {
            // hapus berdasar kode kandang
            string hapus;
            cout << "masukkan kode kandang data yang akan dihapus : ";
            cin >> hapus;
            sort(ternak.begin(), ternak.end(), cmp_first_elemen);
            int index = upperBound(hapus, ternak, 0, ternak.size());
            if(ternak[index].kodekandang == hapus)
            {
                ternak.erase(ternak.begin()+index);
                cout << "Data Terhapus\n";
            }
            else
                cout << "DATA TIDAK TERSEDIA\n";
        }
        else if(input == 5)
        {
            // tampilkan data secara terurut
            sort(ternak.begin(), ternak.end(), cmp);
            for(auto it:ternak)
            {
                cout << "\nkode kandang : " << it.kodekandang;
                cout << "\njenis ayam : " << it.jenisayam;
                cout << "\nbanyak telur : " << it.banyaktelur;
                cout << "\numur ayam : " << it.umurayam;
                cout << "\njumlah pakan : " << it.jumlahpakan;
                cout << "\npemberian vitamin : " << it.pemberianvitamin;
                cout << endl << endl << endl;
            }
        }
        else if(input == 6)
        {
            // cari berdasar kode kandang
            string cari;
            cout << "masukkan kode kandang yang akan dicari : ";
            cin >> cari;
            sort(ternak.begin(), ternak.end(), cmp_first_elemen);
            int index=upperBound(cari, ternak, 0, ternak.size());
            if(ternak[index].kodekandang == cari)
            {
                cout << "DATA TERSEDIA\n";
            }
            else
                cout << "DATA TIDAK TERSEDIA\n";
        }
        
        else if(input == 7)
        {
            // simpan data ke file .txt
            simpan(writedata, ternak);
        }
        else if(input == 8)
        {
            // keluar dari program
            exit(0);
        }
        else
            cout << "Anda memasukkan data yang salah";
    }
    return 0;
}
