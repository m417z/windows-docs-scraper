# GetUdp6Table function

## Description

The
**GetUdp6Table** function retrieves the IPv6 User Datagram Protocol (UDP) listener table.

## Parameters

### `Udp6Table` [out]

A pointer to a buffer that receives the IPv6 UDP listener table as a
[MIB_UDP6TABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table) structure.

### `SizePointer` [in, out]

On input, specifies the size in bytes of the buffer pointed to by the *Udp6Table* parameter.

On output, if the buffer is not large enough to hold the returned listener table, the function sets this parameter equal to the required buffer size in bytes.

### `Order` [in]

A Boolean value that specifies whether the returned UDP listener table should be sorted. If this parameter is **TRUE**, the table is sorted in the order of:

1. Local IPv6 address
2. Local scope ID
3. Local port

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by the *Udp6Table* parameter is not large enough. The required size is returned in the **ULONG** variable pointed to by the *SizePointer* parameter. |
| **ERROR_INVALID_PARAMETER** | The *SizePointer* parameter is **NULL**, or [GetUdp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudp6table) is unable to write to the memory pointed to by the *SizePointer* parameter. |
| **ERROR_NOT_SUPPORTED** | This function is not supported on the operating system in use on the local system. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetUdp6Table** function is defined on Windows Vista and later.

## See also

[GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable)

[GetOwnerModuleFromUdp6Entry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromudp6entry)

[GetOwnerModuleFromUdpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromudpentry)

[GetUdp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudp6table)

[GetUdpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatistics)

[GetUdpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatisticsex)

[MIB_UDP6ROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row)

[MIB_UDP6ROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row_owner_module)

[MIB_UDP6ROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6row_owner_pid)

[MIB_UDP6TABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table)

[MIB_UDP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_module)

[MIB_UDP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_pid)

[MIB_UDPROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow)

[MIB_UDPROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_module)

[MIB_UDPROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow_owner_pid)

[MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable)

[MIB_UDPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_module)

[MIB_UDPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_pid)