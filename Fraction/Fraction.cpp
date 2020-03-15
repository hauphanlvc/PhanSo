
#include <iostream>
#include <algorithm>
using namespace std;
struct PhanSo
{
    int iTuSo, iMauSo;
};
void NhapPhanSo(PhanSo& a)
{
    cout << "Nhap tu so cua phan so :\n";
    cin >> a.iTuSo;
    do
    {
        cout << "Nhap mau so cua phan so :\n";
        cin >> a.iMauSo;
        if (a.iMauSo == 0) cout << "Ban vui long nhap lai voi dieu kien mau so khac 0\n";

    } while (a.iMauSo == 0);

}
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);

}
void RutGon(PhanSo& a)
{
    int UocChungLonNhatCuaTuSoVaMauSo = gcd(abs(a.iTuSo), abs(a.iMauSo));
    a.iTuSo /= UocChungLonNhatCuaTuSoVaMauSo;
    a.iMauSo /= UocChungLonNhatCuaTuSoVaMauSo;
}
PhanSo CongPhanSo(PhanSo& a, PhanSo& b)
{
    PhanSo c;
    c.iTuSo = a.iTuSo * b.iMauSo + b.iTuSo * a.iMauSo;
    c.iMauSo = a.iMauSo * b.iMauSo;
    RutGon(c);
    return c;


}
PhanSo TruPhanSo(PhanSo& a, PhanSo& b)
{
    PhanSo c;
    c.iTuSo = a.iTuSo * b.iMauSo - b.iTuSo * a.iMauSo;
    c.iMauSo = a.iMauSo * b.iMauSo;
    RutGon(c);
    return c;


}
PhanSo NhanPhanSo(PhanSo& a, PhanSo& b)
{
    PhanSo c;
    c.iTuSo = a.iTuSo * b.iTuSo;
    c.iMauSo = a.iMauSo * b.iMauSo;
    RutGon(c);
    return c;
}
PhanSo ChiaPhanSo(PhanSo& a, PhanSo& b)
{
    PhanSo c;
    c.iTuSo = a.iTuSo * b.iMauSo;
    c.iMauSo = a.iMauSo * b.iTuSo;
    RutGon(c);
    return c;

}
int main()
{
    PhanSo a, b;
    NhapPhanSo(a);
    NhapPhanSo(b);
    cout << "Ket qua sau khi cong 2 phan so a va b : \n";
    PhanSo KetQuaSauKhiCong = CongPhanSo(a, b);
    cout << KetQuaSauKhiCong.iTuSo << " " << KetQuaSauKhiCong.iMauSo << endl;
    cout << "Ket qua sau khi tru 2 phan so a va b : \n";
    PhanSo KetQuaSauKhiTru = TruPhanSo(a, b);
    cout << KetQuaSauKhiTru.iTuSo << " " << KetQuaSauKhiTru.iMauSo << endl;
    cout << "Ket qua sau khi nhan 2 phan so a va b : \n";
    PhanSo KetQuaSauKhiNhan = NhanPhanSo(a, b);
    cout << KetQuaSauKhiNhan.iTuSo << " " << KetQuaSauKhiNhan.iMauSo << endl;
    cout << "Ket qua sau khi chia 2 phan so a va b : \n";
    if (b.iTuSo == 0)
    {
        cout << "Phan so a khong the chia cho phan so b ";
        
    }
    else
    {
        PhanSo KetQuaSauKhiChia = ChiaPhanSo(a, b);
        cout << KetQuaSauKhiChia.iTuSo << " " << KetQuaSauKhiChia.iMauSo << endl;
    }

}

