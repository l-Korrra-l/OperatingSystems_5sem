
mutex - global

mutex_lock:
	bts mutex, 1		; lock mutex
	jnc OK				; if mutex was open then exit procedure
	call thread_yield	; or switch process
	jmp mutex_lock		; new try
OK:ret;

mutex_unlock:
	move mutex,0		; open mutex
	ret;