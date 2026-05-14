#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int choose0=1;
int choose1=0;
int choosetc;
int chooseup=1;
int chooseup1;
int w=1;
int gold=0;
vector<string>tenquai={
    "Slime",
    "Zombie",
    "Goblin",
    "Skeleton",
    "Virus",
    "Witch",
    "Alien",
    "Ghost",
    "Banana",
    "Monkey"
};
vector<string>tenboss={
    "TOXIC DRAGON",
    "DARK KNIGHT",
    "1ST DEMON",
    "ANCIENT GOLEM",
    "WORLD'S END ROBOT",
    "HELL HEADER",
    "GOLDEN GOLDEN DUCK",
    "HUGE DURIAN",
    "DOCTOR CAPYBARA",
    "6 PACKS GYMER",
    "SIX SEVEN MUHAHA"
};
struct nhanvat{
    string ten;
    int maxhp;
    int hp;
    int atk;
    int level;

    int heal;
    int skill;
    int crit;

    int upatk;
    int uphp;
    int upheal;
    int upcrit;

    nhanvat(){
        maxhp=100;
        hp=maxhp;
        atk=10;

        heal=maxhp*30/100;
        skill=maxhp*50/100+20;
        crit=5;

        upatk=0;
        uphp=0;
        upheal=0;
        upcrit=0;
    }
};
struct quaivat{
    int basehp;
    int hp;
    int baseatk;
    int atk;

    quaivat(){
        basehp=50;
        hp=50;
        baseatk=5;
        atk=5;
    }
};
struct boss{
    int basehp;
    int hp;
    int baseatk;
    int atk;

    boss(){
        basehp=100;
        hp=100;
        baseatk=10;
        atk=10;
    }
};
void savegame(nhanvat &nv,int &gold, int &w){
    ofstream save("savegame.txt");
    save<<nv.ten<<endl;
    save<<nv.upatk<<endl;
    save<<nv.upcrit<<endl;
    save<<nv.upheal<<endl;
    save<<nv.uphp<<endl;
    save<<nv.maxhp<<endl;
    save<<nv.atk<<endl;
    save<<nv.crit<<endl;
    save<<gold<<endl;
    save<<w<<endl;
    save<<nv.heal<<endl;
    save<<nv.skill<<endl;

    save.close();

}
void loadgame(nhanvat &nv,int &gold,int &w){
    ifstream save("savegame.txt");
    if(!save){
        return;
    }
    getline(save,nv.ten);
    save>>nv.upatk;
    save>>nv.upcrit;
    save>>nv.upheal;
    save>>nv.uphp;
    save>>nv.maxhp;
    save>>nv.atk;
    save>>nv.crit;
    save>>gold;
    save>>w;
    save>>nv.heal;
    save>>nv.skill;

    nv.hp = nv.maxhp;
    save.close();
}
string rdquai(){
    int x=rand()%tenquai.size();
    return tenquai[x];
}
string rdboss(){
    int y=rand()%tenboss.size();
    return tenboss[y];
}
void ktrhp(nhanvat &nv){
    if (nv.hp>=nv.maxhp){
        nv.hp=nv.maxhp;
    }
}
void nhapten(nhanvat &nv){
    cout<<"Nhap ten cua ban: "<<endl;
    getline(cin,nv.ten);
}
void xem(nhanvat &nv){
    cout<<endl<<"Nhan Vat: "<<nv.ten
        <<endl<<"HP: "<<nv.hp
        <<endl<<"ATK: "<<nv.atk
        <<endl<<"CRIT: "<<nv.crit
        <<endl<<"GOLD: "<<gold<<endl;
}
bool trutien(int &gold, int gia){
    if (gold>=gia){
        gold=gold-gia;
        return true;
    }else {
        return false;
    }
}
void up(int &gold,nhanvat &nv){
    while(true){
        int giahp=1,giaatk=1,giaheal=1,giacrit=1;
        cout<<endl<<"Ban dang co: "<<gold<<" xu vang"<<endl;
        cout<<"Chon Muc Nang Cap: "<<endl
            <<"1. MaxHP gia: "<<giahp+nv.uphp*2<<endl
            <<"2. ATK gia: "<<giaatk+nv.upatk*2<<endl
            <<"3. Heal gia: "<<giaheal+nv.upheal*2<<endl
            <<"4. CRIT gia: "<<giacrit+nv.upcrit*5<<endl
            <<"0. Thoat"<<endl;
        cin>>chooseup1;
        cin.ignore();
        switch (chooseup1){
        case 1:{
            int gia=giahp+nv.uphp*2;
            if(trutien(gold,gia)){
                int hp=nv.maxhp;
                nv.maxhp=nv.maxhp+(nv.uphp+2)*20;
                cout<<"Ban Da Nang Cap MaxHP"<<endl
                    <<"HP: "<<hp<<"-->"<<nv.maxhp<<endl;
                    nv.uphp++;
            }else {
                cout<<"Ban Khong Du Xu!"<<endl;
            }
            break;
        }case 2:{
            int gia=giaatk+nv.upatk*2;
            if(trutien(gold,gia)){
                int atk=nv.atk;
                nv.atk=nv.atk+(nv.upatk+1)*10;
                cout<<"Ban Da Nang Cap ATK"<<endl
                    <<"ATK: "<<atk<<"-->"<<nv.atk<<endl;
                    nv.upatk++;
            }
            break;
        }case 3:{
            int gia=giaheal+nv.upheal*2;
            if(trutien(gold,gia)){
                int heal=nv.heal;
                nv.heal=nv.heal+(nv.upheal+2)*10;
                cout<<"Ban Da Nang Cap Heal"<<endl
                    <<"Heal: "<<heal<<"-->"<<nv.heal<<endl;
                    nv.upheal++;
            }
            break;
        }case 4:{
            int gia=giacrit+nv.upcrit*5;
            if(trutien(gold,gia)){
                int crit=nv.crit;
                nv.crit=nv.crit+2;
                cout<<"Ban Da Nang Cap CRIT"<<endl
                    <<"CRIT: "<<crit<<"-->"<<nv.crit<<endl;
                    nv.upcrit++;
            }
            break;
        }
        case 0:{
            return;
        }
        default:
            break;
        }
    }
}
bool cri(nhanvat &nv){
    int c=rand()%100+1;
    for (int i=1;i<=nv.crit;i++){
        if (i==c){
            return true;
        }
    }
    return false;
}
int tancong(nhanvat &nv, int &enemyhp, int &enemyatk, bool isboss){
    nv.hp=nv.maxhp;
    int cooldownnv=0;
    int cooldownboss=0;
    string quai=rdquai();
    string boss=rdboss();
    while (enemyhp>0&&nv.hp>0){
        if(cooldownnv<0){
            cooldownnv=0;
        }
        if (isboss){
            cout<<nv.ten<<":       "<<boss<<": "<<endl
                <<"HP: "<<nv.hp<<"     "<<"HP: "<<enemyhp<<endl
                <<"ATK: "<<nv.atk<<"     "<<"ATK: "<<enemyatk<<endl
                <<"CRIT: "<<nv.crit<<endl;
        }else{
            cout<<nv.ten<<":       "<<quai<<": "<<endl
                <<"HP: "<<nv.hp<<"     "<<"HP: "<<enemyhp<<endl
                <<"ATK: "<<nv.atk<<"     "<<"ATK: "<<enemyatk<<endl
                <<"CRIT: "<<nv.crit<<endl;
        }cout<<endl<<"Lua Chon Cua Ban:"<<endl
            <<"1. Tan Cong"<<endl
            <<"2. Hoi Mau"<<endl
            <<"3. SKILL"<<"("<<cooldownnv<<")"<<endl;
            cin>>choosetc;
        switch (choosetc){
        case 1:{
            int nvhp=nv.hp;
            int qvhp=enemyhp;
            if (isboss){
                if (cooldownboss<=0){
                    nv.hp=nv.hp-(enemyatk+w*3);
                    cout<<boss<<" Dung DON DANH CUONG HOA Gay "<<enemyatk+w*3<<" DAMAGE Len Ban"<<endl
                        <<nv.ten<<" HP: "<<nvhp<<"-->"<<nv.hp<<endl;
                    if (cri(nv)){
                        enemyhp=enemyhp-(nv.atk*2);
                        cout<<"BAN DA GAY "<<nv.atk*2<<"CRIT DAMAGE LEN "<<boss<<endl
                            <<boss<<" HP: "<<qvhp<<"-->"<<enemyhp<<endl<<endl;
                    }else{
                        enemyhp=enemyhp-nv.atk;
                        cout<<"Ban Da Gay "<<nv.atk<<" DAMAGE Len "<<boss<<endl
                            <<boss<<" HP: "<<qvhp<<"-->"<<enemyhp<<endl<<endl;
                            cooldownboss=4;
                            cooldownnv--;
                    }
                }else{
                    nv.hp=nv.hp-enemyatk;
                    cout<<boss<<" Da Gay "<<enemyatk<<" DAMAGE Len Ban"<<endl
                        <<nv.ten<<" HP: "<<nvhp<<"-->"<<nv.hp<<endl;
                    if (cri(nv)){
                        enemyhp=enemyhp-(nv.atk*2);
                        cout<<"BAN DA GAY "<<nv.atk*2<<"CRIT DAMAGE LEN "<<boss<<endl
                            <<boss<<" HP: "<<qvhp<<"-->"<<enemyhp<<endl<<endl;
                            cooldownboss--;
                            cooldownnv--;
                    }else{
                        enemyhp=enemyhp-nv.atk;
                        cout<<"Ban Da Gay "<<nv.atk<<" DAMAGE Len "<<boss<<endl
                            <<boss<<" HP: "<<qvhp<<"-->"<<enemyhp<<endl<<endl;
                            cooldownboss--;
                            cooldownnv--;
                    }
                }
            }else{
                nv.hp=nv.hp-enemyatk;
                cout<<quai<<" Da Gay "<<enemyatk<<" DAMAGE Len Ban"<<endl
                    <<nv.ten<<" HP: "<<nvhp<<"-->"<<nv.hp<<endl;
                if (cri(nv)){
                    enemyhp=enemyhp-(nv.atk*2);
                    cout<<"BAN DA GAY "<<nv.atk*2<<"CRIT DAMAGE LEN "<<quai<<endl
                        <<quai<<" HP: "<<qvhp<<"-->"<<enemyhp<<endl<<endl;
                }else{
                    enemyhp=enemyhp-nv.atk;
                    cout<<"Ban Da Gay "<<nv.atk<<" DAMAGE Len "<<quai<<endl
                        <<quai<<" HP: "<<qvhp<<"-->"<<enemyhp<<endl<<endl;
                        cooldownnv--;
                }
            }
                break;
        }
        case 2:{
        int hpnv=nv.hp;
            nv.hp=nv.hp+nv.heal;
            ktrhp(nv);
            cout<<"Ban Da Hoi "<<nv.heal<<" Mau"<<endl
                <<nv.ten<<" HP: "<<hpnv<<"-->"<<nv.hp<<endl;
            hpnv=nv.hp;
            if(isboss){
                nv.hp=nv.hp-(enemyatk/2);
                cout<<boss<<" Da Gay "<<enemyatk/2<<" DAMAGE Len Ban"<<endl
                    <<nv.ten<<" HP: "<<hpnv<<"-->"<<nv.hp<<endl<<endl;
                cooldownnv--;
                cooldownboss--;
            }else{
            nv.hp=nv.hp-(enemyatk/2);
            cout<<quai<<" Da Danh Ban "<<enemyatk/2<<"DAMAGE"<<endl
                <<nv.ten<<" HP: "<<hpnv<<"-->"<<nv.hp<<endl<<endl;
                cooldownnv--;
            }
                break;
        }
        case 3:{
        int hpnv=nv.hp;
            if(cooldownnv==0){
                nv.hp=nv.hp+nv.skill;
                ktrhp(nv);
                cout<<"*@%^#(^!&^#(&!_---ULTRA HEALING---_*@*)#@&*^("<<endl
                    <<nv.ten<<" HP: "<<hpnv<<"-->"<<nv.hp<<endl<<endl;
                cooldownnv=2;
                break;
            }else{
                cout<<"Dang Hoi Chieu"<<endl<<endl;
                continue;
            }
        }
        break;
        default:
            cout<<"chon sai, vui long chon lai!"<<endl;
        }
    }
    if(nv.hp<=0){
        nv.hp=0;
        cout<<"ban da thua";
    }if (enemyhp<=0){
        enemyhp=0;
        int reward=w-1;
        if(isboss){
            gold=gold+(reward*2);
        cout<<"Ban da Thang"<<endl
            <<"Ban Nhan Duoc "<<reward*2<<" Xu"<<endl<<endl;
        }else{
        gold=gold+reward;
        cout<<"Ban da Thang"<<endl
            <<"Ban Nhan Duoc "<<reward<<" Xu"<<endl<<endl;
        }
    }
    return 0;
}
int wave(int &w){
    cout<<endl<<"====WAVE "<<w<<"===="<<endl;
    w++;
    return w;
}
int combatquai(nhanvat &nv, quaivat &qv){
    wave(w);
    qv.hp=qv.basehp*(w-1)-((w-1)*10);
    qv.atk=qv.baseatk*(w-1);
    tancong(nv,qv.hp,qv.atk,false);
    return 0;
}
int combatboss(nhanvat &nv, boss &bos){
    wave(w);
    cout<<"====BOSS WAVE===="<<endl;
    bos.hp=bos.basehp*(w-1)+50;
    bos.atk=bos.baseatk+((w-1)*5);
    tancong(nv,bos.hp,bos.atk,true);
    return 0;
}
void doiten(nhanvat &nv){
    string ten;
    cout<<"Nhap Ten Moi Cua Ban: ";
    getline(cin,ten);
    cout<<endl;
    nv.ten=ten;
    cout<<"Da Doi Ten Cua Ban Thanh: "<<nv.ten<<endl;
}
int main(){
    srand(time(0));
    nhanvat nv;
    quaivat qv;
    boss bos;
    loadgame(nv, gold, w);
    if(nv.ten==""){
        nhapten(nv);
    }while (choose0==1){
        cout<<endl<<"Trang Chu:"<<endl
            <<"1. Xem Nhan Vat"<<endl
            <<"2. Di San Quai"<<endl
            <<"3. Nang Cap va Mua Hang"<<endl
            <<"4. Doi Ten"<<endl
            <<"0. Thoat"<<endl;
        cin>>choose1;
        cin.ignore();
        switch (choose1){
        case 1:
            xem(nv);
            break;
        case 2:
            if(w%10==0){
                combatboss(nv,bos);
            }else{
                combatquai(nv, qv);
            }break;
        case 3:
            up(gold,nv);
            break;
        case 4:
            doiten(nv);
            break;
        case 0:
            savegame(nv,gold,w);
            cout<<"Da Luu!";
            choose0=0;
            break;
        default:
            break;
        }
    }
    return 0;
}