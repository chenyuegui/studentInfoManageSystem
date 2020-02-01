#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu {
    char name[16];
    int age;
    long id;
    struct stu *next;
};

void insert(struct stu *head, struct stu *ne) {
    ne->next = head->next;
    head->next = ne;
}

void writeFile(struct stu *head) {
    struct stu *p = head->next;
    FILE *fp;
    fp = fopen("C:\\Users\\ChenYulin\\Desktop\\test.txt", "w");
    while (p != NULL) {
        fprintf(fp, "%s %d %ld\n", p->name, p->age, p->id);
        p = p->next;
    }
    fclose(fp);

}

void readFile(struct stu *head) {
    FILE *fp;
    fp = fopen("C:\\Users\\ChenYulin\\Desktop\\test.txt", "r");
    int test = fgetc(fp);
    if (test == EOF) {
        fclose(fp);
        return;
    }
    fclose(fp);
    fp = fopen("C:\\Users\\ChenYulin\\Desktop\\test.txt", "r");
    while (!feof(fp)) {
        struct stu *read = (struct stu *) malloc(sizeof(struct stu));
        insert(head, read);
        fscanf(fp, "%s %d %ld\n", read->name, &read->age, &read->id);
    }
    fclose(fp);
}
void printStuInfo(struct stu *head) {
    struct stu *p = head->next;
    while (p != NULL) {
        printf("%s %d %ld\n", p->name, p->age, p->id);
        p = p->next;
    }
}
void freeAll(struct stu *head) {
    struct stu *pre, *p;
    pre = head;
    p = head->next;
    while (pre != NULL) {
        free(pre);
        pre = p;
        if (p == NULL)
            break;
        p = p->next;


    }
}
void delete(struct stu *head, int deleteId) {
    struct stu *pre, *q;
    pre = head;
    q = pre->next;
    while (q != NULL) {
        if (q->id != deleteId) {
            pre = pre->next;
            q = q->next;
        } else {
            pre->next = q->next;
            free(q);
            break;
        }
    }


}
void fix(struct stu *head, int a) {
    struct stu *f;
    int z, i;
    f = head;
    f = f->next;
    while (f != NULL) {
        if (f->id == a) {
            while (z) {
                printf("����Ҫ�޸��������ݣ�\n");
                printf("1 �޸�ѧ��������\n");
                printf("2 �޸�ѧ�����䣻 \n");
                printf("3 �޸�ѧ�� ID��\n");
                printf("0 �˳���\n");
                scanf("%d", &i);
                switch (i) {
                    case 1:
                        printf("�������޸ĺ��ѧ��������");
                        scanf("%s", f->name);
                        break;
                    case 2:
                        printf("�������޸ĺ��ѧ�����䣺");
                        scanf("%d", &f->age);
                        break;
                    case 3:
                        printf("�������޸ĺ��ѧ��id��");
                        scanf("%ld", &f->id);
                        break;
                    case 0:
                        z = 0;
                        break;
                }
            }
        }
        f = f->next;
    }


}
struct stu *findById(struct stu *head, int findId) {
    struct stu *p;
    p = head->next;
    while (p != NULL) {
        if (p->id == findId) {
            return p;
        }
        p = p->next;

    }
    return NULL;
}
void sort(struct stu *head){
    struct stu* p;
    struct stu* first;
    struct stu* second;
    struct stu itemp ;
    p=head->next;


    while(p!=NULL){
        first=head->next;

        while(first->next !=NULL){
            second=first->next;
            if(first->id>second->id){
                strcpy(itemp.name,first->name);
                itemp.age=first->age;
                itemp.id=first->id;
                strcpy(first->name,second->name);
                first->age=second->age;
                first->id=second->id;
                strcpy(second->name,itemp.name);
                second->age=itemp.age;
                second->id=itemp.id;
            }
            first=second;
        }


        p=p->next;
    }
}


void main() {
    struct stu *head = (struct stu *) malloc(sizeof(struct stu));
    head->next = NULL;
    readFile(head);
    while (1) {
        int functionNum;
        printf("       *******��ӭʹ��ѧ����Ϣ����ϵͳ********\n");
        printf("           ******��ѡ������Ҫ�Ĺ���*******\n");
        printf("1 ����ѧ����Ϣ��\n2 ɾ��ѧ����Ϣ��\n3 ����ѧ����Ϣ��\n4 ����ѧ����Ϣ��\n5 ���ѧ����Ϣ\n6 ��id��������\n0 �˳�\n");
        scanf("%d", &functionNum);
        int a;
        char op;
        int deleteId;
        struct stu *ne;
        switch (functionNum) {
            case 1:
                while (1) {
                    ne = (struct stu *) malloc(sizeof(struct stu));
                    printf("��������Ҫ�����ѧ����Ϣ\n");
                    printf("������ѧ��������");
                    scanf("%s", ne->name);
                    printf("������ѧ�����䣺");
                    scanf("%d", &ne->age);
                    printf("������ѧ��ID:");
                    scanf("%ld", &ne->id);
                    insert(head, ne);
                    printf("�Ƿ�������룿\n");
                    setbuf(stdin, NULL);
                    op = getchar();
                    printf("%c\n", op);
                    if (op == 'y') {
                        continue;
                    }
                    break;
                }
                break;
            case 2:
                printf("��������Ҫɾ����ѧ����ID:");
                scanf("%ld", &deleteId);
                delete(head, deleteId);
                printStuInfo(head);
                break;
            case 3:
                printf("��������Ҫ�޸ĵ�ѧ����ID��");
                scanf("%ld", &a);
                fix(head, a);
                printStuInfo(head);
                break;
            case 4:
                printf("����������Ҫ���ҵ�ѧ��ID");
                int findId;
                scanf("%ld", &findId);
                struct stu *p = findById(head, findId);
                printf("%s %d %ld", p->name, p->age, p->id);
                break;
            case 5:
                printStuInfo(head);
                break;
            case 6:
                sort(head);
                break;
            case 0:
                writeFile(head);
                freeAll(head);
                exit(1);
            default:
                break;
        }
    }
}


