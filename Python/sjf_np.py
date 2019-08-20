import operator

def compute_cmplt(process, arr_time, burst_time):
    
    total_time = 0
    exec_order = [None] * len(process)
    cmplt_time = [0] * len(process)
    small = burst_time[0]
    index = 0

    while None not in exec_order:
        for i in range(len(process)):
            if total_time <= arr_time[i] and i not in exec_order and burst_time[i] < small:
                small = burst_time[i]
                index = i
        exec_order.append(index)


    return exec_order, cmplt_time

if __name__ == '__main__':
    
    process = [1, 2, 3, 4, 5]
    arr_time = [0, 0, 2, 5, 10]
    burst_time = [10, 5, 3, 20, 2]

    process = [x for y, x in sorted(zip(arr_time, process))]
    burst_time = [x for y, z, x in sorted(zip(arr_time, process, burst_time))]
    arr_time = sorted(arr_time)

    exec_order, cmplt_time = compute_cmplt(process, arr_time, burst_time)
