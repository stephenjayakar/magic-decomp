#define NODES_MAX 10
#define NULL ((void *)0)

extern struct Node {
    int value;
    struct Node *next;
} nodes[];

extern int node_count;

struct Node *f1(int arg) {
    if (node_count >= NODES_MAX) {
        return NULL;
    }
    nodes[node_count].value = arg;
    nodes[node_count].next = NULL;
    return &nodes[node_count++];
}

void f2(struct Node **ref_node, int value) {
    struct Node *new_node = f1(value);
    if (new_node && !*ref_node) {
        *ref_node = new_node;
    }
}

void f3(struct Node *node) {
    while (node) {
        node = node->next;
    }
}

int main(void) {
    struct Node *first_node = NULL;
    struct Node *node;

    node = f1(1);
    if (node) first_node = node;

    node = f1(2);
    if (node && !first_node) first_node = node;

    node = f1(3);
    if (node && !first_node) first_node = node;

    f3(first_node);

    return 0;
}
