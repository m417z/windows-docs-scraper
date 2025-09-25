# LookupPrivilegeDisplayNameW function

## Description

The **LookupPrivilegeDisplayName** function retrieves the display name that represents a specified privilege.

## Parameters

### `lpSystemName` [in, optional]

A pointer to a null-terminated string that specifies the name of the system on which the privilege name is retrieved. If a null string is specified, the function attempts to find the display name on the local system.

### `lpName` [in]

A pointer to a null-terminated string that specifies the name of the privilege, as defined in Winnt.h. For example, this parameter could specify the constant, SE_REMOTE_SHUTDOWN_NAME, or its corresponding string, "SeRemoteShutdownPrivilege". For a list of values, see [Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/privilege-constants).

### `lpDisplayName` [out, optional]

A pointer to a buffer that receives a null-terminated string that specifies the privilege display name. For example, if the *lpName* parameter is SE_REMOTE_SHUTDOWN_NAME, the privilege display name is "Force shutdown from a remote system."

### `cchDisplayName` [in, out]

A pointer to a variable that specifies the size, in **TCHAR**s, of the *lpDisplayName* buffer. When the function returns, this parameter contains the length of the privilege display name, not including the terminating null character. If the buffer pointed to by the *lpDisplayName* parameter is too small, this variable contains the required size.

### `lpLanguageId` [out]

A pointer to a variable that receives the language identifier for the returned display name.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **LookupPrivilegeDisplayName** function retrieves display names only for the privileges specified in the Defined Privileges section of Winnt.h.

> [!NOTE]
> The winbase.h header defines LookupPrivilegeDisplayName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[LookupPrivilegeName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegenamea)

[LookupPrivilegeValue](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegevaluea)