# GetIpNetTable function

## Description

The
**GetIpNetTable** function retrieves the IPv4 to physical address mapping table.

## Parameters

### `IpNetTable` [out]

A pointer to a buffer that receives the IPv4 to physical address mapping table as a
[MIB_IPNETTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnettable) structure.

### `SizePointer` [in, out]

On input, specifies the size in bytes of the buffer pointed to by the *pIpNetTable* parameter.

On output, if the buffer is not large enough to hold the returned mapping table, the function sets this parameter equal to the required buffer size in bytes.

### `Order` [in]

A Boolean value that specifies whether the returned mapping table should be sorted in ascending order by IP address. If this parameter is **TRUE**, the table is sorted.

## Return value

If the function succeeds, the return value is NO_ERROR or ERROR_NO_DATA.

If the function fails or does not return any data, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by the *pIpNetTable* parameter is not large enough. The required size is returned in the **DWORD** variable pointed to by the *pdwSize* parameter. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *pdwSize* parameter is **NULL**, or [GetIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipnettable) is unable to write to the memory pointed to by the *pdwSize* parameter. |
| **ERROR_NO_DATA** | There is no data to return. The IPv4 to physical address mapping table is empty. This return value indicates that the call to the [GetIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipnettable) function succeeded, but there was no data to return. |
| **ERROR_NOT_SUPPORTED** | The IPv4 transport is not configured on the local computer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The
**GetIpNetTable** function enumerates the Address Resolution Protocol (ARP) entries for IPv4 on a local system from the IPv4 to physical address mapping table and returns this information in a [MIB_IPNETTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnettable) structure.

The IPv4 address entries are returned in a [MIB_IPNETTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnettable) structure in the buffer pointed to by the *pIpNetTable* parameter. The **MIB_IPNETTABLE** structure contains a count of ARP entries and an array of [MIB_IPNETROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnetrow_lh) structures for each IPv4 address entry.

Note that the returned [MIB_IPNETTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnettable) structure pointed to by the *pIpNetTable* parameter may contain padding for alignment between the **dwNumEntries** member and the first [MIB_IPNETROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnetrow_lh) array entry in the **table** member of the **MIB_IPNETTABLE** structure. Padding for alignment may also be present between the **MIB_IPNETROW** array entries. Any access to a **MIB_IPNETROW** array entry should assume padding may exist.

 on Windows Vista and later, the [GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2) function can be used to retrieve the neighbor IP addresses for both IPv6 and IPv4.

## See also

[CreateIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipnetentry)

[DeleteIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipnetentry)

[FlushIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-flushipnettable)

[GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IPNETROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnetrow_lh)

[MIB_IPNETTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnettable)

[SetIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipnetentry)