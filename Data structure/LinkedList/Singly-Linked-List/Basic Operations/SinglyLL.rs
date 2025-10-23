use std::fmt::Display;

struct Node<T> {
    value: T,
    next: Option<Box<Node<T>>>,
}

struct LinkedList<T> {
    head: Option<Box<Node<T>>>,
}

impl<T: Display+ PartialEq> LinkedList<T> {
    fn new() -> Self;
    fn push_front(&mut self, value: T);
    fn push_back(&mut self, value: T);
    fn pop_front(&mut self) -> Option<T>;
    fn pop_back(&mut self) -> Option<T>;
    fn isEmpty(&self) -> bool;
    fn front_value(&self) -> Option<&T>;
    fn print(&self);
}

impl<T:Display+ PartialEq> LinkedList<T> {
    /**
     * Creates a new empty LinkedList
     * @return a new empty LinkedList
     */
    fn new() -> Self {
        LinkedList{
            head: None
        }
    }
    /**
     * Adds a new node to the front of the list
     * @param value the value to be added
     */
    fn isEmpty(&self) -> bool {
        self.head.is_none()
    }
    /** 
     * Returns the value of the front node
     * @return Option<&T> the value of the front node or None if the list
     */
    fn push_front(&mut self, value: T) {
        let new_node = Box::new(Node{
            value: value,
            next: self.head.take(),
        });
        self.head = Some(new_node);
    }

    fn push_back(&mut self, value: T) {
        let new_node = Box::new(Node{
            value: value,
            next: None,
        });
        match self.head.as_mut() {
            Some(mut node) => {
                while let Some(next_node) = node.next.as_mut() {
                    node = next_node;
                }
                node.next = Some(new_node);
            },
            None => {
                self.head = Some(new_node);
            }
        }
    }
    /**
     * Removes the front node and returns its value
     * @return Option<T> the value of the front node or None if the list is empty
     */
    fn pop_front(&mut self) -> Option<T> {
        match self.head.take() {
            Some(node) => {
                self.head = node.next;
                Some(node.value)
            },
            None => None,
        }
     }

     /**
     * Removes the back node and returns its value
     * @return Option<T> the value of the back node or None if the list is empty
     */
    fn pop_back(&mut self) -> Option<T> {
        match self.head.as_mut() {
            Some(mut node) => {
                if node.next.is_none() {
                    let value = self.head.take().map(|n| n.value);
                    return value;
                }
                while let Some(next_node) = node.next.as_mut() {
                    if next_node.next.is_none() {
                        let value = next_node.value;
                        node.next = None;
                        return Some(value);
                    }
                    node = next_node;
                }
                None
            },
            None => None,
        }
    }
    /**
     * Prints the linked list
     */
    fn front_value(&self) -> Option<&T> {
        match self.head.as_ref() {
            Some(node) => Some(&node.value),
            None => None,
        }
    }
    /** 
     * Prints the linked list
    */
    fn print(&self) {
        let mut node = self.head.as_ref();
        while let Some(current_node) = node {
            print!("{} -> ", current_node.value);
            node = current_node.next.as_ref();
        }
    }
}
