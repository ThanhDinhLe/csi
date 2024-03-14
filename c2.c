#include <stdio.h>


struct SinhVien {
    char maSV[20];
    char hoTen[50];
    float diemGPA;
};

int main() {
    FILE *file;
    char filename[] = "Sinhvien.txt";
    struct SinhVien sv;
    int n;

   
    printf("Nhập số lượng sinh viên: ");
    scanf("%d", &n);

    
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Không thể mở tệp %s\n", filename);
        return 1;
    }

   
    for (int i = 0; i < n; i++) {
        printf("Nhập thông tin cho sinh viên thứ %d:\n", i + 1);
        printf("Mã sinh viên: ");
        scanf("%s", sv.maSV);
        printf("Họ tên: ");
        scanf("%s", sv.hoTen); // Đọc họ tên chỉ khi không có khoảng trắng
        printf("Điểm GPA: ");
        scanf("%f", &sv.diemGPA);

       
        fprintf(file, "%s %s %.1f\n", sv.maSV, sv.hoTen, sv.diemGPA);
    }

   
    fclose(file);

    printf("Đã ghi danh sách sinh viên vào tệp %s.\n", filename);

    return 0;
}
