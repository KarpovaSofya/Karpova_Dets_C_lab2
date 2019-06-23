from QueueFunc import*

s = "1,2,3,4,5"
print("Queue - "+ s)
print("queue_size: "+ str(queue_size(s)))
print("queue_top: "+ queue_top(s))
print("queue_back: "+ queue_back(s))
print("queue_pop: "+ queue_pop(s))
print("queue_pus: "+ queue_pus(s,'789'))
print("queue_empty: "+ str(queue_empty(s)))