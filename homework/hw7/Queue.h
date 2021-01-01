//Chris Wilhelm cwilhel8
#ifndef QUEUE_HW7_H__
#define QUEUE_HW7_H__

// ios forward declaration
#include <iosfwd>
#include <ostream>
//
/**
 * This is a templated class of CQueue
 * It allows for ant datatype to be used rather than just char
 * is also has a useDataAsPriority parameter, if this is true, it
 * will sort the data, else order will be first in first position
 */
template < typename DataType, bool useDataAsPriority>
class Queue {
public:
  /**
   * Default constructor that will set _head to be nullptr
   */
  Queue();
  
  /**
   * constructor so the first node is ch
   * @param ch The input character
   */
  Queue(const DataType& ch);
  
  /**
   * Copy constructor, copies contents of rhs into Queue
   * @param rhs A constant reference to the input CQueue object
   */ 
  Queue(const Queue<DataType, useDataAsPriority>& rhs);
  
  /**
   * Overloaded operator= to assign a queue to another queue
   * @param rhs A reference to the input CQueue object
   */
  void operator=(const Queue<DataType, useDataAsPriority>& rhs); 
  
  /**
   * The destructor - release memories if needed
   */
  ~Queue();
  
  /**
   * A function to enqueue a datatype to the queue, if the Queue
   * is unsorted, will be added to end, else will be sorted and 
   * added to the proper posiiton
   * @param ch The input character to add to the queue
   */
  void Enqueue(const DataType& ch);

  /**
   * A function to dequeue a datatype from the queue, removes
   * first datatype
   * @return The first data in the queue
   */
  DataType Dequeue();
  
  /**
   * Overloaded operator<< to enqueue, adds data to the queue
   * If it is sorted, then the data is inputed at the correct
   * space, else it is places at the end.
   * @param ch The input data  to add to the queue
   * return A reference to the Queue object
   */
  Queue& operator<<(const DataType& ch);
  
  /**
   * Overloaded operator>> to dequeue
   * @param ch A reference to the output datatype
   * return A reference to the Queue object
   */
  Queue& operator>>(DataType& ch);
  
  /**
   * Overloaded operator== to check if two queues are the same
   * @param rhs A reference to a Queue object to compare
   * return true if two Queues are the same node by node, else false
   */
  bool operator==(const Queue<DataType, useDataAsPriority> &rhs) const;
  
  /**
   * brief Overloaded operator+ to concatenate two queues
   * if the useDataAsPriority it true, the concatenated Queue will
   * also be sorted. If not, the concatentation will occur at the end.
   * @param rhs a refernce to the right hand side of the concatentation.
   * return Queue, a pointer Queue(concatenated)
   */
  Queue operator+(const Queue<DataType, useDataAsPriority>& rhs) const;
  
  /**
   * \brief Overloaded output stream operator<< to print the queue in 
   * this format data1 -> data2 -> ... -> datax -> NULL<newline>
   *   e.g. if we have a queue with three elements 'a', 'b', 'c'
   *        it will print "a -> b -> c -> NULL\n"
   * @param os A reference to the output stream object
   * @param q A constant reference to the input Queue object
   * return A reference to the output stream object
   */
  // template <typename U, bool T>
  friend std::ostream& operator<<(std::ostream& os, const Queue<DataType, useDataAsPriority>& q){
    _Node* curr;
    for(curr = q._head; curr != nullptr; curr = curr->next) {
      os << curr->data << " -> ";
    }
    os << "NULL\n";
    return os;
  }
  
private:
  /// friend CQueueTest class to allow the test class access the private data
  friend class TQueueTest;
  
  /**
   * \struct Node_
   * \breif A private structure to represent a node in a queue
   */
  struct _Node {
    DataType data;    ///< A character node data
    _Node *next;  ///< A pointer to the next node. nullptr if it is the end node
  };
  _Node *_head;   ///< a pointer to the head node of the queue
};
#include "Queue.inc"
#endif // CQUEUE_HW7_H__
