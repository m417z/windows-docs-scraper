# AddLocalAlternateComputerName function

Adds an alternate local network name for the computer from which it is called.

## Parameters

*lpDnsFQHostname* \[in\]

The alternate name to be added. The name must be in the **ComputerNameDnsFullyQualified** format as defined in the [**COMPUTER\_NAME\_FORMAT**](https://learn.microsoft.com/windows/win32/api/sysinfoapi/ne-sysinfoapi-computer_name_format) enumeration, and the [**DnsValidateName\_W**](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsvalidatename) function must be able to validate it with its format set to **DnsNameHostnameFull**.

*ulFlags* \[in\]

This parameter is reserved and must be set to zero.

## Return value

If the function succeeds, the function returns **ERROR\_SUCCESS**. If the function fails, it returns a nonzero error code. Among the error codes that it returns are the following:

| Return code | Description |
|-----------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|
| **ERROR\_INVALID\_PARAMETER** | Indicates that the *lpDnsFQHostname* parameter does not point to a valid DNS name, or that the *ulFlags* parameter is not equal to zero.<br> |
| **ERROR\_NOT\_ENOUGH\_MEMORY** | There is not enough memory to complete the operation.<br> |

## Requirements

| Requirement | Value |
|-----------------------------------|-------------------------------------------------------------------------------------------------------|
| Library<br> | Kernel32.lib |
| DLL<br> | Kernel32.dll |
| Unicode and ANSI names<br> | **AddLocalAlternateComputerNameW** (Unicode) and **AddLocalAlternateComputerNameA** (ANSI)<br> |

## See also

[**COMPUTER\_NAME\_FORMAT**](https://learn.microsoft.com/windows/win32/api/sysinfoapi/ne-sysinfoapi-computer_name_format)

[**DnsValidateName\_W**](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsvalidatename)

