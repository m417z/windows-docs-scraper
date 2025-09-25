# CreateProcessAsUserW function

## Description

Creates a new process and its primary thread. The new process runs in the security context of the user represented by the specified token.

Typically, the process that calls the
**CreateProcessAsUser** function must have the **SE_INCREASE_QUOTA_NAME** privilege and may require the **SE_ASSIGNPRIMARYTOKEN_NAME** privilege if the token is not assignable. If this function fails with **ERROR_PRIVILEGE_NOT_HELD** (1314), use the [CreateProcessWithLogonW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithlogonw) function instead. **CreateProcessWithLogonW** requires no special privileges, but the specified user account must be allowed to log on interactively. Generally, it is best to use **CreateProcessWithLogonW** to create a process with alternate credentials.

## Parameters

### `hToken` [in, optional]

A handle to the primary token that represents a user. The handle must have the **TOKEN_QUERY**, **TOKEN_DUPLICATE**, and **TOKEN_ASSIGN_PRIMARY** access rights. For more information, see
[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects). The user represented by the token must have read and execute access to the application specified by the *lpApplicationName* or the *lpCommandLine* parameter.

To get a primary token that represents the specified user, call the
[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function. Alternatively, you can call the
[DuplicateTokenEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex) function to convert an impersonation token into a primary token. This allows a server application that is impersonating a client to create a process that has the security context of the client.

If *hToken* is a restricted version of the caller's primary token, the **SE_ASSIGNPRIMARYTOKEN_NAME** privilege is not required. If the necessary privileges are not already enabled,
**CreateProcessAsUser** enables them for the duration of the call. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

**Terminal Services:** The process is run in the session specified in the token. By default, this is the same session that called [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera). To change the session, use the
[SetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-settokeninformation) function.

### `lpApplicationName` [in, optional]

The name of the module to be executed. This module can be a Windows-based application. It can be some other type of module (for example, MS-DOS or OS/2) if the appropriate subsystem is available on the local computer.

The string can specify the full path and file name of the module to execute or it can specify a partial name. In the case of a partial name, the function uses the current drive and current directory to complete the specification. The function will not use the search path. This parameter must include the file name extension; no default extension is assumed.

The *lpApplicationName* parameter can be **NULL**. In that case, the module name must be the first white space–delimited token in the *lpCommandLine* string. If you are using a long file name that contains a space, use quoted strings to indicate where the file name ends and the arguments begin; otherwise, the file name is ambiguous. For example, consider the string "c:\program files\sub dir\program name". This string can be interpreted in a number of ways. The system tries to interpret the possibilities in the following order:

**c:\program.exe**
**c:\program files\sub.exe**
**c:\program files\sub dir\program.exe**
**c:\program files\sub dir\program name.exe**
If the executable module is a 16-bit application, *lpApplicationName* should be **NULL**, and the string pointed to by *lpCommandLine* should specify the executable module as well as its arguments. By default, all 16-bit Windows-based applications created by
**CreateProcessAsUser** are run in a separate VDM (equivalent to **CREATE_SEPARATE_WOW_VDM** in
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)).

### `lpCommandLine` [in, out, optional]

The command line to be executed. The maximum length of this string is 32K characters. If *lpApplicationName* is **NULL**, the module name portion of *lpCommandLine* is limited to **MAX_PATH** characters.

The Unicode version of this function, **CreateProcessAsUserW**, can modify the contents of this string. Therefore, this parameter cannot be a pointer to read-only memory (such as a **const** variable or a literal string). If this parameter is a constant string, the function may cause an access violation.

The *lpCommandLine* parameter can be **NULL**. In that case, the function uses the string pointed to by *lpApplicationName* as the command line.

If both *lpApplicationName* and *lpCommandLine* are non-**NULL**, **lpApplicationName* specifies the module to execute, and **lpCommandLine* specifies the command line. The new process can use
[GetCommandLine](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-getcommandlinea) to retrieve the entire command line. Console processes written in C can use the *argc* and *argv* arguments to parse the command line. Because *argv*[0] is the module name, C programmers generally repeat the module name as the first token in the command line.

If *lpApplicationName* is **NULL**, the first white space–delimited token of the command line specifies the module name. If you are using a long file name that contains a space, use quoted strings to indicate where the file name ends and the arguments begin (see the explanation for the *lpApplicationName* parameter). If the file name does not contain an extension, .exe is appended. Therefore, if the file name extension is .com, this parameter must include the .com extension. If the file name ends in a period (.) with no extension, or if the file name contains a path, .exe is not appended. If the file name does not contain a directory path, the system searches for the executable file in the following sequence:

1. The directory from which the application loaded.
2. The current directory for the parent process.
3. The 32-bit Windows system directory. Use the [GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya) function to get the path of this directory.
4. The 16-bit Windows system directory. There is no function that obtains the path of this directory, but it is searched.
5. The Windows directory. Use the
   [GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya) function to get the path of this directory.
6. The directories that are listed in the PATH environment variable. Note that this function does not search the per-application path specified by the **App Paths** registry key. To include this per-application path in the search sequence, use the [ShellExecute](https://learn.microsoft.com/previous-versions/windows/desktop/axe/shellexecute) function.

The system adds a null character to the command line string to separate the file name from the arguments. This divides the original string into two strings for internal processing.

### `lpProcessAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies a security descriptor for the new process object and determines whether child processes can inherit the returned handle to the process. If *lpProcessAttributes* is **NULL** or **lpSecurityDescriptor** is **NULL**, the process gets a default security descriptor and the handle cannot be inherited. The default security descriptor is that of the user referenced in the *hToken* parameter. This security descriptor may not allow access for the caller, in which case the process may not be opened again after it is run. The process handle is valid and will continue to have full access rights.

### `lpThreadAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies a security descriptor for the new thread object and determines whether child processes can inherit the returned handle to the thread. If *lpThreadAttributes* is **NULL** or **lpSecurityDescriptor** is **NULL**, the thread gets a default security descriptor and the handle cannot be inherited. The default security descriptor is that of the user referenced in the *hToken* parameter. This security descriptor may not allow access for the caller.

### `bInheritHandles` [in]

If this parameter is **TRUE**, each inheritable handle in the calling process is inherited by the new process. If the parameter is **FALSE**, the handles are not inherited. Note that inherited handles have the same value and access rights as the original handles.
For additional discussion of inheritable handles, see Remarks.

**Terminal Services:** You cannot inherit handles across sessions. Additionally, if this parameter is **TRUE**, you must create the process in the same session as the caller.

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

A pointer to an [environment block](https://learn.microsoft.com/windows/win32/procthread/environment-variables) for the new process. If this parameter is **NULL**, the new process uses the environment of the calling process.

An environment block consists of a null-terminated block of null-terminated strings. Each string is in the following form:

*name*=*value*\0

Because the equal sign is used as a separator, it must not be used in the name of an environment variable.

An environment block can contain either Unicode or ANSI characters. If the environment block pointed to by *lpEnvironment* contains Unicode characters, be sure that *dwCreationFlags* includes **CREATE_UNICODE_ENVIRONMENT**.

The ANSI version of this function, **CreateProcessAsUserA** fails if the total size of the environment block for the process exceeds 32,767 characters.

Note that an ANSI environment block is terminated by two zero bytes: one for the last string, one more to terminate the block. A Unicode environment block is terminated by four zero bytes: two for the last string, two more to terminate the block.

**Windows Server 2003 and Windows XP:** If the size of the combined user and system environment variable exceeds 8192 bytes, the process created by **CreateProcessAsUser** no longer runs with the environment block passed to the function by the parent process. Instead, the child process runs with the environment block returned by the [CreateEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createenvironmentblock) function.

To retrieve a copy of the environment block for a given user, use the
[CreateEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createenvironmentblock) function.

### `lpCurrentDirectory` [in, optional]

The full path to the current directory for the process. The string can also specify a UNC path.

If this parameter is NULL, the new process will have the same current drive and directory as the calling process. (This feature is provided primarily for shells that need to start an application and specify its initial drive and working directory.)

### `lpStartupInfo` [in]

A pointer to a
[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) or [STARTUPINFOEX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-startupinfoexa) structure.

The user must have full access to both the specified window station and desktop. If you want the process to be interactive, specify winsta0\default. If the **lpDesktop** member is NULL, the new process inherits the desktop and window station of its parent process.
If this member is an empty string, "", the new process connects to a window station using the rules described in [Process Connection to a Window Station](https://learn.microsoft.com/windows/desktop/winstation/process-connection-to-a-window-station).

To set extended attributes, use a [STARTUPINFOEX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-startupinfoexa) structure and specify **EXTENDED_STARTUPINFO_PRESENT** in the *dwCreationFlags* parameter.

Handles in
[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) or [STARTUPINFOEX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-startupinfoexa) must be closed with
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) when they are no longer needed.

**Important** The caller is responsible for ensuring that the standard handle fields in [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) contain valid handle values. These fields are copied unchanged to the child process without validation, even when the **dwFlags** member specifies **STARTF_USESTDHANDLES**. Incorrect values can cause the child process to misbehave or crash. Use the [Application Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/application-verifier) runtime verification tool to detect invalid handles.

### `lpProcessInformation` [out]

A pointer to a
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) structure that receives identification information about the new process.

Handles in
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) must be closed with
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) when they are no longer needed.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Note that the function returns before the process has finished initialization. If a required DLL cannot be located or fails to initialize, the process is terminated. To get the termination status of a process, call [GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess).

## Remarks

**CreateProcessAsUser** must be able to open the primary token of the calling process with the **TOKEN_DUPLICATE** and **TOKEN_IMPERSONATE** access rights.

By default,
**CreateProcessAsUser** creates the new process on a noninteractive window station with a desktop that is not visible and cannot receive user input. To enable user interaction with the new process, you must specify the name of the default interactive window station and desktop, "winsta0\default", in the **lpDesktop** member of the
[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure. In addition, before calling
**CreateProcessAsUser**, you must change the discretionary access control list (DACL) of both the default interactive window station and the default desktop. The DACLs for the window station and desktop must grant access to the user or the logon session represented by the *hToken* parameter.

**CreateProcessAsUser** does not load the specified user's profile into the **HKEY_USERS** registry key. Therefore, to access the information in the **HKEY_CURRENT_USER** registry key, you must load the user's profile information into **HKEY_USERS** with the
[LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea) function before calling
**CreateProcessAsUser**. Be sure to call [UnloadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-unloaduserprofile) after the new process exits.

If the *lpEnvironment* parameter is NULL, the new process inherits the environment of the calling process.
**CreateProcessAsUser** does not automatically modify the environment block to include environment variables specific to the user represented by *hToken*. For example, the USERNAME and USERDOMAIN variables are inherited from the calling process if *lpEnvironment* is NULL. It is your responsibility to prepare the environment block for the new process and specify it in *lpEnvironment*.

The
[CreateProcessWithLogonW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithlogonw) and [CreateProcessWithTokenW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithtokenw) functions are similar to
**CreateProcessAsUser**, except that the caller does not need to call the
[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function to authenticate the user and get a token.

**CreateProcessAsUser** allows you to access the specified directory and executable image in the security context of the caller or the target user. By default,
**CreateProcessAsUser** accesses the directory and executable image in the security context of the caller. In this case, if the caller does not have access to the directory and executable image, the function fails. To access the directory and executable image using the security context of the target user, specify *hToken* in a call to the
[ImpersonateLoggedOnUser](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser) function before calling
**CreateProcessAsUser**.

The process is assigned a process identifier. The identifier is valid until the process terminates. It can be used to identify the process, or specified in the
[OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess) function to open a handle to the process. The initial thread in the process is also assigned a thread identifier. It can be specified in the
[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread) function to open a handle to the thread. The identifier is valid until the thread terminates and can be used to uniquely identify the thread within the system. These identifiers are returned in the
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) structure.

The calling thread can use the
[WaitForInputIdle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitforinputidle) function to wait until the new process has finished its initialization and is waiting for user input with no input pending. This can be useful for synchronization between parent and child processes, because
**CreateProcessAsUser** returns without waiting for the new process to finish its initialization. For example, the creating process would use
**WaitForInputIdle** before trying to find a window associated with the new process.

The preferred way to shut down a process is by using the
[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess) function, because this function sends notification of approaching termination to all DLLs attached to the process. Other means of shutting down a process do not notify the attached DLLs. Note that when a thread calls
**ExitProcess**, other threads of the process are terminated without an opportunity to execute any additional code (including the thread termination code of attached DLLs). For more information, see
[Terminating a Process](https://learn.microsoft.com/windows/desktop/ProcThread/terminating-a-process).

By default, passing **TRUE** as the value of the *bInheritHandles* parameter causes all inheritable handles to be inherited by the new process.
This can be problematic for applications which create processes from multiple threads simultaneously
yet desire each process to inherit different handles.
Applications can use the
[UpdateProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-updateprocthreadattribute) function
with the **PROC_THREAD_ATTRIBUTE_HANDLE_LIST** parameter
to provide a list of handles to be inherited by a particular process.

### Security Remarks

The *lpApplicationName* parameter can be NULL, in which case the executable name must be the first white space–delimited string in *lpCommandLine*. If the executable or path name has a space in it, there is a risk that a different executable could be run because of the way the function parses spaces. The following example is dangerous because the function will attempt to run "Program.exe", if it exists, instead of "MyApp.exe".

``` syntax
    LPTSTR szCmdline[] = _tcsdup(TEXT("C:\\Program Files\\MyApp"));
    CreateProcessAsUser(hToken, NULL, szCmdline, /*...*/ );
```

If a malicious user were to create an application called "Program.exe" on a system, any program that incorrectly calls
**CreateProcessAsUser** using the Program Files directory will run this application instead of the intended application.

To avoid this problem, do not pass NULL for *lpApplicationName*. If you do pass **NULL** for *lpApplicationName*, use quotation marks around the executable path in *lpCommandLine*, as shown in the example below.

``` syntax
    LPTSTR szCmdline[] = _tcsdup(TEXT("\"C:\\Program Files\\MyApp\""));
    CreateProcessAsUser(hToken, NULL, szCmdline, /*...*/);
```

**PowerShell:** When the **CreateProcessAsUser** function is used to implement a cmdlet in PowerShell version 2.0, the cmdlet operates correctly for both fan-in and fan-out remote sessions. Because of certain security scenarios, however, a cmdlet implemented with **CreateProcessAsUser** only operates correctly in PowerShell version 3.0 for fan-in remote sessions; fan-out remote sessions will fail because of insufficient client security privileges. To implement a cmdlet that works for both fan-in and fan-out remote sessions in PowerShell version 3.0, use the [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function.

#### Examples

For an example, see
[Starting an Interactive Client Process](https://learn.microsoft.com/previous-versions/aa379608(v=vs.85)).

> [!NOTE]
> The processthreadsapi.h header defines CreateProcessAsUser as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createenvironmentblock)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateProcessWithLogonW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithlogonw)

[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess)

[GetEnvironmentStrings](https://learn.microsoft.com/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-initialize)

[GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess)

[GetStartupInfo](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getstartupinfow)

[ImpersonateLoggedOnUser](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser)

[LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea)

[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[SHCreateProcessAsUserW](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shcreateprocessasuserw)

[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa)

[STARTUPINFOEX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-startupinfoexa)

[SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode)

[WaitForInputIdle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitforinputidle)