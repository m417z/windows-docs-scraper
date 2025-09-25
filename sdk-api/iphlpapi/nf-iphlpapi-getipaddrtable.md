# GetIpAddrTable function

## Description

The
**GetIpAddrTable** function retrieves the interface–to–IPv4 address mapping table.

## Parameters

### `pIpAddrTable` [out]

A pointer to a buffer that receives the interface–to–IPv4 address mapping table as a
[MIB_IPADDRTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrtable) structure.

### `pdwSize` [in, out]

On input, specifies the size in bytes of the buffer pointed to by the *pIpAddrTable* parameter.

On output, if the buffer is not large enough to hold the returned mapping table, the function sets this parameter equal to the required buffer size in bytes.

### `bOrder` [in]

If this parameter is **TRUE**, then
the returned mapping table
is sorted in ascending order by IPv4 address.
The sorting is performed in network byte order.
For example, 10.0.0.255 comes immediately before 10.0.1.0.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by the *pIpAddrTable* parameter is not large enough. The required size is returned in the **DWORD** variable pointed to by the *pdwSize* parameter. |
| **ERROR_INVALID_PARAMETER** | The *pdwSize* parameter is **NULL**, or [GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable) is unable to write to the memory pointed to by the *pdwSize* parameter. |
| **ERROR_NOT_SUPPORTED** | This function is not supported on the operating system in use on the local system. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetIpAddrTable** function retrieves the interface–to–IPv4 address mapping table on a local computer and returns this information in an [MIB_IPADDRTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrtable) structure.

The IPv4 addresses returned by the **GetIpAddrTable** function are affected by the status of the network interfaces on a local computer. Manually resetting a network interface card (NIC) and certain PnP events may result in an IP address being removed or changed.

On Windows Server 2003 and Windows XP, the IPv4 addresses returned by the **GetIpAddrTable** function are also affected if the media sensing capability of the TCP/IP stack on a local computer has been disabled by calling the [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) function. When media sensing has been disabled, the **GetIpAddrTable** function may return IPv4 addresses associated with disconnected interfaces. These Ipv4 addresses for disconnected interfaces are not valid for use.

On Windows Server 2008 and Windows Vista, the IPv4 addresses returned by the **GetIpAddrTable** function are not affected by the media sensing capability of the TCP/IP stack on a local computer. The **GetIpAddrTable** function returns only valid IPv4 addresses.

The [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function available on Windows XP can be used to retrieve both IPv6 and IPv4 addresses and interface information.

The [MIB_IPADDRTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrtable) structure returned by the **GetIpAddrTable** function may contain padding for alignment between the **dwNumEntries** member and the first [MIB_IPADDRROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrrow_w2k) array entry in the **table** member. Padding for alignment may also be present between the **MIB_IPADDRROW** array entries in the **table** member. Any access to a **MIB_IPADDRROW** array entry should assume padding may exist.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the [MIB_IPADDRROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrrow_w2k) is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

#### Examples

The following example retrieves the IP address table, then prints some members of the IP address entries in the table.

```cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int __cdecl main()
{

    int i;

    /* Variables used by GetIpAddrTable */
    PMIB_IPADDRTABLE pIPAddrTable;
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;
    IN_ADDR IPAddr;

    /* Variables used to return error message */
    LPVOID lpMsgBuf;

    // Before calling AddIPAddress we use GetIpAddrTable to get
    // an adapter to which we can add the IP.
    pIPAddrTable = (MIB_IPADDRTABLE *) MALLOC(sizeof (MIB_IPADDRTABLE));

    if (pIPAddrTable) {
        // Make an initial call to GetIpAddrTable to get the
        // necessary size into the dwSize variable
        if (GetIpAddrTable(pIPAddrTable, &dwSize, 0) ==
            ERROR_INSUFFICIENT_BUFFER) {
            FREE(pIPAddrTable);
            pIPAddrTable = (MIB_IPADDRTABLE *) MALLOC(dwSize);

        }
        if (pIPAddrTable == NULL) {
            printf("Memory allocation failed for GetIpAddrTable\n");
            exit(1);
        }
    }
    // Make a second call to GetIpAddrTable to get the
    // actual data we want
    if ( (dwRetVal = GetIpAddrTable( pIPAddrTable, &dwSize, 0 )) != NO_ERROR ) {
        printf("GetIpAddrTable failed with error %d\n", dwRetVal);
        if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, dwRetVal, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),       // Default language
                          (LPTSTR) & lpMsgBuf, 0, NULL)) {
            printf("\tError: %s", lpMsgBuf);
            LocalFree(lpMsgBuf);
        }
        exit(1);
    }

    printf("\tNum Entries: %ld\n", pIPAddrTable->dwNumEntries);
    for (i=0; i < (int) pIPAddrTable->dwNumEntries; i++) {
        printf("\n\tInterface Index[%d]:\t%ld\n", i, pIPAddrTable->table[i].dwIndex);
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[i].dwAddr;
        printf("\tIP Address[%d]:     \t%s\n", i, inet_ntoa(IPAddr) );
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[i].dwMask;
        printf("\tSubnet Mask[%d]:    \t%s\n", i, inet_ntoa(IPAddr) );
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[i].dwBCastAddr;
        printf("\tBroadCast[%d]:      \t%s (%ld%)\n", i, inet_ntoa(IPAddr), pIPAddrTable->table[i].dwBCastAddr);
        printf("\tReassembly size[%d]:\t%ld\n", i, pIPAddrTable->table[i].dwReasmSize);
        printf("\tType and State[%d]:", i);
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_PRIMARY)
            printf("\tPrimary IP Address");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_DYNAMIC)
            printf("\tDynamic IP Address");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_DISCONNECTED)
            printf("\tAddress is on disconnected interface");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_DELETED)
            printf("\tAddress is being deleted");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_TRANSIENT)
            printf("\tTransient address");
        printf("\n");
    }

    if (pIPAddrTable) {
        FREE(pIPAddrTable);
        pIPAddrTable = NULL;
    }

    exit(0);
}

```

## See also

[AddIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-addipaddress)

[DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense)

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh)

[MIB_IPADDRROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrrow_w2k)

[MIB_IPADDRTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrtable)

[RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense)