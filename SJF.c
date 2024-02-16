// SJF


#include<stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int proc[10], burst[10], wait[10], turn[10], arr[10], t_wait = 0, t_turn = 0, n, i, j;
    float avg_wait, avg_turn;

    printf("\nEnter total no of process : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter arrival time, burst time for process P#%d : ", i + 1);
        scanf("%d %d", &arr[i], &burst[i]);
        proc[i] = i + 1;
        wait[i] = 0;
    }

    // Sorting processes based on burst time using bubble sort
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (burst[j] > burst[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swap(&burst[j], &burst[j + 1]);
                swap(&proc[j], &proc[j + 1]);
            }
        }
    }

    turn[0] = burst[0];
    printf("\nProcess         Arrival          Burst               Turnaround \n");
    printf("\nP#%d              %d                %d                   %d", proc[0], arr[0], burst[0], turn[0]);

    for (i = 1; i < n; i++) {
        wait[i] = wait[i - 1] + burst[i - 1];
        turn[i] = wait[i] + burst[i];
        t_wait += wait[i];
        t_turn += turn[i];
        printf("\nP#%d              %d                %d                   %d", proc[i], arr[i], burst[i], turn[i]);
    }

    avg_wait = (float)t_wait / n;
    avg_turn = (float)t_turn / n;

    printf("\nAvg_waiting time : %f , Avg_turnaround time : %f ", avg_wait, avg_turn);

    return 0;
}

