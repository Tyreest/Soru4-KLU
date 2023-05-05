#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* result = NULL;
    Node* last = NULL;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        Node* node = (Node*) malloc(sizeof(Node));
        node->val = sum % 10;
        node->next = NULL;
        carry = sum / 10;
        if (result == NULL) {
            result = node;
        } else {
            last->next = node;
        }
        last = node;
    }
    
    return result;
}

int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;
    
    printf("İlk Numarayı Girin: ");
    int num1;
    scanf("%d", &num1);
    while (num1 > 0) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->val = num1 % 10;
        node->next = l1;
        l1 = node;
        num1 /= 10;
    }
    
    printf("İkinci numarayı girin: ");
    int num2;
    scanf("%d", &num2);
    while (num2 > 0) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->val = num2 % 10;
        node->next = l2;
        l2 = node;
        num2 /= 10;
    }
    
    Node* result = addTwoNumbers(l1, l2);
    
    printf("Sonuç: ");
    while (result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");
    
    return 0;
}
