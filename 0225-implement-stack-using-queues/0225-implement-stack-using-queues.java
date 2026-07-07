import java.util.LinkedList;
import java.util.Queue;

class MyStack {
    private Queue<Integer> q1;
    private Queue<Integer> q2;

    public MyStack() {
        q1 = new LinkedList<>();
        q2 = new LinkedList<>();
    }
    
    public void push(int x) {
        q1.offer(x);
    }
    
    public int pop() {
        // Move all but last element to q2
        while (q1.size() > 1) {
            q2.offer(q1.poll());
        }
        int val = q1.poll(); // last element = top of stack
        // Swap queues
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
        return val;
    }
    
    public int top() {
        while (q1.size() > 1) {
            q2.offer(q1.poll());
        }
        int val = q1.peek(); // last element
        q2.offer(q1.poll()); // move it to q2 as well
        // Swap queues
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
        return val;
    }
    
    public boolean empty() {
        return q1.isEmpty();
    }
}