# include <stdio.h>
# include <stdlib.h>

typedef struct tree{
  int num;
  struct tree* sad;
  struct tree* sae;
} Tree;

// create tree

Tree* create_tree()
{
  return NULL;
}

// tree is empty?

int tree_is_empty(Tree* t)
{
  return t == NULL;
}

// show tree

void show_tree(Tree* t)
{
  printf("[");
  if(!tree_is_empty(t)){
    printf("%d", t->num);
    show_tree(t->sae);
    show_tree(t->sad);
  }
  printf("]");
}

void put_tree(Tree** t, int num)
{
  if(*t == NULL) {
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->sae = NULL;
    (*t)->sad = NULL;
    (*t)->num = num;
  } else {
    if(num < (*t)->num){
      put_tree(&(*t)->sae, num);
    } if(num > (*t)->num) {
      put_tree(&(*t)->sae, num);
    }
  }
}

int is_in_tree(Tree* t, int num)
{
  if(tree_is_empty(t)){
    return 0;
  }

  return t->num==num || is_in_tree(t->sae, num) || is_in_tree(t->sad, num);
}

int main()
{
  Tree* t = create_tree();

  put_tree(&t, 12);
  put_tree(&t, 15);
  put_tree(&t, 10);
  put_tree(&t, 13);

  show_tree(t);

  if(tree_is_empty(t)){
    printf("Arvore vazia\n");
  } else{
    printf("\n\nA arvore nao esta vazia\n");
  }

  if(is_in_tree(t, 15)){
    printf("Tem o numero 15 na arvore\n");
  } else{
    printf("O numero 15 n existe na arvore\n");
  }

  if(is_in_tree(t, 22)){
    printf("Tem o numero 22 na arvore\n");
  } else{
    printf("O numero 22 n existe na arvore\n");
  }

  free(t);
  return 0;
}