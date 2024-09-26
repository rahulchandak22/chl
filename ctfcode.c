int32_t (* const)() _init()
{
    if (__gmon_start__ == 0)
        return __gmon_start__;
    
    return __gmon_start__();
}

int32_t sub_1020()
{
    int32_t var_4 = data_3ff8;
    /* jump -> data_3ffc */
}

void __libc_start_main(int32_t (* main)(int32_t argc, char** argv, char** envp), int32_t argc, char** ubp_av, void (* init)(), void (* fini)(), void (* rtld_fini)(), void* stack_end) __noreturn
{
    /* tailcall */
    return __libc_start_main(main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}

int32_t sub_1036()
{
    /* tailcall */
    return sub_1020(0);
}

int32_t printf(char const* format, ...)
{
    /* tailcall */
    return printf();
}

int32_t sub_1046()
{
    /* tailcall */
    return sub_1020(8);
}

char* fgets(char* buf, int32_t n, FILE* fp)
{
    /* tailcall */
    return fgets(buf, n, fp);
}

int32_t sub_1056()
{
    /* tailcall */
    return sub_1020(0x10);
}

int32_t fclose(FILE* fp)
{
    /* tailcall */
    return fclose(fp);
}

int32_t sub_1066()
{
    /* tailcall */
    return sub_1020(0x18);
}

int32_t fseek(FILE* fp, int32_t offset, int32_t whence)
{
    /* tailcall */
    return fseek(fp, offset, whence);
}

int32_t sub_1076()
{
    /* tailcall */
    return sub_1020(0x20);
}

size_t fread(void* buf, size_t size, size_t count, FILE* fp)
{
    /* tailcall */
    return fread(buf, size, count, fp);
}

int32_t sub_1086()
{
    /* tailcall */
    return sub_1020(0x28);
}

int32_t puts(char const* str)
{
    /* tailcall */
    return puts(str);
}

int32_t sub_1096()
{
    /* tailcall */
    return sub_1020(0x30);
}

void exit(int32_t status) __noreturn
{
    /* tailcall */
    return exit(status);
}

int32_t sub_10a6()
{
    /* tailcall */
    return sub_1020(0x38);
}

int32_t setvbuf(FILE* fp, char* buf, int32_t mode, size_t size)
{
    /* tailcall */
    return setvbuf(fp, buf, mode, size);
}

int32_t sub_10b6()
{
    /* tailcall */
    return sub_1020(0x40);
}

FILE* fopen(char const* filename, char const* mode)
{
    /* tailcall */
    return fopen(filename, mode);
}

int32_t sub_10c6()
{
    /* tailcall */
    return sub_1020(0x48);
}

int32_t putchar(int32_t c)
{
    /* tailcall */
    return putchar(c);
}

int32_t sub_10d6()
{
    /* tailcall */
    return sub_1020(0x50);
}

int32_t __isoc99_scanf(char const* format, ...)
{
    /* tailcall */
    return __isoc99_scanf();
}

int32_t sub_10e6()
{
    /* tailcall */
    return sub_1020(0x58);
}

void __cxa_finalize(void* d)
{
    /* tailcall */
    return __cxa_finalize(d);
}

void __convention("regparm") _start(int32_t arg1, void (* arg2)()) __noreturn
{
    int32_t stack_end = arg1;
    __libc_start_main(main, __return_addr, &ubp_av, nullptr, nullptr, arg2, &stack_end);
    /* no return */
}

int32_t sub_1128() __pure
{
    return;
}

int32_t __x86.get_pc_thunk.bx() __pure
{
    return;
}

void* deregister_tm_clones()
{
    return &__TMC_END__;
}

int32_t register_tm_clones()
{
    return 0;
}

void __do_global_dtors_aux()
{
    if (__TMC_END__ == 0)
    {
        if (__cxa_finalize != 0)
            __cxa_finalize(__dso_handle);
        
        deregister_tm_clones();
        __TMC_END__ = 1;
    }
}

int32_t frame_dummy()
{
    /* tailcall */
    return register_tm_clones();
}

int32_t __x86.get_pc_thunk.dx() __pure
{
    return;
}

void get_flag() __noreturn
{
    FILE* fp = fopen("/home/ctf/flag.txt", &data_201b);
    
    if (fp == 0)
    {
        puts("Flag file is missing.");
        exit(1);
        /* no return */
    }
    
    fseek(fp, offset, 0);
    void buf;
    size_t eax_1 = fread(&buf, 1, 0x40, fp);
    
    if (eax_1 == 0)
        puts("End of file.");
    else
    {
        *(eax_1 + &buf) = 0;
        printf("Read data: %s\n", &buf);
        offset += eax_1;
    }
    
    fclose(fp);
    exit(1);
    /* no return */
}

void menu() __noreturn
{
    puts("What would you like to do?");
    puts("1. Know about HSBC");
    puts("2. Get the flag format");
    puts("3. Send a message to HSBC");
    puts("4. Exit");
    int32_t var_10;
    __isoc99_scanf(&data_20b6, &var_10);
    int32_t eax = var_10;
    
    if (eax == 4)
        puts("Goodbye!");
    else if (eax > 4)
        puts("Invalid choice.");
    else if (eax == 3)
    {
        printf("Please enter your message: ");
        void format;
        __isoc99_scanf(&data_2131, &format, 0x40);
        printf("Thank you for your message: ");
        printf(&format);
        putchar(0xa);
    }
    else if (eax > 3)
        puts("Invalid choice.");
    else if (eax == 1)
        puts("HSBC is a British multinational …");
    else if (eax == 2)
        puts("HSBC{.*}");
    else
        puts("Invalid choice.");
    
    exit(1);
    /* no return */
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    void* const __return_addr_1 = __return_addr;
    int32_t* var_10 = &argc;
    setvbuf(*stdout, nullptr, 2, 0);
    puts("Welcome to the HSBC CTF!");
    printf("Enter your name: ");
    void var_90;
    fgets(&var_90, 0x80, *stdin);
    printf("Hello, ");
    printf(&var_90);
    putchar(0xa);
    menu();
    get_flag()
    /* no return */
}

int32_t _fini()
{
    return;
}