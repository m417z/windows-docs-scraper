# CreateProcessWithTokenW function

## Description

Creates a new process and its primary thread. The new process runs in the security context of the specified token. It can optionally load the user profile for the specified user.

The process that calls **CreateProcessWithTokenW** must have the SE_IMPERSONATE_NAME privilege. If this function fails with ERROR_PRIVILEGE_NOT_HELD (1314), use the [CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) or [CreateProcessWithLogonW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithlogonw) function instead. Typically, the process that calls
**CreateProcessAsUser** must have the SE_INCREASE_QUOTA_NAME privilege and may require the SE_ASSIGNPRIMARYTOKEN_NAME privilege if the token is not assignable. **CreateProcessWithLogonW** requires no special privileges, but the specified user account must be allowed to log on interactively. Generally, it is best to use **CreateProcessWithLogonW** to create a process with alternate credentials.

## Parameters

### `hToken` [in]

A handle to the primary token that represents a user. The handle must have the TOKEN_QUERY, TOKEN_DUPLICATE, and TOKEN_ASSIGN_PRIMARY access rights. For more information, see
[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects). The user represented by the token must have read and execute access to the application specified by the *lpApplicationName* or the *lpCommandLine* parameter.

To get a primary token that represents the specified user, call the
[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function. Alternatively, you can call the
[DuplicateTokenEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex) function to convert an impersonation token into a primary token. This allows a server application that is impersonating a client to create a process that has the security context of the client.

**Terminal Services:** The caller's process always runs in the caller's session, not in the session specified in the token. To run a process in the session specified in the token, use the CreateProcessAsUser function.

### `dwLogonFlags` [in]

The logon option. This parameter can be zero or one of the following values.

| Value | Meaning |
| --- | --- |
| **LOGON_WITH_PROFILE**<br><br>0x00000001 | Log on, then load the user's profile in the **HKEY_USERS** registry key. The function returns after the profile has been loaded. Loading the profile can be time-consuming, so it is best to use this value only if you must access the information in the **HKEY_CURRENT_USER** registry key. <br><br>**Windows Server 2003:** The profile is unloaded after the new process has been terminated, regardless of whether it has created child processes. |
| **LOGON_NETCREDENTIALS_ONLY**<br><br>0x00000002 | Log on, but use the specified credentials on the network only. The new process uses the same token as the caller, but the system creates a new logon session within LSA, and the process uses the specified credentials as the default credentials. <br><br>This value can be used to create a process that uses a different set of credentials locally than it does remotely. This is useful in inter-domain scenarios where there is no trust relationship.<br><br>The system does not validate the specified credentials. Therefore, the process can start, but it may not have access to network resources. |

### `lpApplicationName` [in, optional]

The name of the module to be executed. This module can be a Windows-based application. It can be some other type of module (for example, MS-DOS or OS/2) if the appropriate subsystem is available on the local computer.

The string can specify the full path and file name of the module to execute or it can specify a partial name. In the case of a partial name, the function uses the current drive and current directory to complete the specification. The function will not use the search path. This parameter must include the file name extension; no default extension is assumed.

The *lpApplicationName* parameter can be NULL. In that case, the module name must be the first white space–delimited token in the *lpCommandLine* string. If you are using a long file name that contains a space, use quoted strings to indicate where the file name ends and the arguments begin; otherwise, the file name is ambiguous. For example, consider the string "c:\program files\sub dir\program name". This string can be interpreted in a number of ways. The system tries to interpret the possibilities in the following order:

**c:\program.exe**
**c:\program files\sub.exe**
**c:\program files\sub dir\program.exe**
**c:\program files\sub dir\program name.exe**
If the executable module is a 16-bit application, *lpApplicationName* should be NULL, and the string pointed to by *lpCommandLine* should specify the executable module as well as its arguments.

### `lpCommandLine` [in, out, optional]

The command line to be executed.

The maximum length of this string is 1024 characters. If *lpApplicationName* is NULL, the module name portion of *lpCommandLine* is limited to MAX_PATH characters.

The function can modify the contents of this string. Therefore, this parameter cannot be a pointer to read-only memory (such as a **const** variable or a literal string). If this parameter is a constant string, the function may cause an access violation.

The *lpCommandLine* parameter can be NULL. In that case, the function uses the string pointed to by *lpApplicationName* as the command line.

If both *lpApplicationName* and *lpCommandLine* are non-NULL, **lpApplicationName* specifies the module to execute, and **lpCommandLine* specifies the command line. The new process can use
[GetCommandLine](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-getcommandlinea) to retrieve the entire command line. Console processes written in C can use the *argc* and *argv* arguments to parse the command line. Because argv[0] is the module name, C programmers generally repeat the module name as the first token in the command line.

If *lpApplicationName* is NULL, the first white space–delimited token of the command line specifies the module name. If you are using a long file name that contains a space, use quoted strings to indicate where the file name ends and the arguments begin (see the explanation for the *lpApplicationName* parameter). If the file name does not contain an extension, .exe is appended. Therefore, if the file name extension is .com, this parameter must include the .com extension. If the file name ends in a period (.) with no extension, or if the file name contains a path, .exe is not appended. If the file name does not contain a directory path, the system searches for the executable file in the following sequence:

1. The directory from which the application loaded.
2. The current directory for the parent process.
3. The 32-bit Windows system directory. Use the [GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya) function to get the path of this directory.
4. The 16-bit Windows system directory. There is no function that obtains the path of this directory, but it is searched.
5. The Windows directory. Use the
   [GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya) function to get the path of this directory.
6. The directories that are listed in the PATH environment variable. Note that this function does not search the per-application path specified by the **App Paths** registry key. To include this per-application path in the search sequence, use the [ShellExecute](https://learn.microsoft.com/previous-versions/windows/desktop/axe/shellexecute) function.

The system adds a null character to the command line string to separate the file name from the arguments. This divides the original string into two strings for internal processing.

### `dwCreationFlags` [in]

The flags that control how the process is created. The CREATE_DEFAULT_ERROR_MODE, CREATE_NEW_CONSOLE, and CREATE_NEW_PROCESS_GROUP flags are enabled by default. For a list of values, see [Process Creation Flags](https://learn.microsoft.com/windows/desktop/ProcThread/process-creation-flags).

This parameter also controls the new process's priority class, which is used to determine the scheduling priorities of the process's threads. For a list of values, see
[GetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getpriorityclass). If none of the priority class flags is specified, the priority class defaults to NORMAL_PRIORITY_CLASS unless the priority class of the creating process is IDLE_PRIORITY_CLASS or BELOW_NORMAL_PRIORITY_CLASS. In this case, the child process receives the default priority class of the calling process.

If the dwCreationFlags parameter has a value of 0:

- The process gets the default error mode, creates a new console and creates a new process group.
- The environment block for the new process is assumed to contain ANSI characters (see *lpEnvironment* parameter for additional information).
- A 16-bit Windows-based application runs in a shared Virtual DOS machine (VDM).

### `lpEnvironment` [in, optional]

A pointer to an environment block for the new process. If this parameter is NULL, the new process uses an environment created from the profile of the user specified by *lpUsername*.

An environment block consists of a null-terminated block of null-terminated strings. Each string is in the following form:

*name*=*value*

Because the equal sign (=) is used as a separator, it must not be used in the name of an environment variable.

An environment block can contain Unicode or ANSI characters. If the environment block pointed to by *lpEnvironment* contains Unicode characters, be sure that *dwCreationFlags* includes CREATE_UNICODE_ENVIRONMENT.

An ANSI environment block is terminated by two zero bytes: one for the last string, one more to terminate the block. A Unicode environment block is terminated by four zero bytes: two for the last string and two more to terminate the block.

To retrieve a copy of the environment block for a specific user, use the
[CreateEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createenvironmentblock) function.

### `lpCurrentDirectory` [in, optional]

The full path to the current directory for the process. The string can also specify a UNC path.

If this parameter is NULL, the new process will have the same current drive and directory as the calling process. (This feature is provided primarily for shells that need to start an application and specify its initial drive and working directory.)

### `lpStartupInfo` [in]

A pointer to a
[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) or [STARTUPINFOEX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-startupinfoexa) structure.

If the **lpDesktop** member is NULL or an empty string, the new process inherits the desktop and window station of its parent process. The function adds permission for the specified user account to the inherited window station and desktop. Otherwise, if this member specifies a desktop, it is the responsibility of the application to add permission for the specified user account to the specified window station and desktop, even for WinSta0\Default.

Handles in
[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) or [STARTUPINFOEX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-startupinfoexa) must be closed with
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) when they are no longer needed.

**Important** If the **dwFlags** member of the [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure specifies **STARTF_USESTDHANDLES**, the standard handle fields are copied unchanged to the child process without validation. The caller is responsible for ensuring that these fields contain valid handle values. Incorrect values can cause the child process to misbehave or crash. Use the [Application Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/application-verifier) runtime verification tool to detect invalid handles.

### `lpProcessInformation` [out]

A pointer to a
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) structure that receives identification information for the new process, including a handle to the process.

Handles in
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) must be closed with the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function when they are no longer needed.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Note that the function returns before the process has finished initialization. If a required DLL cannot be located or fails to initialize, the process is terminated. To get the termination status of a process, call [GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess).

## Remarks

By default,
**CreateProcessWithTokenW** does not load the specified user's profile into the **HKEY_USERS** registry key. This means that access to information in the **HKEY_CURRENT_USER** registry key may not produce results consistent with a normal interactive logon. It is your responsibility to load the user's registry hive into **HKEY_USERS** by either using LOGON_WITH_PROFILE, or by calling the
[LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea) function before calling this function.

If the *lpEnvironment* parameter is NULL, the new process uses an environment block created from the profile of the user specified by *lpUserName*. If the HOMEDRIVE and HOMEPATH variables are not set, **CreateProcessWithTokenW** modifies the environment block to use the drive and path of the user's working directory.

When created, the new process and thread handles receive full access rights (PROCESS_ALL_ACCESS and THREAD_ALL_ACCESS). For either handle, if a security descriptor is not provided, the handle can be used in any function that requires an object handle of that type. When a security descriptor is provided, an access check is performed on all subsequent uses of the handle before access is granted. If access is denied, the requesting process cannot use the handle to gain access to the process or thread.

To retrieve a security token, pass the process handle in the
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) structure to the
[OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken) function.

The process is assigned a process identifier. The identifier is valid until the process terminates. It can be used to identify the process, or specified in the
[OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess) function to open a handle to the process. The initial thread in the process is also assigned a thread identifier. It can be specified in the
[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread) function to open a handle to the thread. The identifier is valid until the thread terminates and can be used to uniquely identify the thread within the system. These identifiers are returned in
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information).

The calling thread can use the
[WaitForInputIdle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitforinputidle) function to wait until the new process has finished its initialization and is waiting for user input with no input pending. This can be useful for synchronization between parent and child processes, because
**CreateProcessWithTokenW** returns without waiting for the new process to finish its initialization. For example, the creating process would use
**WaitForInputIdle** before trying to find a window associated with the new process.

The preferred way to shut down a process is by using the
[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess) function, because this function sends notification of approaching termination to all DLLs attached to the process. Other means of shutting down a process do not notify the attached DLLs. Note that when a thread calls
**ExitProcess**, other threads of the process are terminated without an opportunity to execute any additional code (including the thread termination code of attached DLLs). For more information, see
[Terminating a Process](https://learn.microsoft.com/windows/desktop/ProcThread/terminating-a-process).

To compile an application that uses this function, define _WIN32_WINNT as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

### Security Remarks

The *lpApplicationName* parameter can be NULL, in which case the executable name must be the first white space–delimited string in *lpCommandLine*. If the executable or path name has a space in it, there is a risk that a different executable could be run because of the way the function parses spaces. The following example is dangerous because the function will attempt to run "Program.exe", if it exists, instead of "MyApp.exe".

``` syntax
	LPTSTR szCmdline = L"C:\\Program Files\\MyApp";
	CreateProcessWithTokenW(/*...*/, szCmdline, /*...*/);
```

If a malicious user were to create an application called "Program.exe" on a system, any program that incorrectly calls
**CreateProcessWithTokenW** using the Program Files directory will run this application instead of the intended application.

To avoid this problem, do not pass NULL for *lpApplicationName*. If you do pass NULL for *lpApplicationName*, use quotation marks around the executable path in *lpCommandLine*, as shown in the example below.

``` syntax
	LPTSTR szCmdline = L"\"C:\\Program Files\\MyApp\"";
	CreateProcessWithTokenW(/*...*/, szCmdline, /*...*/);
```

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createenvironmentblock)

[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess)

[GetEnvironmentStrings](https://learn.microsoft.com/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-initialize)

[GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess)

[OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess)

[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa)

[SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode)

[WaitForInputIdle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitforinputidle)