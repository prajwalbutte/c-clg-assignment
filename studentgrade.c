truct Student {
    int roll;
    char name[20];
    float marks[3], total, per;
    char grade;
};

void main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for(int i=0; i<n; i++) {
        printf("\nEnter Roll No and Name: ");
        scanf("%d %s", &s[i].roll, s[i].name);
        printf("Enter marks in 3 subjects: ");
        s[i].total = 0;
        for(int j=0; j<3; j++) {
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }
        s[i].per = s[i].total / 3;
        if(s[i].per >= 90) s[i].grade = 'A';
        else if(s[i].per >= 75) s[i].grade = 'B';
        else if(s[i].per >= 50) s[i].grade = 'C';
        else s[i].grade = 'F';
    }

    printf("\nRoll\tName\tTotal\tPer\tGrade\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%s\t%.2f\t%.2f\t%c\n",
               s[i].roll, s[i].name, s[i].total, s[i].per, s[i].grade);
    }
}
