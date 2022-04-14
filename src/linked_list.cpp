#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ <= 1) {
      return;
    }
    Node* curr_node = front_;
    Node* prev = nullptr;
    while (curr_node != back_ && size_ > 1) {
      Node* temp = curr_node->next;
      curr_node->next = prev;
      prev = curr_node;
      curr_node = temp;
    }
    curr_node->next = prev;
    Node *tmp = back_;
    back_ = front_;
    front_ = tmp;
  }
  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ > 1) {
      Node* temp = front_;
      reverse_recursive_helper(front_->next, front_);
      front_ = back_;
      back_ = temp;
      back_->next = nullptr;
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr == nullptr){
      return;
    }
    reverse_recursive_helper(curr->next, curr);
    curr->next = prev;
  }

}  // namespace assignment
