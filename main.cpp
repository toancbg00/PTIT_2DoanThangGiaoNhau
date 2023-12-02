#include <bits/stdc++.h>
using namespace std;
// clockwise = 1; counterclockwise = 0
bool kiemTraChieuCuaBaDiem (long x1, long x2, long x3, long y1, long y2, long y3){
int check;
check = (y2-y1)*(x3-x2)-(y3-y2)*(x2-x1);
if (check > 0) return true;
else return false;
}
bool kiemTraBaDiemThangHang (long x1, long x2, long x3, long y1, long y2, long y3){
double doc1, doc2;
if (x1==x2 && x1 == x3 || y1 == y2 && y2 == y3){
    return true;
}
 if (x1 == x2) {
            return x3 == x1;
        } else if (x1 == x3) {
            return x2 == x1;
        } else {
            doc1 = (y1 - y2) * 1.0 / (x1 - x2);
            doc2 = (y1 - y3) * 1.0 / (x1 - x3);
            return fabs(doc1 - doc2) < 1e-9;

        }
}
bool kiemTraDiemNamGiua(long x1, long x2, long x3, long y1, long y2, long y3){
long distanceAC, distanceAB;
distanceAC = sqrt((x1-x3)*(x1-x3)-(y1-y3)*(y1-y3));
distanceAB = sqrt((x1-x2)*(x1-x2)-(y1-y2)*(y1-y2));
if (distanceAC <= distanceAB) return true;
else return false;
}
int main(){
long int x1, x2, x3, x4, y1, y2, y3, y4;
// Khai bao toa do 4 diem A, B, C, D
cin >> x1 >> y1;
cin >> x2 >> y2;
cin >> x3 >> y3;
cin >> x4 >> y4;
// Neu A B C thang hang, khi C nam giua A va B thi CD giao AB
if (kiemTraBaDiemThangHang(x1, x2, x3, y1, y2, y3)){
    if (kiemTraDiemNamGiua(x1, x2, x3, y1, y2, y3)) cout << "YES!";
    else cout << "NO";
}
else if (kiemTraBaDiemThangHang(x1, x2, x4, y1, y2, y4)){
     if (kiemTraDiemNamGiua(x1, x2, x4, y1, y2, y4)) cout << "YES!";
    else cout << "NO";
}
// truong hop khong co 3 diem thang hang, neu bo 3 diem quay cung chieu thi cat nhau
else if (kiemTraBaDiemThangHang(x1, x2, x3, y1, y2, y3 )==0 && (kiemTraBaDiemThangHang(x1, x2, x4, y1, y2, y4)==0)){
    if (kiemTraChieuCuaBaDiem(x1, x2, x3, y1, y2, y3)!= kiemTraChieuCuaBaDiem(x1, x2, x4, y1, y2, y4)) cout << "YES!";
    else cout << "NO";
}
return 0;
}
