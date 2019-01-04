#include <stdio.h>
#include <stdlib.h>
/*#include "/u/d/paurevi1/csc190/lab1/lab1good/bcgood.c"
*/
struct llnode {
   char value;
   struct llnode *next;
};
typedef struct llnode llnode;

int llnode_add_to_tail(llnode **x,char value) {
   if (x==NULL) { return -1; }
   if (*x==NULL) {
      *x = (llnode *) malloc(sizeof(llnode));
      (*x)->value = value;
      (*x)->next = NULL;
      return 0;
   } else {
      return llnode_add_to_tail(&((*x)->next),value);
   }
}

int llnode_print_from_head(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      printf("%c\n",x->value);
      return llnode_print_from_head(x->next);
   }
}

int llnode_print_from_tail(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      if (x->next == NULL) {
         printf("%c\n",x->value);
         return 0;
      } else {
         llnode_print_from_tail(x->next);
         printf("%c\n",x->value);
         return 0;
      }
   }
}

int llnode_add_to_head(llnode **x, char value) {
                if (x == NULL) {return -1;}
                else {
                llnode *p = NULL;
                p = (*x);
                *x = (llnode *)malloc(sizeof(llnode));
                (*x)->value = value;
                (*x)->next = p;
                return 0;
                }
}

int push(llnode**x, char value) {
        if (x == NULL) { return -1; }
        llnode_add_to_head(x, value);
        return 0;

}

int pop(llnode **x, char *return_value) {
        if (*x == NULL) {return -1;}
        llnode *temp;
        if (x == NULL) {return -1;}
        temp = *x;
        *return_value = (*x)->value;
        *x = (*x)->next;
         free(temp);
        return 0;
}

int main(void) {
   int n=0;
   int RVALUE = 0;
   int result = 0;
   char value;
   int rvalue = 0;
   char return_value = '0';
   char bracket1 = ')';
   char bracket2 = ']';
   char bracket3 = '}';
   llnode *input_list=NULL;

   while (scanf("%c",&value) != EOF) {
      n=n+1;
      if (value == '(') {push(&input_list, ')');}
      if (value == '[') {push(&input_list, ']');}
      if (value == '{') {push(&input_list, '}');}
      if ((value == ')') || (value == ']') || (value == '}'))
      {
         pop(&input_list, &return_value);
         if (return_value != value)
                {
                        printf("FAIL,%d\n", n-1);
                        return 0;
                        break;
                }
      }
   }
   return_value = '0';
   pop(&input_list, &return_value);
   if (return_value != '0')
        {
                 printf("FAIL,%d\n", n-3);
                 result = -1;
        }
   if (result == 0) { printf("PASS\n"); }
   return 0;
}

