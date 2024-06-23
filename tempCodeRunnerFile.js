class ListNode {
    constructor(value = 0, next = null) {
        this.value = value;
        this.next = next;
    }
}

function insertLinkedList(head, value) {
    const newNode = new ListNode(value);
    if (!head || value <= head.value) {
        newNode.next = head;
        return newNode;
    }
    
    let current = head;
    while (current.next && current.next.value < value) {
        current = current.next;
    }
    
    newNode.next = current.next;
    current.next = newNode;
    
    return head;
}