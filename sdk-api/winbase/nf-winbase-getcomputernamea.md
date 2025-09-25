# GetComputerNameA function

## Description

Retrieves the NetBIOS name of the local computer. This name is established at system startup, when the system reads it from the registry.

**GetComputerName** retrieves only the NetBIOS name of the local computer. To retrieve the DNS host name, DNS domain name, or the fully qualified DNS name, call the
[GetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getcomputernameexa) function. Additional information is provided by the
[IADsADSystemInfo](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsadsysteminfo) interface.

The behavior of this function can be affected if the local computer is a node in a cluster. For more information, see [ResUtilGetEnvironmentWithNetName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetenvironmentwithnetname) and [UseNetworkName](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/generic-applications-usenetworkname).

## Parameters

### `lpBuffer` [out]

A pointer to a buffer that receives the computer name or the cluster virtual server name. The buffer size should be large enough to contain MAX_COMPUTERNAME_LENGTH + 1 characters.

### `nSize` [in, out]

On input, specifies the size of the buffer, in **TCHARs**. On output, the number of **TCHARs** copied to the destination buffer, not including the terminating null character.

If the buffer is too small, the function fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_BUFFER_OVERFLOW. The *lpnSize* parameter specifies the size of the buffer required, including the terminating null character.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**GetComputerName** function retrieves the NetBIOS name established at system startup. Name changes made by the
[SetComputerName](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernamea) or
[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa) functions do not take effect until the user restarts the computer.

If the caller is running under a client session, this function returns the server name. To retrieve the client name, use the [WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa) function.

#### Examples

For an example, see
[Getting System Information](https://learn.microsoft.com/windows/desktop/SysInfo/getting-system-information).

> [!NOTE]
> The winbase.h header defines GetComputerName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Computer Names](https://learn.microsoft.com/windows/desktop/SysInfo/computer-names)

[GetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getcomputernameexa)

[SetComputerName](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernamea)

[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa)

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)