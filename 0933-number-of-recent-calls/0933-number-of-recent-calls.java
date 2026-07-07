class RecentCounter {
    private Queue<Integer> q;

    public RecentCounter() {
        q = new LinkedList<>();
    }
    
    public int ping(int t) {
        q.offer(t); // add new request
        // remove requests older than t - 3000
        while (q.peek() < t - 3000) {
            q.poll();
        }
        return q.size();
    }
}
