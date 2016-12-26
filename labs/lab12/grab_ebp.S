.intel_syntax noprefix
.text
.global grab_current_ebp

grab_current_ebp:
	mov eax, ebp
	ret
