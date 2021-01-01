//Chris Wilhelm cwilhel8
#ifndef CQUEUE_HW7_H__
#define CQUEUE_HW7_H__

// ios forward declaration
#include <iosfwd>

/**
 * \class CQueue
 * \defgroup CQueue
 * \breif A character queue.
 */
class CQueue {
public:
  /**
   * This is the default constructor for a Queue that has data of
   * type char. This creates an empty queue. 
   */
  CQueue();
  
  /**
   * This is a constructors for a queue of letters(char) in the
   * form of a linked list, this function takes a specific letter
   * and places it at the start of the queue.
   * @param ch The input character
   */
  CQueue(const char& ch);
  
  /**
   * This is a copy constructor for a Queue. It creates a deep copy 
   * so that the two are independent in memory.
   * @param rhs, this is a reference to Queue to be copied to the new Queue
   */ 
  CQueue(const CQueue& rhs);
  
  /**
   * This is an overload of the = operator. It is intended to set the 
   * Queue equal to the one passed in to the function.
   * @param rhs, a refernce to the Queue to be assigned to the new one
   */
  void operator=(const CQueue& rhs); 
  
  /**
   * This is the destructor for the Queue. It destroys each _Node of the
   * Queue and thus frees all the memory.
   */
  ~CQueue();
  
  /**
   * This function adds a parameters to the end of the Queue.
   * @param ch The input character to add to the queue
   */
  void Enqueue(const char& ch);

  /**
   * This function removes the first character of the Queue.
   * return The first character in the queue(the one removed).
   */
  char Dequeue();
  
  /**
   * This function overloads the << operator to perform the same function as
   * Enqueue/
   * @param ch The input character to add to the queue
   * return A reference to the CQueue object
   */
  CQueue& operator<<(const char& ch);
  
  /**
   * This function is an Overloaded for operator>> to have it dequeue the first
   * data, this is performed by calling Dequeue.
   * @param ch A reference to the output character(that is removed)
   * return A reference to the CQueue object
   */
  CQueue& operator>>(char& ch);
  
  /**
   * brief Overloaded operator== to check if two queues are the same
   * @param rhs A reference to a CQueue object to compare
   * return true if two CQueues are the same node by node, else false
   */
  bool operator==(const CQueue &rhs) const;
  
  /**
   * This function concatenates two Queues by adding the second one to the end
   * of the first.
   * @param rhs, A reference to the queue to be added to the end
   * return a pointer to the concatenates Queue.
   */
  CQueue operator+(const CQueue& rhs) const;
  
  /**
   * brief Overloaded output stream operator<< to print the queue in 
   * this format data1 -> data2 -> ... -> datax -> NULL<newline>
   *   e.g. if we have a queue with three elements 'a', 'b', 'c'
   *        it will print "a -> b -> c -> NULL\n"
   * @param os A reference to the output stream object
   * @param q A constant reference to the input CQueue object
   * return A reference to the output stream object
   */
  friend std::ostream& operator<<(std::ostream& os, const CQueue& q);
  
private:
  /// friend CQueueTest class to allow the test class access the private data
  friend class CQueueTest;
  
  /**
   * struct Node_
   * breif A private structure to represent a node in a queue
   */
  struct _Node {
    char data;    ///< A character node data
    _Node *next;  ///< A pointer to the next node. nullptr if it is the end node
  };

  _Node *_head;   ///< a pointer to the head node of the queue
};

#endif // CQUEUE_HW7_H__
