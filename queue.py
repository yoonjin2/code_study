import sys

t = int(sys.stdin.readline().rstrip())

queue_list = []
front = -1
rear = -1

for i in range(t):
    command = sys.stdin.readline().split()
    # push
    if command[0] == 'push':
        rear += 1
        queue_list.append(int(command[1]))
    else:
        # pop
        if command[0] == 'pop':
            # empty
            # command == empty 와 기대값 다름
            if front == rear:
                print(-1)
            else:
                print(queue_list[front+1])
                queue_list.pop(front+1)
                rear -= 1
        # size
        elif command[0] == 'size':
            print(len(queue_list))
        # empty
        elif command[0] == 'empty':
            if front == rear:
                print(1)
            else:
                # not empty
                print(0)
        # front
        elif command[0] == 'front':
            # empty
            # command == empty 와 기대값 다름
            if front == rear:
                print(-1)
            else:
                print(queue_list[front+1])
        # back
        elif command[0] == 'back':
            # empty
            # command == empty 와 기대값 다름
            if front == rear:
                print(-1)
            else:
                print(queue_list[rear])
        else:
            break