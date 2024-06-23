//Number One
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Define a stack structure
struct Stack {
    char data[MAX_SIZE];
    int top;
};

// Initialize an empty stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(struct Stack* stack, char c) {
    stack->data[++stack->top] = c;
}

// Pop an element from the stack
char pop(struct Stack* stack) {
    return stack->data[stack->top--];
}

// Check if the input string of brackets is valid
bool isValid(char* s) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&stack, c);
        } else {
            if (stack.top == -1) {
                return false; // No matching opening bracket
            }
            char topChar = pop(&stack);
            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{')) {
                return false; // Mismatched brackets
            }
        }
    }

    return stack.top == -1; // Stack should be empty at the end
}

int main() {
    char input[MAX_SIZE];

    // Prompt user for input
    printf("Enter a string of brackets: ");
    scanf("%s", input);

    printf("Input: %s\n", input);
    printf("Is Valid: %s\n", isValid(input) ? "True" : "False");

    return 0;
}

//Number Two
#include <stdio.h>

// Function to find and print a pair with the given sum
void findPair(int arr[], int size, int targetSum) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                printf("Pair found: %d + %d = %d\n", arr[i], arr[j], targetSum);
                return;
            }
        }
    }
    printf("No pair found with the given sum.\n");
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);

    findPair(nums, size, target);

    return 0;
}



//Number Five
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to insert a new node with the given value
struct ListNode* insertNode(struct ListNode* head, int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;

    if (head == NULL || value < head->val) {
        newNode->next = head;
        return newNode; // New head
    }

    struct ListNode* curr = head;
    while (curr->next != NULL && curr->next->val < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head; // Original head remains unchanged
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a sample sorted linked list: 1 -> 2 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);

    printf("Original list: ");
    printList(head);

    int valueToInsert = 3;
    head = insertNode(head, valueToInsert);

    printf("List after inserting %d: ", valueToInsert);
    printList(head);

    // Clean up memory (free nodes)
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


//Number Six
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    return prev; // New head after reversal
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list: ");
    printList(head);

    struct ListNode* newHead = reverseList(head);

    printf("Reversed list: ");
    printList(newHead);

    // Clean up memory (free nodes)
    while (newHead != NULL) {
        struct ListNode* temp = newHead;
        newHead = newHead->next;
        free(temp);
    }

    return 0;
}
