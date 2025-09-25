# SetIpStatisticsEx function

## Description

The
**SetIpStatisticsEx** function toggles IP forwarding on or off and sets the default time-to-live (TTL) value for the local computer.

## Parameters

### `Statistics` [in]

A pointer to a
[MIB_IPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipstats_lh) structure. The caller should set the **dwForwarding** and **dwDefaultTTL** members of this structure to the new values. To keep one of the members at its current value, use MIB_USE_CURRENT_TTL or MIB_USE_CURRENT_FORWARDING.

### `Family`

The address family for which forwarding and TTL is to be set.

Possible values for the address family are listed in the *Winsock2.h* header file. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and possible values for this member are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET**, and **AF_INET6**.

| Value | Meaning |
| --- | --- |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. When this parameter is specified, this function sets forwarding and TTL options for IPv4 entries. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. When this parameter is specified, this function sets forwarding and TTL options for IPv6 entries. |

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *pIpStats* parameter or the *Family* parameter was not set to **AF_INET**, and **AF_INET6**. This error is also returned if the **dwForwarding** member in the [MIB_IPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipstats_lh) structure pointed to by the *pIpStats* parameter contains a value other than **MIB_IP_NOT_FORWARDING**, **MIB_IP_FORWARDING**, or **MIB_USE_CURRENT_FORWARDING**. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and AF_INET was specified in the *Family* parameter or no IPv6 stack is on the local computer and AF_INET6 was specified in the *Family* member. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

To set only the default TTL, the caller can also use the
[SetIpTTL](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipttl) function.

The **SetIpStatisticsEx** function can only be called by a user logged on as a member of the Administrators group. If **SetIpStatisticsEx** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned.

The **SetIpStatisticsEx** function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application on lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

## See also

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipstats_lh)

[SetIpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipstatistics)

[SetIpTTL](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipttl)