# GetUdpTable function

## Description

The
**GetUdpTable** function retrieves the IPv4 User Datagram Protocol (UDP) listener table.

## Parameters

### `UdpTable` [out]

A pointer to a buffer that receives the IPv4 UDP listener table as a
[MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable) structure.

### `SizePointer` [in, out]

On input, specifies the size in bytes of the buffer pointed to by the *UdpTable* parameter.

On output, if the buffer is not large enough to hold the returned listener table, the function sets this parameter equal to the required buffer size in bytes.

On the Windows SDK released for Windows Vista and later, the data type for this parameter is changed to a **PULONG** which is equivalent to a **PDWORD**.

### `Order` [in]

A Boolean value that specifies whether the returned UDP listener table should be sorted. If this parameter is **TRUE**, the table is sorted in the order of:

1. Local IP address
2. Local port

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by the *pUdpTable* parameter is not large enough. The required size is returned in the **ULONG** variable pointed to by the *pdwSize* parameter.<br><br>This error is also returned if the *pUdpTable* parameter is **NULL**. |
| **ERROR_INVALID_PARAMETER** | The *pdwSize* parameter is **NULL**, or [GetUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudptable) is unable to write to the memory pointed to by the *pdwSize* parameter. |
| **ERROR_NOT_SUPPORTED** | This function is not supported on the operating system in use on the local system. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

On the Windows SDK released for Windows Vista and later, the return value from the **GetUdpTable** function is changed to a data type of **ULONG** which is equivalent to a **DWORD**.

## See also

[GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable)

[GetOwnerModuleFromUdp6Entry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromudp6entry)

[GetOwnerModuleFromUdpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromudpentry)

[GetUdp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudp6table)

[GetUdpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatistics)

[GetUdpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatisticsex)

[MIB_UDPROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow)

[MIB_UDPROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_module)

[MIB_UDPROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_pid)

[MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable)

[MIB_UDPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_module)

[MIB_UDPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_pid)