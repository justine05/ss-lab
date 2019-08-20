import operator

def compute_cmplt(process, arr_time, burst_time):
    
    total_time = 0
    count = 0
    cmplt_time = [0] * len(process)

    while count < len(process):
        for i in range(len(process)):
            if arr_time[i] <= total_time:
                total_time = total_time + burst_time[i]
                cmplt_time[i] = total_time
                count = count + 1
    return cmplt_time



if __name__ == '__main__':

    process = [1, 2, 5, 4, 3]
    arr_time = [0, 0, 10, 5, 2]
    burst_time = [10, 5, 2, 20, 3]

    process = [x for y, x in sorted(zip(arr_time, process))]
    burst_time = [x for y, z, x in sorted(zip(arr_time, process, burst_time))]
    arr_time = sorted(arr_time) 

    cmplt_time = compute_cmplt(process, arr_time, burst_time)
    turn_around_time = list(map(operator.sub, cmplt_time, arr_time))
    waiting_time = list(map(operator.sub, turn_around_time, burst_time))
    avg_waiting_time = float(sum(waiting_time))/len(process)

    print("Process order = " + str(process))
    print("Completion Time = " + str(cmplt_time))
    print("Turnaround Time = " + str(turn_around_time))
    print("Waiting Time = " + str(waiting_time))
    print("Average Waiting Time = " + str(avg_waiting_time))