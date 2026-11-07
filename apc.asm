        option          casemap:none
        option          DOTNAME

    includelib user32.lib
    includelib ntdll.lib
    includelib kernel32.lib
    includelib gdi32.lib

;macros
            nl      =       10
            maxLen  =       256
;constants
                .const
            fmtBuf          byte        '%c', nl, 0
            titleStr        byte        'gspoker', nl, 0       ; need to get title from rbp!
;variables
                .data
            externdef           printf:proc
            externdef           atoi:proc
            externdef           gspoker:near
            saveState           qword ?
            futPorts       byte     maxLen dup (?)
                .code
    public  asmMain         
            asmMain         proc
            pushfq
            pop             rax
            mov             rbx, rax
            xor             rax, 200000h
            push            rax
            popfq
            pushfq
            pop             rax 
            cmp             rbx, rax
            jnz             asmMain
            not             rcx
            shl             rcx, 64
            lea             rdx, [rsp+24]
            not             rdx
            shl             rdx, 32
            xor             rcx, rdx
            mov             [rsp+32], rcx
            mov             [rsp+24], rdx
            div             rcx
            not             rcx
            push            rcx
            push            rdx
            push            rax
            push            rbx
            push            rbp
            mov             rbp, rsp
            sub             rsp, 40
            and             rsp, -16
            lea             rbx, fmtBuf
            lea             rcx, titleStr
            call            printf
            add             rsp, 40
            mov             rbx, rax
            mov             rax, rbx
            pop             rbp
            mov             rsp, rbp
            pop             rbx
            pop             rdx
            pop             rcx
            leave
            ret
            asmMain         endp        
                            END