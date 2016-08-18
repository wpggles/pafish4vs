option casemap:none

.code

get_number_of_processors proc stdcall
    mov rax, gs : [60h]
    mov rax, [rax + 0B8h]
    ret
get_number_of_processors endp

end