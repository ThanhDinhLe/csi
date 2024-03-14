#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct SinhVien {
    char maSV[20];
    char hoTen[50];
    float diemGPA;
};


int compare(const void *a, const void *b) {
    const struct SinhVien *sv1 = (const struct SinhVien *)a;
    const struct SinhVien *sv2 = (const struct SinhVien *)b;
    return (sv1->diemGPA > sv2->diemGPA) - (sv1->diemGPA < sv2->diemGPA);
}

int main() {
    FILE *file;
    char filename[] = "Sinhvien.txt";
    struct SinhVien sv[100]; 
    int count = 0;

   
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Không thể mở tệp %s\n", filename);
        return 1;
    }

    
    while (fscanf(file, "%s %s %f", sv[count].maSV, sv[count].hoTen, &sv[count].diemGPA) != EOF) {
        count++;
    }

   
    fclose(file);

    
    qsort(sv, count, sizeof(struct SinhVien), compare);

   
    printf("Danh sách sinh viên sau khi sắp xếp theo điểm GPA:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s %.1f\n", sv[i].maSV, sv[i].hoTen, sv[i].diemGPA);
    }

    return 0;
}
