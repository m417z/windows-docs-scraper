# AllocateAndGetUdpExTableFromStack function

## Description

[This function is no longer available for use as of Windows Vista. Instead, use the [GetUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudptable) or [GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable) function to retrieve the UDP connection table.]

The **AllocateAndGetUdpExTableFromStack** function retrieves the UDP connection table and allocates memory from the local heap to store the table.

## Parameters

### `ppUdpTable` [out]

Pointer to the address of the opaque data that contains the UDP connection table after the function returns.

### `bOrder` [in]

If true, the UDP connection entries in the table returned in *ppUDPTable* are sorted; if false, they are not.

### `hHeap` [in]

Handle to the heap from which the memory to store the table will be allocated.

### `dwFlags` [in]

One or more flags that indicate specific heap allocation control behaviors.

### `dwFamily` [in]

The family of the UDP addresses in the table.

| Value | Meaning |
| --- | --- |
| **AF_INET** | Retrieve IPv4 UDP addresses. |
| **AF_INET6** | Retrieve IPv6 UDP addresses. |

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, it returns a function from winerror.h.

## Remarks

In the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the function prototype for **AllocateAndGetUdpExTableFromStack** is still defined in the Iphlpapi.h header file for continued support on Windows Server 2003 and Windows XP.

## See also

[AllocateAndGetTcpExTableFromStack](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-allocateandgettcpextablefromstack)

[GetExtendedUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedudptable)

[GetUdpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudptable)