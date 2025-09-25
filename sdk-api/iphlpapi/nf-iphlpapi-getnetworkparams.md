# GetNetworkParams function

## Description

The
**GetNetworkParams** function retrieves network parameters for the local computer.

## Parameters

### `pFixedInfo` [out]

A pointer to a
buffer that contains a [FIXED_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-fixed_info_w2ksp1) structure that receives the network parameters for the local computer, if the function was successful. This buffer must be allocated by the caller prior to calling the **GetNetworkParams** function.

### `pOutBufLen` [in]

A pointer to a **ULONG** variable that specifies the size of the
[FIXED_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-fixed_info_w2ksp1) structure. If this size is insufficient to hold the information,
**GetNetworkParams** fills in this variable with the required size, and returns an error code of **ERROR_BUFFER_OVERFLOW**.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BUFFER_OVERFLOW** | The buffer to receive the network parameter information is too small. This value is returned if the *pOutBufLen* parameter is too small to hold the network parameter information or the *pFixedInfo* parameter was a **NULL** pointer. When this error code is returned, the *pOutBufLen* parameter points to the required buffer size. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *pOutBufLen* parameter is a **NULL** pointer, the calling process does not have read/write access to the memory pointed to by *pOutBufLen*, or the calling process does not have write access to the memory pointed to by the *pFixedInfo* parameter. |
| **ERROR_NO_DATA** | No network parameter information exists for the local computer. |
| **ERROR_NOT_SUPPORTED** | The **GetNetworkParams** function is not supported by the operating system running on the local computer. |
| **Other** | If the function fails, use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetNetworkParams** function is used to retrieve network parameters for the local computer. Network parameters are returned in a [FIXED_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-fixed_info_w2ksp1) structure. The memory for the **FIXED_INFO** structure must be allocated by the application. It is the responsibility of the application to free this memory when it is no longer needed.

In the Microsoft Windows Software Development Kit (SDK), the [FIXED_INFO_WIN2KSP1](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-fixed_info_w2ksp1) structure is defined. When compiling an
application if the target platform is Windows 2000 with Service Pack 1 (SP1) and later (`NTDDI_VERSION >= NTDDI_WIN2KSP1`,
`_WIN32_WINNT >= 0x0501`, or
`WINVER >= 0x0501`), the **FIXED_INFO_WIN2KSP1** struct is typedefed to the **FIXED_INFO** structure. When compiling an application if the target
platform is not Windows 2000 with SP1 and later, the
**FIXED_INFO** structure is undefined.

The **GetNetworkParams** function and the
[FIXED_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-fixed_info_w2ksp1) structure are supported on Windows 98and later. But to build an application for a target platform earlier than Windows 2000 with Service Pack 1 (SP1), an earlier version of the Platform Software Development Kit (SDK) must be used.

#### Examples

The following example retrieves the network parameters for the local computer and prints information from the returned data.

```cpp
//
// Link with IPHlpAPI.lib
//
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "IPHLPAPI.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int __cdecl main()
{

    FIXED_INFO *pFixedInfo;
    ULONG ulOutBufLen;
    DWORD dwRetVal;
    IP_ADDR_STRING *pIPAddr;

    pFixedInfo = (FIXED_INFO *) MALLOC(sizeof (FIXED_INFO));
    if (pFixedInfo == NULL) {
        printf("Error allocating memory needed to call GetNetworkParams\n");
        return 1;
    }
    ulOutBufLen = sizeof (FIXED_INFO);

// Make an initial call to GetAdaptersInfo to get
// the necessary size into the ulOutBufLen variable
    if (GetNetworkParams(pFixedInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
        FREE(pFixedInfo);
        pFixedInfo = (FIXED_INFO *) MALLOC(ulOutBufLen);
        if (pFixedInfo == NULL) {
            printf("Error allocating memory needed to call GetNetworkParams\n");
            return 1;
        }
    }

    if (dwRetVal = GetNetworkParams(pFixedInfo, &ulOutBufLen) == NO_ERROR) {

        printf("Host Name: %s\n", pFixedInfo->HostName);
        printf("Domain Name: %s\n", pFixedInfo->DomainName);

        printf("DNS Servers:\n");
        printf("\t%s\n", pFixedInfo->DnsServerList.IpAddress.String);

        pIPAddr = pFixedInfo->DnsServerList.Next;
        while (pIPAddr) {
            printf("\t%s\n", pIPAddr->IpAddress.String);
            pIPAddr = pIPAddr->Next;
        }

        printf("Node Type: ");
        switch (pFixedInfo->NodeType) {
        case BROADCAST_NODETYPE:
            printf("Broadcast node\n");
            break;
        case PEER_TO_PEER_NODETYPE:
            printf("Peer to Peer node\n");
            break;
        case MIXED_NODETYPE:
            printf("Mixed node\n");
            break;
        case HYBRID_NODETYPE:
            printf("Hybrid node\n");
            break;
        default:
            printf("Unknown node type %0lx\n", pFixedInfo->NodeType);
            break;
        }

        printf("DHCP scope name: %s\n", pFixedInfo->ScopeId);

        if (pFixedInfo->EnableRouting)
            printf("Routing: enabled\n");
        else
            printf("Routing: disabled\n");

        if (pFixedInfo->EnableProxy)
            printf("ARP proxy: enabled\n");
        else
            printf("ARP Proxy: disabled\n");

        if (pFixedInfo->EnableDns)
            printf("DNS: enabled\n");
        else
            printf("DNS: disabled\n");

    } else {
        printf("GetNetworkParams failed with error: %d\n", dwRetVal);
        return 1;
    }

    if (pFixedInfo)
        FREE(pFixedInfo);

    return 0;
}

```

## See also

[FIXED_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-fixed_info_w2ksp1)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)