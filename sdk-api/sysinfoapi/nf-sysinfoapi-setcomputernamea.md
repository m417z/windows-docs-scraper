# SetComputerNameA function

## Description

Sets a new NetBIOS name for the local computer. The name is stored in the registry and the name change takes effect the next time the user restarts the computer.

If the local computer is a node in a cluster,
**SetComputerName** sets NetBIOS name of the local computer, not that of the cluster virtual server.

To set the DNS host name or the DNS domain name, call the
[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa) function.

## Parameters

### `lpComputerName` [in]

The computer name that will take effect the next time the computer is started. The name must not be longer than MAX_COMPUTERNAME_LENGTH characters.

The standard character set includes letters, numbers, and the following symbols: ! @ # $ % ^ & ' ) ( . - _ { } ~ . If this parameter contains one or more characters that are outside the standard character set,
**SetComputerName** returns ERROR_INVALID_PARAMETER.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Applications using this function must have administrator rights.

> [!NOTE]
> The sysinfoapi.h header defines SetComputerName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Computer Names](https://learn.microsoft.com/windows/desktop/SysInfo/computer-names)

[GetComputerName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcomputernamea)

[GetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getcomputernameexa)

[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa)

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)