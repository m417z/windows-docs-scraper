# FlushIpNetTable2 function

## Description

The
**FlushIpNetTable2** function flushes the IP neighbor table on the local computer.

## Parameters

### `Family` [in]

The address family to flush.

Possible values for the address family are listed in the *Winsock2.h* header file. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and possible values for this member are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET**, **AF_INET6**, and **AF_UNSPEC**.

| Value | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | The address family is unspecified. When this parameter is specified, this function flushes the neighbor IP address table containing both IPv4 and IPv6 entries. |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. When this parameter is specified, this function flushes the neighbor IP address table containing only IPv4 entries. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. When this parameter is specified, this function flushes the neighbor IP address table containing only IPv6 entries. |

### `InterfaceIndex` [in]

The interface index. If the index is specified,
flush the neighbor IP address entries on a specific interface, otherwise flush the
neighbor IP address entries on all the interfaces. To ignore the interface, set this parameter to zero.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *Family* parameter was not specified as **AF_INET**, **AF_INET6**, or **AF_UNSPEC**. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and **AF_INET** was specified in the **Family** parameter. This error is also returned if no IPv6 stack is on the local computer and **AF_INET6** was specified in the **Family** parameter. This error is also returned on versions of Windows where this function is not supported. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **FlushIpNetTable2** function is defined on Windows Vista and later.

The
**FlushIpNetTable2** function flushes or deletes the neighbor IP addresses on a local system. The *Family* parameter can be used to limit neighbor IP addresses to delete to a particular IP address family. If neighbor IP addresses for both IPv4 and IPv6 should be deleted, set the *Family* parameter to **AF_UNSPEC**. The *InterfaceIndex* parameter can be used to limit neighbor IP addresses to delete to a particular interface. If neighbor IP addresses for all interfaces should be deleted, set the *InterfaceIndex* parameter to zero.

The *Family* parameter must be initialized to either **AF_INET**, **AF_INET6**, or **AF_UNSPEC**.

The **FlushIpNetTable2** function can only be called by a user logged on as a member of the Administrators group. If **FlushIpNetTable2** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned. This function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

## See also

[CreateIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipnetentry2)

[DeleteIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipnetentry2)

[GetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnetentry2)

[GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2)

[MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2)

[MIB_IPNET_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_table2)

[ResolveIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-resolveipnetentry2)

[SetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipnetentry2)