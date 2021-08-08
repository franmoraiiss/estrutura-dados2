#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RED 'R'
#define BLACK 'B'

typedef struct node {
  char color;
  int key; 
  struct node *left, *right; 
  int n; 
  int height; 
} node;

void insert(node **root, int key);
void color(node *x, int key);
int isRed(node *h);

node *rotateLeft(node *h);
node *rotateRight(node *h);
node *flipColors(node *h);
node *put(node **x, int key);

int size(node *x) {
  if(!x) {
    return 0;
  }

  return x->n;
}

node *searchNode(node *root , int valor) {
  if(root == NULL) {
    return NULL;
  } else if(valor < root->key) {
    return searchNode(root->left, valor);
  } else if(valor > root->key) {
    return searchNode(root->right, valor);
  } else {
    return root;
  }
}

void preorder(struct node *root) {
	if(root != NULL) {
		printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root) {
	if(root != NULL) {
		inorder(root->left);
    printf("%d ", root->key);
		inorder(root->right);
	}
}

void posorder(struct node *root) {
	if(root != NULL) {
		posorder(root->left);
		posorder(root->right);
    printf("%d ", root->key);
	}
}

int search(node *root, int valor) {
  if(root == NULL) {
    return -1;
  } else if(valor < root->key) {
    return search(root->left, valor);
  } else if(valor > root->key) {
    return search(root->right, valor);
  } else {
    return root->key;
  }
}

int main() {
  int opcao, valor;
  node *root = NULL; 

  do {
    scanf("%d", &opcao); 
    switch(opcao) {        
      case 1:
        scanf("%d", &valor); 
        insert(&root, valor);
        break;
      
      case 2:          
        scanf("%d", &valor); 
        int busca = search(root, valor);        
        if(busca != -1)  {
          printf("%d\n", busca);
        } else {
          printf("x\n");
        }
        break;
    
      case 3:
        preorder(root);
        printf("\n");
        break;
      
      case 4:
        inorder(root);
        printf("\n");
        break;
      
      case 5:
        posorder(root);
        printf("\n");
        break;
        
      case 6:
        scanf("%d", &valor);
        color(root, valor);
        break;
        
      case 7:
        break;      
    }
  } while(opcao != 7);
  
  return 0;
}

int isRed(node *h) {
  if(h == NULL) {
    return 0;
  }

  if(h->color == RED) {
    return 1;
  }

  return 0;
}

node *rotateLeft(node *h) {
  node *x = h->right;

  h->right = x->left;
  x->left = h;

  x->color = h->color;
  h->color = RED;

  x->n = h->n;
  h->n = 1 + size(h->left) + size(h->right);

  return x;
}

node *rotateRight(node *h) {
  node *x = h->left;

  h->left = x->right;
  x->right = h;

  x->color = h->color;
  h->color = RED;

  x->n = h->n;
  h->n = 1 + size(h->left) + size(h->right);

  return x;
}

node *flipColors(node *h) {
  h->color = RED;
  h->left->color = BLACK;
  h->right->color = BLACK;

  return h;
}

void insert(node **root, int key) {
  put(&(*root), key);
  (*root)->color = BLACK;
}

node *put(node **x, int key) {
  if(!(*x)) {
    (*x) = (node *) malloc(sizeof(node));
    (*x)->key = key;
    (*x)->left = (*x)->right = NULL;
    (*x)->color = RED;
    (*x)->n = 1;
    (*x)->height = 0;
    return (*x);
  }

  if(key < (*x)->key) {
    put(&(*x)->left, key);
  } else {
    put(&(*x)->right, key);
  }

  if(isRed((*x)->right) && !isRed((*x)->left)) {
    (*x) = rotateLeft(*x);
  }

  if(isRed((*x)->left) && isRed((*x)->left->left)) {
    (*x) = rotateRight((*x));
  }

  if(isRed((*x)->left) && isRed((*x)->right)) {
    (*x) = flipColors((*x));
  }
  
  (*x)->n = 1 + size((*x)->left) + size((*x)->right);

  return (*x);
}

void color(node *x, int valor) {
  node *no = searchNode(x, valor);

  if(no) {
    printf("%c\n", no->color);
  }
}
