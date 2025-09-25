# LookupPrivilegeNameW function

## Description

The **LookupPrivilegeName** function retrieves the name that corresponds to the privilege represented on a specific system by a specified [locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID).

## Parameters

### `lpSystemName` [in, optional]

A pointer to a null-terminated string that specifies the name of the system on which the privilege name is retrieved. If a null string is specified, the function attempts to find the privilege name on the local system.

### `lpLuid` [in]

A pointer to the LUID by which the privilege is known on the target system.

### `lpName` [out, optional]

A pointer to a buffer that receives a null-terminated string that represents the privilege name. For example, this string could be "SeSecurityPrivilege".

### `cchName` [in, out]

A pointer to a variable that specifies the size, in a **TCHAR** value, of the *lpName* buffer. When the function returns, this parameter contains the length of the privilege name, not including the terminating null character. If the buffer pointed to by the *lpName* parameter is too small, this variable contains the required size.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **LookupPrivilegeName** function supports only the privileges specified in the Defined Privileges section of Winnt.h. For a list of values, see [Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/privilege-constants).

> [!NOTE]
> The winbase.h header defines LookupPrivilegeName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[LookupPrivilegeDisplayName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegedisplaynamea)

[LookupPrivilegeValue](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegevaluea)