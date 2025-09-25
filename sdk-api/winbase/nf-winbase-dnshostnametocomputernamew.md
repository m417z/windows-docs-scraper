# DnsHostnameToComputerNameW function

## Description

Converts a DNS-style host name to a NetBIOS-style computer name.

## Parameters

### `Hostname` [in]

The DNS name. If the DNS name is not a valid, translatable name, the function fails. For more information, see [Computer Names](https://learn.microsoft.com/windows/desktop/SysInfo/computer-names).

### `ComputerName` [out]

A pointer to a buffer that receives the computer name. The buffer size should be large enough to contain MAX_COMPUTERNAME_LENGTH + 1 characters.

### `nSize` [in, out]

On input, specifies the size of the buffer, in **TCHARs**. On output, receives the number of **TCHARs** copied to the destination buffer, not including the terminating null character.

If the buffer is too small, the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_MORE_DATA, and *nSize* receives the required buffer size, not including the terminating null character.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The *ComputerName* buffer is too small. The *nSize* parameter contains the number of bytes required to receive the name. |

## Remarks

This function performs a textual mapping of the name. This convention limits the names of computers to be the common subset of the names. (Specifically, the leftmost label of the DNS name is truncated to 15-bytes of OEM characters.) Therefore, do not use this function to convert a DNS domain name to a NetBIOS domain name. There is no textual mapping for domain names.

To compile an application that uses this function, define _WIN32_WINNT as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> The winbase.h header defines DnsHostnameToComputerName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getcomputernameexa)

[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa)

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)