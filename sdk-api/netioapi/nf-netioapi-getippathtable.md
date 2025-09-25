# GetIpPathTable function

## Description

The
**GetIpPathTable** function retrieves the IP path table on the local computer.

## Parameters

### `Family` [in]

The address family to retrieve.

Possible values for the address family are listed in the *Winsock2.h* header file. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and possible values for this member are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET**, **AF_INET6**, and **AF_UNSPEC**.

| Value | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | The address family is unspecified. When this parameter is specified, this function returns the IP path table containing both IPv4 and IPv6 entries. |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. When this parameter is specified, this function returns the IP path table containing only IPv4 entries. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. When this parameter is specified, this function returns the IP path table containing only IPv6 entries. |

### `Table` [out]

A pointer to a
[MIB_IPPATH_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_table) structure that contains a table of IP path entries on the local computer.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Table* parameter or the *Family* parameter was not specified as **AF_INET**, **AF_INET6**, or **AF_UNSPEC**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **ERROR_NOT_FOUND** | No IP path entries as specified in the *Family* parameter were found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and **AF_INET** was specified in the **Family** parameter. This error is also returned if no IPv6 stack is on the local computer and **AF_INET6** was specified in the **Family** parameter. This error is also returned on versions of Windows where this function is not supported. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetIpPathTable** function is defined on Windows Vista and later.

The
**GetIpPathTable** function enumerates the IP path entries on a local system and returns this information in a [MIB_IPPATH_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_table) structure.

The IP path entries are returned in a [MIB_IPPATH_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_table) structure in the buffer pointed to by the *Table* parameter. The **MIB_IPPATH_TABLE** structure contains an IP path entry count and an array of [MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) structures for each IP path entry. When these returned structures are no longer required, free the memory by calling the [FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable).

The *Family* parameter must be initialized to either **AF_INET**, **AF_INET6**, or **AF_UNSPEC**.

Note that the returned [MIB_IPPATH_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_table) structure pointed to by the *Table* parameter may contain padding for alignment between the **NumEntries** member and the first [MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) array entry in the **Table** member of the **MIB_IPPATH_TABLE** structure. Padding for alignment may also be present between the **MIB_IPPATH_ROW** array entries. Any access to a **MIB_IPPATH_ROW** array entry should assume padding may exist.

## See also

[FlushIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-flushippathtable)

[FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable)

[GetIpPathEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathentry)

[MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row)

[MIB_IPPATH_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_table)