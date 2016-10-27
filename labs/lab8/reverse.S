.intel_syntax noprefix
.text
.global reverse_asm

reverse_asm:
	push ebx

	#ebx for headptr, ecx nextptr, edx newhead_ptr
	#set all three to null
	mov eax, 0x0
	mov ebx, eax
	mov ecx, eax
	mov edx, eax
	
	mov eax, [esp + 8]
	cmp eax, 0
	je null_ret

	add eax, [esp + 12]
	#ebx is headptr
	mov ebx, eax

while_start:
	cmp ebx, 0x0
	je while_done
	
	#nextptr = (void *)(*((unsigned long *) headptr));
	mov ecx, [ebx]

	#∗(unsigned long ∗) headptr = (unsigned long) new headptr ;
	mov [ebx], edx

	#new_headptr = headptr
	mov edx, ebx

	#headptr = nextptr
	mov ebx, ecx

	#next iteration
	jmp while_start

while_done:
	mov eax, edx
	sub eax, [esp + 12]
	
	pop ebx
	ret

null_ret:
	pop ebx
	ret

