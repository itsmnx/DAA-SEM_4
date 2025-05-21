import java.util.*;

public class TaskScheduling {

    static class Task {
        int time, deadline;
        Task(int t, int d) {
            time = t; deadline = d;
        }
    }

    public static int maxTasks(Task[] tasks) {
        int n = tasks.length;

        // Sort tasks by deadline (earliest first)
        Arrays.sort(tasks, Comparator.comparingInt(t -> t.deadline));

        // Find max possible deadline to define dp range
        int maxDeadline = 0;
        for (Task task : tasks) {
            if (task.deadline > maxDeadline)
                maxDeadline = task.deadline;
        }

        // dp[t] = max number of tasks that can be completed by time t
        int[] dp = new int[maxDeadline + 1];
        
        for (Task task : tasks) {
            // Traverse backwards to avoid reuse in the same iteration
            for (int time = task.deadline; time >= task.time; time--) {
                dp[time] = Math.max(dp[time], dp[time - task.time] + 1);
            }
        }

        // max value in dp is answer
        int maxTasks = 0;
        for (int i = 0; i <= maxDeadline; i++) {
            if (dp[i] > maxTasks)
                maxTasks = dp[i];
        }

        return maxTasks;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of tasks: ");
        int n = sc.nextInt();

        Task[] tasks = new Task[n];
        System.out.println("Enter time taken for each task:");
        int[] times = new int[n];
        for (int i = 0; i < n; i++)
            times[i] = sc.nextInt();

        System.out.println("Enter deadline for each task:");
        int[] deadlines = new int[n];
        for (int i = 0; i < n; i++)
            deadlines[i] = sc.nextInt();

        for (int i = 0; i < n; i++)
            tasks[i] = new Task(times[i], deadlines[i]);

        int result = maxTasks(tasks);
        System.out.println("Maximum number of tasks completed: " + result);
    }
}
