def queue_empty(st):
	if st == '' or st == ' ':
		return 0
	else:
		return 1

def queue_size(st):
	return len(st.split(','))

def queue_top(st):
	return st[:st.index(',')]

def queue_back(st):
	return st[st.rindex(',')+1:]

def queue_pop(st):
	return st[st.index(',') + 1:]

def queue_pus(st,var):
	return st + ',' + var