# GetAdaptersInfo function

## Description

The
**GetAdaptersInfo** function retrieves adapter information for the local computer.

**On Windows XP and later:** Use the [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function instead of **GetAdaptersInfo**.

## Parameters

### `AdapterInfo` [out]

A pointer to a buffer that receives a linked list of
[IP_ADAPTER_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_info) structures.

### `SizePointer` [in, out]

A pointer to a **ULONG** variable that specifies the size of the buffer pointed to by the *pAdapterInfo* parameter. If this size is insufficient to hold the adapter information,
**GetAdaptersInfo** fills in this variable with the required size, and returns an error code of **ERROR_BUFFER_OVERFLOW**.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS** (defined to the same value as **NO_ERROR**).

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BUFFER_OVERFLOW** | The buffer to receive the adapter information is too small. This value is returned if the buffer size indicated by the *pOutBufLen* parameter is too small to hold the adapter information or the *pAdapterInfo* parameter was a **NULL** pointer. When this error code is returned, the *pOutBufLen* parameter points to the required buffer size. |
| **ERROR_INVALID_DATA** | Invalid adapter information was retrieved. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. This error is returned if the *pOutBufLen* parameter is a **NULL** pointer, or the calling process does not have read/write access to the memory pointed to by *pOutBufLen* or the calling process does not have write access to the memory pointed to by the *pAdapterInfo* parameter. |
| **ERROR_NO_DATA** | No adapter information exists for the local computer. |
| **ERROR_NOT_SUPPORTED** | The [GetAdaptersInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersinfo) function is not supported by the operating system running on the local computer. |
| **Other** | If the function fails, use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetAdaptersInfo** function can retrieve information only for IPv4 addresses.

In versions prior to Windows 10, the order in which adapters appear in the list returned by this function can be controlled from the Network Connections folder: select the Advanced Settings menu item from the Advanced menu. Starting with Windows 10, the order is unspecified.

The
**GetAdaptersInfo** and
[GetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getinterfaceinfo) functions do not return information about the IPv4 loopback interface. Information on the loopback interface is returned by the [GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable) function.

**On Windows XP and later:** The list of adapters returned by
**GetAdaptersInfo** includes unidirectional adapters. To generate a list of adapters that can both send and receive data, call
[GetUniDirectionalAdapterInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getunidirectionaladapterinfo), and exclude the returned adapters from the list returned by
**GetAdaptersInfo**.

#### Examples

This example retrieves the adapter information and prints various properties of each adapter.

```cpp
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>
#pragma comment(lib, "IPHLPAPI.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int __cdecl main()
{

    /* Declare and initialize variables */

// It is possible for an adapter to have multiple
// IPv4 addresses, gateways, and secondary WINS servers
// assigned to the adapter.
//
// Note that this sample code only prints out the
// first entry for the IP address/mask, and gateway, and
// the primary and secondary WINS server for each adapter.

    PIP_ADAPTER_INFO pAdapterInfo;
    PIP_ADAPTER_INFO pAdapter = NULL;
    DWORD dwRetVal = 0;
    UINT i;

/* variables used to print DHCP time info */
    struct tm newtime;
    char buffer[32];
    errno_t error;

    ULONG ulOutBufLen = sizeof (IP_ADAPTER_INFO);
    pAdapterInfo = (IP_ADAPTER_INFO *) MALLOC(sizeof (IP_ADAPTER_INFO));
    if (pAdapterInfo == NULL) {
        printf("Error allocating memory needed to call GetAdaptersinfo\n");
        return 1;
    }
// Make an initial call to GetAdaptersInfo to get
// the necessary size into the ulOutBufLen variable
    if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
        FREE(pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO *) MALLOC(ulOutBufLen);
        if (pAdapterInfo == NULL) {
            printf("Error allocating memory needed to call GetAdaptersinfo\n");
            return 1;
        }
    }

    if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR) {
        pAdapter = pAdapterInfo;
        while (pAdapter) {
            printf("\tComboIndex: \t%d\n", pAdapter->ComboIndex);
            printf("\tAdapter Name: \t%s\n", pAdapter->AdapterName);
            printf("\tAdapter Desc: \t%s\n", pAdapter->Description);
            printf("\tAdapter Addr: \t");
            for (i = 0; i < pAdapter->AddressLength; i++) {
                if (i == (pAdapter->AddressLength - 1))
                    printf("%.2X\n", (int) pAdapter->Address[i]);
                else
                    printf("%.2X-", (int) pAdapter->Address[i]);
            }
            printf("\tIndex: \t%d\n", pAdapter->Index);
            printf("\tType: \t");
            switch (pAdapter->Type) {
            case MIB_IF_TYPE_OTHER:
                printf("Other\n");
                break;
            case MIB_IF_TYPE_ETHERNET:
                printf("Ethernet\n");
                break;
            case MIB_IF_TYPE_TOKENRING:
                printf("Token Ring\n");
                break;
            case MIB_IF_TYPE_FDDI:
                printf("FDDI\n");
                break;
            case MIB_IF_TYPE_PPP:
                printf("PPP\n");
                break;
            case MIB_IF_TYPE_LOOPBACK:
                printf("Loopback\n");
                break;
            case MIB_IF_TYPE_SLIP:
                printf("Slip\n");
                break;
            default:
                printf("Unknown type %ld\n", pAdapter->Type);
                break;
            }

            printf("\tIP Address: \t%s\n",
                   pAdapter->IpAddressList.IpAddress.String);
            printf("\tIP Mask: \t%s\n", pAdapter->IpAddressList.IpMask.String);

            printf("\tGateway: \t%s\n", pAdapter->GatewayList.IpAddress.String);
            printf("\t***\n");

            if (pAdapter->DhcpEnabled) {
                printf("\tDHCP Enabled: Yes\n");
                printf("\t  DHCP Server: \t%s\n",
                       pAdapter->DhcpServer.IpAddress.String);

                printf("\t  Lease Obtained: ");
                /* Display local time */
                error = _localtime32_s(&newtime, (__time32_t*) &pAdapter->LeaseObtained);
                if (error)
                    printf("Invalid Argument to _localtime32_s\n");
                else {
                    // Convert to an ASCII representation
                    error = asctime_s(buffer, 32, &newtime);
                    if (error)
                        printf("Invalid Argument to asctime_s\n");
                    else
                        /* asctime_s returns the string terminated by \n\0 */
                        printf("%s", buffer);
                }

                printf("\t  Lease Expires:  ");
                error = _localtime32_s(&newtime, (__time32_t*) &pAdapter->LeaseExpires);
                if (error)
                    printf("Invalid Argument to _localtime32_s\n");
                else {
                    // Convert to an ASCII representation
                    error = asctime_s(buffer, 32, &newtime);
                    if (error)
                        printf("Invalid Argument to asctime_s\n");
                    else
                        /* asctime_s returns the string terminated by \n\0 */
                        printf("%s", buffer);
                }
            } else
                printf("\tDHCP Enabled: No\n");

            if (pAdapter->HaveWins) {
                printf("\tHave Wins: Yes\n");
                printf("\t  Primary Wins Server:    %s\n",
                       pAdapter->PrimaryWinsServer.IpAddress.String);
                printf("\t  Secondary Wins Server:  %s\n",
                       pAdapter->SecondaryWinsServer.IpAddress.String);
            } else
                printf("\tHave Wins: No\n");
            pAdapter = pAdapter->Next;
            printf("\n");
        }
    } else {
        printf("GetAdaptersInfo failed with error: %d\n", dwRetVal);

    }
    if (pAdapterInfo)
        FREE(pAdapterInfo);

    return 0;
}

```

## See also

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[GetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getinterfaceinfo)

[GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable)

[GetNumberOfInterfaces](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getnumberofinterfaces)

[GetUniDirectionalAdapterInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getunidirectionaladapterinfo)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP_ADAPTER_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_info)