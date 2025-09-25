# CreateProcessWithLogonW function

## Description

Creates a new process and its primary thread. Then the new process runs the specified executable file in the security context of the specified credentials (user, domain, and password). It can optionally load the user profile for a specified user.

This function is similar to the
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) and [CreateProcessWithTokenW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithtokenw) functions, except that the caller does not need to call the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function to authenticate the user and get a token.

## Parameters

### `lpUsername` [in]

The name of the user. This is the name of the user account to log on to. If you use the UPN format, *user*@*DNS_domain_name*, the *lpDomain* parameter must be NULL.

The user account must have the Log On Locally permission on the local computer. This permission is granted to all users on workstations and servers, but only to administrators on domain controllers.

### `lpDomain` [in, optional]

The name of the domain or server whose account database contains the *lpUsername* account. If this parameter is NULL, the user name must be specified in UPN format.

### `lpPassword` [in]

The clear-text password for the *lpUsername* account.

### `dwLogonFlags` [in]

The logon option. This parameter can be 0 (zero) or one of the following values.

| Value | Meaning |
| --- | --- |
| **LOGON_WITH_PROFILE**<br><br>0x00000001 | Log on, then load the user profile in the **HKEY_USERS** registry key. The function returns after the profile is loaded. Loading the profile can be time-consuming, so it is best to use this value only if you must access the information in the **HKEY_CURRENT_USER** registry key. <br><br>**Windows Server 2003:** The profile is unloaded after the new process is terminated, whether or not it has created child processes.<br><br>**Windows XP:** The profile is unloaded after the new process and all child processes it has created are terminated. |
| **LOGON_NETCREDENTIALS_ONLY**<br><br>0x00000002 | Log on, but use the specified credentials on the network only. The new process uses the same token as the caller, but the system creates a new logon session within LSA, and the process uses the specified credentials as the default credentials. <br><br>This value can be used to create a process that uses a different set of credentials locally than it does remotely. This is useful in inter-domain scenarios where there is no trust relationship.<br><br>The system does not validate the specified credentials. Therefore, the process can start, but it may not have access to network resources. |

### `lpApplicationName` [in, optional]

The name of the module to be executed. This module can be a Windows-based application. It can be some other type of module (for example, MS-DOS or OS/2) if the appropriate subsystem is available on the local computer.

The string can specify the full path and file name of the module to execute or it can specify a partial name. If it is a partial name, the function uses the current drive and current directory to complete the specification. The function does not use the search path. This parameter must include the file name extension; no default extension is assumed.

The *lpApplicationName* parameter can be NULL, and the module name must be the first white space–delimited token in the *lpCommandLine* string. If you are using a long file name that contains a space, use quoted strings to indicate where the file name ends and the arguments begin; otherwise, the file name is ambiguous.

For example, the following string can be interpreted in different ways:

"c:\program files\sub dir\program name"

The system tries to interpret the possibilities in the following order:

1. **c:\program.exe** files\sub dir\program name
2. **c:\program files\sub.exe** dir\program name
3. **c:\program files\sub dir\program.exe** name
4. **c:\program files\sub dir\program name.exe**

If the executable module is a 16-bit application, *lpApplicationName* should be NULL, and the string pointed to by *lpCommandLine* should specify the executable module and its arguments.

### `lpCommandLine` [in, out, optional]

The command line to be executed. The maximum length of this string is 1024 characters. If *lpApplicationName* is **NULL**, the module name portion of *lpCommandLine* is limited to **MAX_PATH** characters.

The function can modify the contents of this string. Therefore, this parameter cannot be a pointer to read-only memory (such as a **const** variable or a literal string). If this parameter is a constant string, the function may cause an access violation.

The *lpCommandLine* parameter can be **NULL**, and the function uses the string pointed to by *lpApplicationName* as the command line.

If both *lpApplicationName* and *lpCommandLine* are non-**NULL**, **lpApplicationName* specifies the module to execute, and **lpCommandLine* specifies the command line. The new process can use
[GetCommandLine](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-getcommandlinea) to retrieve the entire command line. Console processes written in C can use the *argc* and *argv* arguments to parse the command line. Because *argv[0]* is the module name, C programmers typically repeat the module name as the first token in the command line.

If *lpApplicationName* is **NULL**, the first white space–delimited token of the command line specifies the module name. If you are using a long file name that contains a space, use quoted strings to indicate where the file name ends and the arguments begin (see the explanation for the *lpApplicationName* parameter). If the file name does not contain an extension, .exe is appended. Therefore, if the file name extension is .com, this parameter must include the .com extension. If the file name ends in a period with no extension, or if the file name contains a path, .exe is not appended. If the file name does not contain a directory path, the system searches for the executable file in the following sequence:

1. The directory from which the application loaded.
2. The current directory for the parent process.
3. The 32-bit Windows system directory. Use the [GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya) function to get the path of this directory.
4. The 16-bit Windows system directory. There is no function that obtains the path of this directory, but it is searched.
5. The Windows directory. Use the
   [GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya) function to get the path of this directory.
6. The directories that are listed in the PATH environment variable. Note that this function does not search the per-application path specified by the **App Paths** registry key. To include this per-application path in the search sequence, use the [ShellExecute](https://learn.microsoft.com/windows/win32/api/shellapi/nf-shellapi-shellexecutew) function.

The system adds a null character to the command line string to separate the file name from the arguments. This divides the original string into two strings for internal processing.

### `dwCreationFlags` [in]

The flags that control how the process is created. The **CREATE_DEFAULT_ERROR_MODE**, **CREATE_NEW_CONSOLE**, and **CREATE_NEW_PROCESS_GROUP** flags are enabled by default. For a list of values, see [Process Creation Flags](https://learn.microsoft.com/windows/desktop/ProcThread/process-creation-flags).

This parameter also controls the new process's priority class, which is used to determine the scheduling priorities of the process's threads. For a list of values, see
[GetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getpriorityclass). If none of the priority class flags is specified, the priority class defaults to **NORMAL_PRIORITY_CLASS** unless the priority class of the creating process is **IDLE_PRIORITY_CLASS** or **BELOW_NORMAL_PRIORITY_CLASS**. In this case, the child process receives the default priority class of the calling process.

If the dwCreationFlags parameter has a value of 0:

- The process gets the default error mode, creates a new console and creates a new process group.
- The environment block for the new process is assumed to contain ANSI characters (see *lpEnvironment* parameter for additional information).
- A 16-bit Windows-based application runs in a shared Virtual DOS machine (VDM).

### `lpEnvironment` [in, optional]

A pointer to an environment block for the new process. If this parameter is **NULL**, the new process uses an environment created from the profile of the user specified by *lpUsername*.

An environment block consists of a null-terminated block of null-terminated strings. Each string is in the following form:

*name*=*value*

Because the equal sign (=) is used as a separator, it must not be used in the name of an environment variable.

An environment block can contain Unicode or ANSI characters. If the environment block pointed to by *lpEnvironment* contains Unicode characters, ensure that *dwCreationFlags* includes **CREATE_UNICODE_ENVIRONMENT**.

An ANSI environment block is terminated by two 0 (zero) bytes: one for the last string and one more to terminate the block. A Unicode environment block is terminated by four zero bytes: two for the last string and two more to terminate the block.

To retrieve a copy of the environment block for a specific user, use the
[CreateEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createenvironmentblock) function.

### `lpCurrentDirectory` [in, optional]

The full path to the current directory for the process. The string can also specify a UNC path.

If this parameter is **NULL**, the new process has the same current drive and directory as the calling process. This feature is provided primarily for shells that need to start an application, and specify its initial drive and working directory.

### `lpStartupInfo` [in]

A pointer to a
[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure.

The application must add permission for the specified user account to the specified window station and desktop, even for WinSta0\Default.

If the **lpDesktop** member is **NULL** or an empty string, the new process inherits the desktop and window station of its parent process.
The application must add permission for the specified user account to the inherited window station and desktop.

**Windows XP:** **CreateProcessWithLogonW** adds permission for the specified user account to the inherited window station and desktop.

Handles in
[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) must be closed with
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) when they are no longer needed.

**Important** If the **dwFlags** member of the [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure specifies **STARTF_USESTDHANDLES**, the standard handle fields are copied unchanged to the child process without validation. The caller is responsible for ensuring that these fields contain valid handle values. Incorrect values can cause the child process to misbehave or crash. Use the [Application Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/application-verifier) runtime verification tool to detect invalid handles.

### `lpProcessInformation` [out]

A pointer to a
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) structure that receives identification information for the new process, including a handle to the process.

Handles in
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) must be closed with the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function when they are not needed.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Note that the function returns before the process has finished initialization. If a required DLL cannot be located or fails to initialize, the process is terminated. To get the termination status of a process, call [GetExitCodeProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess).

## Remarks

By default,
**CreateProcessWithLogonW** does not load the specified user profile into the **HKEY_USERS** registry key. This means that access to information in the **HKEY_CURRENT_USER** registry key may not produce results that are consistent with a normal interactive logon. It is your responsibility to load the user registry hive into **HKEY_USERS** before calling
**CreateProcessWithLogonW**, by using **LOGON_WITH_PROFILE**, or by calling the
[LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea) function.

If the *lpEnvironment* parameter is NULL, the new process uses an environment block created from the profile of the user specified by *lpUserName*. If the HOMEDRIVE and HOMEPATH variables are not set, **CreateProcessWithLogonW** modifies the environment block to use the drive and path of the user's working directory.

When created, the new process and thread handles receive full access rights (**PROCESS_ALL_ACCESS** and **THREAD_ALL_ACCESS**). For either handle, if a security descriptor is not provided, the handle can be used in any function that requires an object handle of that type. When a security descriptor is provided, an access check is performed on all subsequent uses of the handle before access is granted. If access is denied, the requesting process cannot use the handle to gain access to the process or thread.

To retrieve a security token, pass the process handle in the
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) structure to the
[OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken) function.

The process is assigned a process identifier. The identifier is valid until the process terminates. It can be used to identify the process, or it can be specified in the
[OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess) function to open a handle to the process. The initial thread in the process is also assigned a thread identifier. It can be specified in the
[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread) function to open a handle to the thread. The identifier is valid until the thread terminates and can be used to uniquely identify the thread within the system. These identifiers are returned in
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information).

The calling thread can use the
[WaitForInputIdle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitforinputidle) function to wait until the new process has completed its initialization and is waiting for user input with no input pending. This can be useful for synchronization between parent and child processes, because
**CreateProcessWithLogonW** returns without waiting for the new process to finish its initialization. For example, the creating process would use
**WaitForInputIdle** before trying to find a window that is associated with the new process.

The preferred way to shut down a process is by using the
[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess) function, because this function sends notification of approaching termination to all DLLs attached to the process. Other means of shutting down a process do not notify the attached DLLs. Note that when a thread calls
**ExitProcess**, other threads of the process are terminated without an opportunity to execute any additional code (including the thread termination code of attached DLLs). For more information, see
[Terminating a Process](https://learn.microsoft.com/windows/desktop/ProcThread/terminating-a-process).

**CreateProcessWithLogonW** accesses the specified directory and executable image in the security context of the target user. If the executable image is on a network and a network drive letter is specified in the path, the network drive letter is not available to the target user, as network drive letters can be assigned for each logon. If a network drive letter is specified, this function fails. If the executable image is on a network, use the UNC path.

There is a limit to the number of child processes that can be created by this function and run simultaneously. For example, on Windows XP, this limit is **MAXIMUM_WAIT_OBJECTS***4. However, you may not be able to create this many processes due to system-wide quota limits.

**Windows XP with SP2,Windows Server 2003, or later:** You cannot call **CreateProcessWithLogonW** from a process that is running under the "LocalSystem" account, because the function uses the logon SID in the caller token, and the token for the "LocalSystem" account does not contain this SID. As an alternative, use the [CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) and [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) functions.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

### Security Remarks

The *lpApplicationName* parameter can be **NULL**, and the executable name must be the first white space–delimited string in *lpCommandLine*. If the executable or path name has a space in it, there is a risk that a different executable could be run because of the way the function parses spaces. Avoid the following example, because the function attempts to run "Program.exe", if it exists, instead of "MyApp.exe".

``` syntax
LPTSTR szCmdline[]=_tcsdup(TEXT("C:\\Program Files\\MyApp"));
CreateProcessWithLogonW(..., szCmdline, ...)
```

If a malicious user creates an application called "Program.exe" on a system, any program that incorrectly calls
**CreateProcessWithLogonW** using the Program Files directory runs the malicious user application instead of the intended application.

To avoid this issue, do not pass **NULL** for *lpApplicationName*. If you pass **NULL** for *lpApplicationName*, use quotation marks around the executable path in *lpCommandLine*, as shown in the following example:

``` syntax
LPTSTR szCmdline[]=_tcsdup(TEXT("\"C:\\Program Files\\MyApp\""));
CreateProcessWithLogonW(..., szCmdline, ...)
```

#### Examples

The following example demonstrates how to call this function.

```cpp

#include <windows.h>
#include <stdio.h>
#include <userenv.h>

void DisplayError(LPWSTR pszAPI)
{
    LPVOID lpvMessageBuffer;

    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, GetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPWSTR)&lpvMessageBuffer, 0, NULL);

    //
    //... now display this string
    //
    wprintf(L"ERROR: API        = %s.\n", pszAPI);
    wprintf(L"       error code = %d.\n", GetLastError());
    wprintf(L"       message    = %s.\n", (LPWSTR)lpvMessageBuffer);

    //
    // Free the buffer allocated by the system
    //
    LocalFree(lpvMessageBuffer);

    ExitProcess(GetLastError());
}

void wmain(int argc, WCHAR *argv[])
{
    DWORD     dwSize;
    HANDLE    hToken;
    LPVOID    lpvEnv;
    PROCESS_INFORMATION pi = {0};
    STARTUPINFO         si = {0};
    WCHAR               szUserProfile[256] = L"";

    si.cb = sizeof(STARTUPINFO);

    if (argc != 4)
    {
        wprintf(L"Usage: %s [user@domain] [password] [cmd]", argv[0]);
        wprintf(L"\n\n");
        return;
    }

    //
    // TO DO: change NULL to '.' to use local account database
    //
    if (!LogonUser(argv[1], NULL, argv[2], LOGON32_LOGON_INTERACTIVE,
            LOGON32_PROVIDER_DEFAULT, &hToken))
        DisplayError(L"LogonUser");

    if (!CreateEnvironmentBlock(&lpvEnv, hToken, TRUE))
        DisplayError(L"CreateEnvironmentBlock");

    dwSize = sizeof(szUserProfile)/sizeof(WCHAR);

    if (!GetUserProfileDirectory(hToken, szUserProfile, &dwSize))
        DisplayError(L"GetUserProfileDirectory");

    //
    // TO DO: change NULL to '.' to use local account database
    //
    if (!CreateProcessWithLogonW(argv[1], NULL, argv[2],
            LOGON_WITH_PROFILE, NULL, argv[3],
            CREATE_UNICODE_ENVIRONMENT, lpvEnv, szUserProfile,
            &si, &pi))
        DisplayError(L"CreateProcessWithLogonW");

    if (!DestroyEnvironmentBlock(lpvEnv))
        DisplayError(L"DestroyEnvironmentBlock");

    CloseHandle(hToken);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

```

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createenvironmentblock)

[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

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