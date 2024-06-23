//Number 1
function isValid(s) {
    const stack = [];
    const bracketMap = {
        '(': ')',
        '{': '}',
        '[': ']'
    };

    for (const char of s) {
        if (char in bracketMap) {
            stack.push(char);
        } else {
            const top = stack.pop();
            if (!top || bracketMap[top] !== char) {
                return false;
            }
        }
    }

    return stack.length === 0;
}

//Test
const inputString = "({[})";
console.log(isValid(inputString)); 


//Number 2
function twoSum(nums,target){
    let map = new Map();

    for(let i=0; i<nums.length; i++){
        let complement = target - nums[i];
        if (map.has(complement)){
            return[map.get(complement) , i];
        }
        map.set(nums[i], i);
    }
    return [];
}

//Try
const findTarget = twoSum([3,4,5,6,67,8,9], 17);
console.log(findTarget);

//Number 5 did! get it
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
//Try
const newNode = insertLinkedList([1,7,9,18,25], 20);
console.log(newNode);


//Number 6
class LinkedListNode {
    constructor(val, next = null) {
      this.val = val;
      this.next = next;
    }
  }
  
  function reverseLinkedList(head) {
    let prev = null;
    let current = head;
  
    while (current !== null) {
      const next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }
  
    return prev;
  }
  
//Try
  const head = new LinkedListNode(1, new LinkedListNode(2, new LinkedListNode(3, new LinkedListNode(4, new LinkedListNode(5)))));
  const reversedHead = reverseLinkedList(head);
  console.log(reversedHead);
