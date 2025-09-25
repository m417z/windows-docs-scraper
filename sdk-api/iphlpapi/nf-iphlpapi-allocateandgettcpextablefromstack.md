# AllocateAndGetTcpExTableFromStack function

## Description

[This function is no longer available for use as of Windows Vista. Instead, use the
[GetTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable) or [GetExtendedTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedtcptable) function to retrieve the TCP connection table.]

The **AllocateAndGetTcpExTableFromStack** function retrieves the TCP connection table and allocates memory from the local heap to store the table.

## Parameters

### `ppTcpTable` [out]

Pointer to the address of the opaque data that contains the TCP connection table after the function returns.

### `bOrder` [in]

If true, the TCP connection entries in the table returned in *ppTcpTable* are sorted; if false, they are not.

### `hHeap` [in]

Handle to the heap from which the memory to store the table will be allocated.

### `dwFlags` [in]

One or more flags that indicate specific heap allocation control behaviors.

### `dwFamily` [in]

The family of the TCP addresses in the table.

| Value | Meaning |
| --- | --- |
| **AF_INET** | Retrieve IPv4 TCP addresses. |
| **AF_INET6** | Retrieve IPv6 TCP addresses. |

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, it returns a function from winerror.h.

## Remarks

In the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the function prototype for **AllocateAndGetTcpExTableFromStack** is still defined in the Iphlpapi.h header file for continued support on Windows Server 2003 and Windows XP.

## See also

[AllocateAndGetUdpExTableFromStack](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-allocateandgetudpextablefromstack)

[GetExtendedTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedtcptable)

**GetTcpTable**