# LookupPrivilegeValueA function

## Description

The **LookupPrivilegeValue** function retrieves the [locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID) used on a specified system to locally represent the specified privilege name.

## Parameters

### `lpSystemName` [in, optional]

A pointer to a null-terminated string that specifies the name of the system on which the privilege name is retrieved. If a null string is specified, the function attempts to find the privilege name on the local system.

### `lpName` [in]

A pointer to a null-terminated string that specifies the name of the privilege, as defined in the Winnt.h header file. For example, this parameter could specify the constant, SE_SECURITY_NAME, or its corresponding string, "SeSecurityPrivilege".

### `lpLuid` [out]

A pointer to a variable that receives the LUID by which the privilege is known on the system specified by the *lpSystemName* parameter.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **LookupPrivilegeValue** function supports only the privileges specified in the Defined Privileges section of Winnt.h. For a list of values, see [Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/privilege-constants).

#### Examples

For an example that uses this function, see [Enabling and Disabling Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/enabling-and-disabling-privileges-in-c--).

> [!NOTE]
> The winbase.h header defines LookupPrivilegeValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[LookupPrivilegeDisplayName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegedisplaynamea)

[LookupPrivilegeName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegenamea)