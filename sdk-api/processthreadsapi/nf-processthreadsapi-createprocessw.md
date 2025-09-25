# CreateProcessW function

## Description

Creates a new process and its primary thread. The new process runs in the security context of the calling process.

If the calling process is impersonating another user, the new process uses the token for the calling process, not the impersonation token. To run the new process in the security context of the user represented by the impersonation token, use the
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) or
[CreateProcessWithLogonW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithlogonw) function.

## Parameters

### `lpApplicationName` [in, optional]

The name of the module to be executed. This module can be a Windows-based application. It can be some other type of module (for example, MS-DOS or OS/2) if the appropriate subsystem is available on the local computer.

The string can specify the full path and file name of the module to execute or it can specify a partial name. In the case of a partial name, the function uses the current drive and current directory to complete the specification. The function will not use the search path. This parameter must include the file name extension; no default extension is assumed.

The *lpApplicationName* parameter can be **NULL**. In that case, the module name must be the first white space–delimited token in the *lpCommandLine* string. If you are using a long file name that contains a space, use quoted strings to indicate where the file name ends and the arguments begin; otherwise, the file name is ambiguous. For example, consider the string "c:\program files\sub dir\program name". This string can be interpreted in a number of ways. The system tries to interpret the possibilities in the following order:

1. **c:\program.exe**
1. **c:\program files\sub.exe**
1. **c:\program files\sub dir\program.exe**
1. **c:\program files\sub dir\program name.exe**

If the executable module is a 16-bit application, *lpApplicationName* should be **NULL**, and the string pointed to by *lpCommandLine* should specify the executable module as well as its arguments.

To run a batch file, you must start the command interpreter; set *lpApplicationName* to cmd.exe and set *lpCommandLine* to the following arguments: /c plus the name of the batch file.

### `lpCommandLine` [in, out, optional]

The command line to be executed.

The maximum length of this string is 32,767 characters, including the Unicode terminating null character. If *lpApplicationName* is **NULL**, the module name portion of *lpCommandLine* is limited to **MAX_PATH** characters.

The Unicode version of this function, **CreateProcessW**, can modify the contents of this string. Therefore, this parameter cannot be a pointer to read-only memory (such as a **const** variable or a literal string). If this parameter is a constant string, the function may cause an access violation.

The *lpCommandLine* parameter can be NULL. In that case, the function uses the string pointed to by *lpApplicationName* as the command line.

If both *lpApplicationName* and *lpCommandLine* are non-**NULL**, the null-terminated string pointed to by *lpApplicationName* specifies the module to execute, and the null-terminated string pointed to by *lpCommandLine* specifies the command line. The new process can use
[GetCommandLine](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-getcommandlinea) to retrieve the entire command line. Console processes written in C can use the *argc* and *argv* arguments to parse the command line. Because argv[0] is the module name, C programmers generally repeat the module name as the first token in the command line.

If *lpApplicationName* is NULL, the first white space–delimited token of the command line specifies the module name. If you are using a long file name that contains a space, use quoted strings to indicate where the file name ends and the arguments begin (see the explanation for the *lpApplicationName* parameter). If the file name does not contain an extension, .exe is appended. Therefore, if the file name extension is .com, this parameter must include the .com extension. If the file name ends in a period (.) with no extension, or if the file name contains a path, .exe is not appended. If the file name does not contain a directory path, the system searches for the executable file in the following sequence:

1. The directory from which the application loaded.
2. The current directory for the parent process.
3. The 32-bit Windows system directory. Use the [GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya) function to get the path of this directory.
4. The 16-bit Windows system directory. There is no function that obtains the path of this directory, but it is searched. The name of this directory is System.
5. The Windows directory. Use the
   [GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya) function to get the path of this directory.
6. The directories that are listed in the PATH environment variable. Note that this function does not search the per-application path specified by the **App Paths** registry key. To include this per-application path in the search sequence, use the [ShellExecute](https://learn.microsoft.com/previous-versions/windows/desktop/axe/shellexecute) function.

The system adds a terminating null character to the command-line string to separate the file name from the arguments. This divides the original string into two strings for internal processing.

### `lpProcessAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that determines whether the returned handle to the new process object can be inherited by child processes. If *lpProcessAttributes* is **NULL**, the handle cannot be inherited.

The **lpSecurityDescriptor** member of the structure specifies a security descriptor for the new process. If *lpProcessAttributes* is NULL or **lpSecurityDescriptor** is **NULL**, the process gets a default security descriptor. The ACLs in the default security descriptor for a process come from the primary token of the creator.**Windows XP:** The ACLs in the default security descriptor for a process come from the primary or impersonation token of the creator. This behavior changed with Windows XP with SP2 and Windows Server 2003.

### `lpThreadAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies a security descriptor for the new thread and determines whether child processes can inherit the returned handle. If *lpThreadAttributes* is NULL, the thread gets a default security descriptor and the handle cannot be inherited. The access control lists (ACL) in the default security descriptor for a thread come from the primary token of the creator.

### `bInheritHandles` [in]

If this parameter is TRUE, each inheritable handle in the calling process is inherited by the new process. If the parameter is FALSE, the handles are not inherited. Note that inherited handles have the same value and access rights as the original handles.
For additional discussion of inheritable handles, see Remarks.

**Terminal Services:** You cannot inherit handles across sessions. Additionally, if this parameter is TRUE, you must create the process in the same session as the caller.

**Protected Process Light (PPL) processes:** The generic handle inheritance is blocked when a PPL process creates a non-PPL process since PROCESS_DUP_HANDLE is not allowed from a non-PPL process to a PPL process. See [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights)

### `dwCreationFlags` [in]

The flags that control the priority class and the creation of the process. For a list of values, see
[Process Creation Flags](https://learn.microsoft.com/windows/desktop/ProcThread/process-creation-flags).

This parameter also controls the new process's priority class, which is used to determine the scheduling priorities of the process's threads. For a list of values, see
[GetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getpriorityclass). If none of the priority class flags is specified, the priority class defaults to **NORMAL_PRIORITY_CLASS** unless the priority class of the creating process is **IDLE_PRIORITY_CLASS** or **BELOW_NORMAL_PRIORITY_CLASS**. In this case, the child process receives the default priority class of the calling process.

If the dwCreationFlags parameter has a value of 0:

- The process inherits both the error mode of the caller and the parent's console.
- The environment block for the new process is assumed to contain ANSI characters (see *lpEnvironment* parameter for additional information).
- A 16-bit Windows-based application runs in a shared Virtual DOS machine (VDM).

### `lpEnvironment` [in, optional]

A pointer to the [environment block](https://learn.microsoft.com/windows/win32/procthread/environment-variables) for the new process. If this parameter is **NULL**, the new process uses the environment of the calling process.

An environment block consists of a null-terminated block of null-terminated strings. Each string is in the following form:

*name*=*value*\0

Because the equal sign is used as a separator, it must not be used in the name of an environment variable.

An environment block can contain either Unicode or ANSI characters. If the environment block pointed to by *lpEnvironment* contains Unicode characters, be sure that *dwCreationFlags* includes **CREATE_UNICODE_ENVIRONMENT**.

The ANSI version of this function, **CreateProcessA** fails if the total size of the environment block for the process exceeds 32,767 characters.

Note that an ANSI environment block is terminated by two zero bytes: one for the last string, one more to terminate the block. A Unicode environment block is terminated by four zero bytes: two for the last string, two more to terminate the block.

### `lpCurrentDirectory` [in, optional]

The full path to the current directory for the process. The string can also specify a UNC path.

If this parameter is **NULL**, the new process will have the same current drive and directory as the calling process. (This feature is provided primarily for shells that need to start an application and specify its initial drive and working directory.)

### `lpStartupInfo` [in]

A pointer to a
[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfow) or [STARTUPINFOEX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-startupinfoexw) structure.

To set extended attributes, use a [STARTUPINFOEX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-startupinfoexw) structure and specify EXTENDED_STARTUPINFO_PRESENT in the *dwCreationFlags* parameter.

Handles in
[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfow) or [STARTUPINFOEX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-startupinfoexw) must be closed with
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) when they are no longer needed.

**Important** The caller is responsible for ensuring that the standard handle fields in [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfow) contain valid handle values. These fields are copied unchanged to the child process without validation, even when the **dwFlags** member specifies **STARTF_USESTDHANDLES**. Incorrect values can cause the child process to misbehave or crash. Use the [Application Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/application-verifier) runtime verification tool to detect invalid handles.

### `lpProcessInformation` [out]

A pointer to a
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-process_information) structure that receives identification information about the new process.

Handles in
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-process_information) must be closed with
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) when they are no longer needed.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Note that the function returns before the process has finished initialization. If a required DLL cannot be located or fails to initialize, the process is terminated. To get the termination status of a process, call [GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess).

## Remarks

The process is assigned a process identifier. The identifier is valid until the process terminates. It can be used to identify the process, or specified in the
[OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess) function to open a handle to the process. The initial thread in the process is also assigned a thread identifier. It can be specified in the
[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread) function to open a handle to the thread. The identifier is valid until the thread terminates and can be used to uniquely identify the thread within the system. These identifiers are returned in the
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-process_information) structure.

The name of the executable in the command line that the operating system provides to a process is not necessarily identical to that in the command line that the calling process gives to the
**CreateProcess** function. The operating system may prepend a fully qualified path to an executable name that is provided without a fully qualified path.

The calling thread can use the
[WaitForInputIdle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitforinputidle) function to wait until the new process has finished its initialization and is waiting for user input with no input pending. This can be useful for synchronization between parent and child processes, because
**CreateProcess** returns without waiting for the new process to finish its initialization. For example, the creating process would use
**WaitForInputIdle** before trying to find a window associated with the new process.

The preferred way to shut down a process is by using the
[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess) function, because this function sends notification of approaching termination to all DLLs attached to the process. Other means of shutting down a process do not notify the attached DLLs. Note that when a thread calls
**ExitProcess**, other threads of the process are terminated without an opportunity to execute any additional code (including the thread termination code of attached DLLs). For more information, see
[Terminating a Process](https://learn.microsoft.com/windows/desktop/ProcThread/terminating-a-process).

A parent process can directly alter the environment variables of a child process during process creation. This is the only situation when a process can directly change the environment settings of another process. For more information, see
[Changing Environment Variables](https://learn.microsoft.com/windows/desktop/ProcThread/changing-environment-variables).

If an application provides an environment block, the current directory information of the system drives is not automatically propagated to the new process. For example, there is an environment variable named =C: whose value is the current directory on drive C. An application must manually pass the current directory information to the new process. To do so, the application must explicitly create these environment variable strings, sort them alphabetically (because the system uses a sorted environment), and put them into the environment block. Typically, they will go at the front of the environment block, due to the environment block sort order.

One way to obtain the current directory information for a drive X is to make the following call:
`GetFullPathName("X:", ...)`. That avoids an application having to scan the environment block. If the full path returned is X:\, there is no need to pass that value on as environment data, since the root directory is the default current directory for drive X of a new process.

When a process is created with **CREATE_NEW_PROCESS_GROUP** specified, an implicit call to
[SetConsoleCtrlHandler](https://learn.microsoft.com/windows/console/setconsolectrlhandler)(**NULL**,**TRUE**) is made on behalf of the new process; this means that the new process has CTRL+C disabled. This lets shells handle CTRL+C themselves, and selectively pass that signal on to sub-processes. CTRL+BREAK is not disabled, and may be used to interrupt the process/process group.

By default, passing **TRUE** as the value of the *bInheritHandles* parameter causes all inheritable handles to be inherited by the new process.
This can be problematic for applications which create processes from multiple threads simultaneously
yet desire each process to inherit different handles.
Applications can use the
[UpdateProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-updateprocthreadattribute) function
with the **PROC_THREAD_ATTRIBUTE_HANDLE_LIST** parameter
to provide a list of handles to be inherited by a particular process.

### Security Remarks

The first parameter, *lpApplicationName*, can be **NULL**, in which case the executable name must be in the white space–delimited string pointed to by *lpCommandLine*. If the executable or path name has a space in it, there is a risk that a different executable could be run because of the way the function parses spaces. The following example is dangerous because the function will attempt to run "Program.exe", if it exists, instead of "MyApp.exe".

``` syntax
    LPTSTR szCmdline = _tcsdup(TEXT("C:\\Program Files\\MyApp -L -S"));
    CreateProcess(NULL, szCmdline, /* ... */);
```

If a malicious user were to create an application called "Program.exe" on a system, any program that incorrectly calls
**CreateProcess** using the Program Files directory will run this application instead of the intended application.

To avoid this problem, do not pass **NULL** for *lpApplicationName*. If you do pass **NULL** for *lpApplicationName*, use quotation marks around the executable path in *lpCommandLine*, as shown in the example below.

``` syntax
    LPTSTR szCmdline[] = _tcsdup(TEXT("\"C:\\Program Files\\MyApp\" -L -S"));
    CreateProcess(NULL, szCmdline, /*...*/);
```

#### Examples

For an example, see
[Creating Processes](https://learn.microsoft.com/windows/desktop/ProcThread/creating-processes).

> [!NOTE]
> The processthreadsapi.h header defines CreateProcess as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[ShellExecuteW](https://learn.microsoft.com/windows/win32/api/shellapi/nf-shellapi-shellexecutew)

[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

[CreateProcessWithLogonW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithlogonw)

[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess)

[GetCommandLine](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-getcommandlinea)

[GetEnvironmentStrings](https://learn.microsoft.com/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-initialize)

[GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess)

[GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea)

[GetStartupInfo](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getstartupinfow)

[OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess)

[PROCESS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-process_information)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa)

[STARTUPINFOEX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-startupinfoexa)

[SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode)

[TerminateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminateprocess)

[WaitForInputIdle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitforinputidle)