#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>

struct student{
    char stud_Admno[15];
    char stud_name[20];
    char stud_address[20];
    char stud_parentName[20];
    char stud_class[20];
    int stud_contact_number;

};
struct student stu;
void addstudent(){
    system("cls");
printf("Add New Student\n");
FILE *openfile;
openfile = fopen("records.txt", "ab+");
if(openfile==NULL){
    printf("record file does not exist\n");
}
else{
   fflush(stdin);
    printf("Admission-NO: ");gets( stu.stud_Admno);
    printf("Name: ");gets(stu.stud_name);
    printf("Address: ");gets(stu.stud_address);
    printf("Parent Name: ");gets(stu.stud_parentName);
    printf("Class: ");gets(stu.stud_class);
    printf("Contact No: ");scanf("%d", &stu.stud_contact_number);
    fwrite(&stu,sizeof(stu),1, openfile);
    printf("New Student Is Added Successfully\n");
}
fclose(openfile);
return;
 }
void searchstudent(){
    system("cls");
char student_admno[15];
int found=0;
printf("Enter The Admission no: \n");fflush(stdin);
gets(student_admno);
FILE *openfile;
openfile = fopen("records.txt", "rb");
 while(fread(&stu,sizeof(stu),1,openfile) == 1){
        if(strcmp(student_admno,stu.stud_Admno) == 0){
            found = 1;
            break;
        }
    }
    if(found==1){
        printf("The Record is found:");
        printf("Admission no: %s\n", stu.stud_Admno);
        printf("Name: %s\n",stu.stud_name);
        printf("Address: %s\n", stu.stud_address);
        printf("Parent Name: %s\n", stu.stud_name);
        printf("Class: %s\n", stu.stud_class);
        printf("Contact no: %d\n", stu.stud_contact_number);
    }
    else{
        printf("No Record Found In The Database\n");
        }
        fclose(openfile);
        return;
        }
void modifystudent(){
    system("cls");
    printf("Modify The Record:");
    char student_admno[15];
    int found=0;
    printf("Enter the Admission No To Modify:");fflush(stdin);
    gets(student_admno);
    FILE *openfile;
    openfile = fopen("records.txt", "rb+");
    while(fread(&stu, sizeof(stu),1,openfile) == 1){
        if(strcmp(student_admno, stu.stud_Admno) == 0){
            printf("Admission-NO:\n");gets(stu.stud_Admno);
    printf("Name:\n");gets(stu.stud_name);
    printf("Address:\n");gets(stu.stud_address);
    printf("Parent Name:\n");gets(stu.stud_parentName);
    printf("Class:\n");gets(stu.stud_class);
    printf("Contant No:\n");scanf("%d", &stu.stud_contact_number);
    fseek(openfile,-sizeof(stu), SEEK_CUR);
    fwrite(&stu,sizeof(stu), 1, openfile);
    printf("Updated Successfully!!\n");
    found=1;
    break;
    }
    }
    if(!found){
        printf("No Record Found\n");
    }
    fclose(openfile);
    return;
     }
    void delete_student(){
        system("cls");
        printf("Delete Record\n");
        char student_admno[15];
        int found=0;
        printf("Enter The Admission No\n");fflush(stdin);
        gets(student_admno);
        FILE *openfile, *temporary;
    openfile = fopen("record.txt","rb");
    temporary = fopen("temp.txt", "wb");
    while(fread(&stu, sizeof(stu),1,openfile) == 1){
        if(strcmp(student_admno, stu.stud_Admno) == 0){
            fwrite(&stu,sizeof(stu),1,temporary);
        }
    }
    fclose(openfile);
    fclose(temporary);
    remove("record.txt");
    rename("temp.txt","records.txt");
    printf("Record Is Sucessfully Deleted\n");
    return;
}
void main_window(){
    system("cls");
int options;
int i=2;
while(1){
        printf("*****Student Record Database *****\n");
    printf("Choose The Option\n");
    printf("1. Add Student\n");
    printf("2. Search Student\n");
    printf("3. Modify Student Record\n");
    printf("4. Delete Student Record\n");
    printf("5. Exit\n");
    printf("Enter The Choice:\n");
    scanf("%d", &options);
    switch(options){
 case 1:

    addstudent();
       break;
 case 2:
      searchstudent();
    break;
 case 3:
    modifystudent();
    break;
 case 4:
    delete_student();
    break;
 case 5:
    exit(0);
    break;
 default:
    printf("Wrong Choice\n");
    break;
    }
}

}
void welcomemessage(){
 MessageBox(0,"Welcome To The Student Database" ,"INFO" ,1);
 return;
}
int main()
{
    welcomemessage();
    main_window();
    return 0;
}
