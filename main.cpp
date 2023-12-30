  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #define max 5

  int main(void);

  int vitri =0;
  struct Stack {
      int data[max];
      int top;
  };
  typedef struct Stack ST;
  void pop1(ST *st);
  void pop2(ST *st);
  void khoitao(ST *st)
  {
      st->top = -1;
  }
  int checkrong(ST *st)
  {
      if(st->top == -1)
      {
          return 1;
      }
      return 0;
  }
  int checkfull(ST * st)
  {
      if(st->top == max)
      {
          return 1;
      }
      return 0;
  }
  void  push(ST *st , int nhap)
  {
   if(checkfull(st))
   {
      printf("stack da day\n");
      main();
   }
   else 
   {
      st->top++;
      st->data[st->top] = nhap;
      vitri++;
   }

  }

  void pop1(ST *st)
  {
   if(checkrong(st))
   {
      printf("stack rong mod 1\n");
      main();
   }
   else
   {
      printf("da xoa nhung khong xoa vi tri\n\n");
      st->data[st->top] = NULL;
      st->top--;
   }
  }
  void pop2(ST *st)
  {
   if(checkrong(st))
   {
      printf("stack rong mod 2\n");
      main();
   }
   else
   {
      printf("da xoa va xoa vi tri\n\n");
      st->top--;
   }
   vitri--;
  }
  void xuat(ST *st)
  {
      printf("In Stack :\n");
      for(int i = 0;i < vitri;i++)
      {
          printf("- %d \n",st->data[i]);
      }
  }
void edit(ST *st)
{
    int nhap,y;
    printf("nhap vi tri can sua : ");
    scanf(" %d",&nhap);
    if(nhap > vitri)
    {
        printf("khong ton tai \n");
      return;
    }
  else
    {
        printf("nhap gia tri can sua : ");
        scanf(" %d",&y);
        st->data[nhap-1] = y;
    }
  
          
}
void sapxep(ST *st)
{
    int i,j,temp;
    for(i = 0;i < vitri;i++)
      {
          for(j = i+1;j < vitri;j++)
            {
                if(st->data[i] > st->data[j])
                {
                    temp = st->data[i];
                    st->data[i] = st->data[j];
                    st->data[j] = temp ;
                }
            }
      }
}
void timkiem(ST *st,int nhap)
{
  int check=0;
  for(int i = 0;i < vitri;i++)
    {
      if(st->data[i] == nhap)
      {
        printf("tim thay [%d] vi tri %d\n",nhap,i+1);
        check = 1;
      }
    }
  if(check == 0)
  {
    printf("khong tim thay\n");
  }
}

void chen(ST *st,int chen,int nhap)
{
  if(vitri == max)
  {
    printf("stack da day\n");
    return;
  }
  else
  {
    for(int i = vitri;i >= chen;i--)
      {
        st->data[i] = st->data[i-1];
      }
    st->data[chen-1] = nhap;
    vitri++;
  }
}
  void menu(ST *st)
  {
      int a,x,y,ch,gt;
      printf("Stack Pro..:\n");
  printf(" 1.Nhap \n 2.Xoa(ko xoa vi tri)\n 3.Xoa(xoa vi tri)\n 4.In \n 5.edit\n 6.Sort\n 7.Tim kiem\n 8.chen\n 9.Thoat \n");
  int choice;
  scanf("%d",&choice);
  switch(choice)
  {
      case 1: printf("Nhap so luong stack can nhap :\n");
              scanf("%d",&a);
              for(int i = 0;i < a;i++)
              {
                  printf("\nNhap vi tri thu [%d]: ",i+1);
                  scanf("%d",&x);
                  push(st,x);
              }
              menu(st);
              break;
      case 2: system("clear");pop1(st);menu(st); break;
      case 3: system("clear");pop2(st);menu(st); break;
      case 4: system("clear");xuat(st);menu(st); break;
      case 5: system("clear");edit(st);menu(st);break;
      case 6: system("clear");sapxep(st);menu(st);break;
      case 7: system("clear");
              printf("Nhap gia tri can tim :\n");
              scanf("%d",&y);
              timkiem(st,y);menu(st);break;
      case 8: system("clear");
              while(1)
                {
              printf("Nhap vi tri chen :\n");
              scanf("%d",&ch);
                  if(ch > vitri || ch < 0)
                  {
                      printf("khong hop le\n");
                      continue;
                  }
                  else
                  {
                    break;
                  }
                }
              printf("Nhap gia tri chen :\n");
              scanf("%d",&gt);
              chen(st,ch,gt);menu(st);break;
      case 9: exit(0);break;
      default :printf("Nhap sai !\n");break;
  }
  }

  int main(void)
  {

  ST *st = (ST *)malloc(sizeof(ST));
  khoitao(st);
  menu(st);

  }
