#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right; 
    int n; 
}
node;

int size(node *x);
void preorder(node *root);
void inorder(struct node* root);
void posorder(node *root);
void insert(node **root, int key);
node *put(node **x, int key);
node *removeNode(node* root, int key);
node *search(node* root, int key);

int main(void) {
    node *root = NULL;

    int v[10] = {9, 2, 8, 1, 7, 3, 4, 6, 5, 0};

    for(int i = 0; i < 10; i++) {
        insert(&root, v[i]);
    }

    printf("In-ordem: ");
    inorder(root);

    printf("\nDigite um elemento para procurar na arvore: ");
    int aux;
    scanf("%d", &aux);

    if(search(root, aux)){
        printf("\n%d existe na arvore\n", aux);
    } else {
        printf("\n%d nao existe na arvore\n", aux);
    }

    printf("\nDigite um elemento para deletar da arvore: ");
    scanf("%d", &aux);

    root = removeNode(root, aux);
    printf("\n");

    printf("In-ordem: ");
    inorder(root);
    printf("\n");

    printf("Pre-ordem: ");
    preorder(root);
    printf("\n");

    printf("Pos-ordem: ");
    posorder(root);
    printf("\n");

    return 0;
}

void preorder(node *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void posorder(node *root) {
    if(root != NULL) {
        posorder(root->left);
        posorder(root->right);
        printf("%d ", root->key);   
    }
}

int size(node *x) {
    if(!x) {
        return 0;
    } else {
        return x->n;   
    }
}

node *put(node **x, int key) {
    if (!(*x)) {
        (*x) = (node*)malloc(sizeof(node));
        (*x)->key = key;
        (*x)->left = (*x)->right = NULL;
        (*x)->n = 1;

        return (*x);
    }

    if (key < (*x)->key) {
        (*x)->left = put(&(*x)->left, key);
    } else {
        (*x)->right = put(&(*x)->right, key);
    }

    (*x)->n = 1 + size((*x)->left) + size((*x)->right);

    return (*x);
}

void insert(node **root, int key) {
    (*root) = put(&(*root), key);
}

node *removeNode(node* root, int key) {
    if(root == NULL) {
        return root;
    }

    if(key < root->key) {
        root->left = removeNode(root->left, key);
    } else if(key > root->key) {
        root->right = removeNode(root->right, key);
    } else {
        if(root->left == NULL) {
            node *temp = root->right;
            free(root);

            return temp;
        } else if(root->right == NULL) {
            node *temp = root->left;
            free(root);

            return temp;
        }

        node *temp = root->right;
 
        while(temp && temp->left != NULL) {
            temp = temp->left;
        }

        root->key = temp->key;
        root->right = removeNode(root->right, temp->key);
    }

    return root;
}


node *search(node* root, int key) {
    if(root == NULL || root->key == key) {
       return root;
    }

    if(root->key < key) {
       return search(root->right, key);
    }
 
    return search(root->left, key);
}
