# GetTcp6Table2 function

## Description

The
**GetTcp6Table2** function retrieves the TCP connection table for IPv6.

## Parameters

### `TcpTable` [out]

A pointer to a buffer that receives the TCP connection table for IPv6 as a
[MIB_TCP6TABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table2) structure.

### `SizePointer` [in, out]

On input, specifies the size of the buffer pointed to by the *TcpTable* parameter.

On output, if the buffer is not large enough to hold the returned TCP connection table, the function sets this parameter equal to the required buffer size.

### `Order` [in]

A value that specifies whether the TCP connection table should be sorted. If this parameter is **TRUE**, the table is sorted in ascending order, starting with the lowest local IP address. If this parameter is **FALSE**, the table appears in the order in which they were retrieved.

The following values are compared (as listed) when ordering the TCP endpoints:

1. Local IPv6 address
2. Local scope ID
3. Local port
4. Remote IPv6 address
5. Remote scope ID
6. Remote port

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by the *TcpTable* parameter is not large enough. The required size is returned in the variable pointed to by the *SizePointer* parameter. |
| **ERROR_INVALID_PARAMETER** | The *SizePointer* parameter is **NULL**, or [GetTcp6Table2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table2) is unable to write to the memory pointed to by the *SizePointer* parameter. |
| **ERROR_NOT_SUPPORTED** | This function is not supported on the operating system in use on the local system. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetTcp6Table2** function is defined on Windows Vista and later.

The **GetTcp6Table2** function is an enhanced version of the [GetTcp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table) function that also retrieves information on the TCP offload state of the TCP connection.

## See also

[GetExtendedTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedtcptable)

[GetOwnerModuleFromTcp6Entry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromtcp6entry)

[GetTcp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table)

[GetTcpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatisticsex)

[GetTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable)

[MIB_TCP6ROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row)

[MIB_TCP6ROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row2)

[MIB_TCP6ROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row_owner_module)

[MIB_TCP6ROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row_owner_pid)

[MIB_TCP6TABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table)

[MIB_TCP6TABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table2)

[MIB_TCP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_module)

[MIB_TCP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_pid)