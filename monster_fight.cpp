#include <iostream>
#include <vector>
#include <string>
using namespace std;
int choose0=1;
int choose1=0;
struct nhanvat{
    string ten;
    int hp=100;
    int atk=10;
    int level=1;
};
struct quaivat{
    int hp=50;
    int atk=5;
};
struct boss{
    int hp=100;
    int atk=10;
};
void nhapten(nhanvat &nv){
    cout<<"Nhap ten cua ban: "<<endl;
    getline(cin,nv.ten);
}
void xem(nhanvat &nv){
    cout<<endl<<"Nhan Vat: "<<nv.ten
        <<endl<<"HP: "<<nv.hp
        <<endl<<"ATK: "<<nv.atk
        <<endl<<"LEVEL: "<<nv.level<<endl;
}
void up(){

}
int tancong(){

    return 0;
}
int hoimau(){

    return 0;
}
int wave(){

    return 0;
}
int ask(){

    return 0;
}
int main(){
    nhanvat nv;
    quaivat qv;
    boss bos;
    nhapten(nv);
    while (choose0>=1){
        cout<<endl<<"Trang Chu:"<<endl
            <<"1. Xem Nhan Vat"<<endl
            <<"2. Di San Quai"<<endl
            <<"3. Nang Cap va Mua Hang"<<endl
            <<"4. Thoat"<<endl;
        cin>>choose1;
        cin.ignore();
        switch (choose1){
        case 1:
            xem(nv);
            break;
        case 2:

            break;
        default:
            break;
        }
    }
    return 0;
}