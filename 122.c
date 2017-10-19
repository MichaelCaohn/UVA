#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct tnode
{
    int    V;
    tnode* L;
    tnode* R;
}tree;
tree node[300];
tree*root;
int  tree_size,complete;

int test(tree *root)
{
    if (!root->V)
        return 0;
    int ans = 0;
    if (!root->L || test(root->L))
        ans ++;
    if (!root->R || test(root->R))
        ans ++;
    return ans == 2;
}

void madetree(tree *root, char* str, int v)
{
    if (*str == 'R') {
        if (!root->R)
            root->R = &node[++ tree_size];
        madetree(root->R, str+1, v);
    }else if (*str == 'L') {
        if (!root->L)
            root->L = &node[++ tree_size];
        madetree(root->L, str+1, v);
    }else {
        if (root->V)
            complete = 0;
        root->V = v;
    }
}

tree*Q[300];
void output(tree *root)
{
    int move = 0,save = 0;
    Q[save ++] = root;
    printf("%d",root->V);
    while (move < save) {
        tree* now = Q[move ++];
        if (now->L) {
            printf(" %d",now->L->V);
            Q[save ++] = now->L;
        }
        if (now->R) {
            printf(" %d",now->R->V);
            Q[save ++] = now->R;
        }
    }
    printf("\n");
}

int main()
{
    char buf[256],leaf[256];
    int  value;
    complete = 1;
    root = &node[tree_size = 0];
    while (~scanf("%s",buf)) {
        if (!strcmp(buf,"()")) {
            if (!complete || !test(root))
                printf("not complete\n");
            else
                output(root);

            memset(node, 0, sizeof(node));
            root = &node[tree_size = 0];
            complete = 1;
        }
        else {
            sscanf(buf,"(%d,%s",&value,leaf);
            madetree(root, leaf, value);
        }
    }
    return 0;
}