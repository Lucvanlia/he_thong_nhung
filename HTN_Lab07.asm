ORG 00H
MAIN:
    MOV TMOD, #20H   
    MOV TH1, #-3      
    MOV SCON, #50H    
    SETB TR1          

lap:
    jnb p1.0, ktra1   
    jnb p1.1, ktra2   
    jnb p1.2, ktra3   
    jnb p1.3, ktra4   
    jnb p1.4, ktra5   
    jmp lap           

ktra1:
    jnb p1.0, $       
    mov a, #'L'       
    call truyen       
    jmp lap

ktra2:
    jnb p1.1, $       
    mov a, #'T'       
    call truyen
    jmp lap

ktra3:
    jnb p1.2, $       
    mov a, #'P'      
    call truyen
    jmp lap

ktra4:
    jnb p1.3, $       
    mov a, #'D'      
    call truyen
    jmp lap

ktra5:
    jnb p1.4, $       
    mov a, #'T'       
    call truyen
    jmp lap

truyen:              
    mov sbuf, a       
    jnb ti, $         
    clr ti            
    ret               

END
