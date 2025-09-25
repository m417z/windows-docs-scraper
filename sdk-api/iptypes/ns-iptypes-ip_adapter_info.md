# IP_ADAPTER_INFO structure

## Description

The
**IP_ADAPTER_INFO** structure contains information about a particular network adapter on the local computer.

## Members

### `Next`

Type: **struct _IP_ADAPTER_INFO***

A pointer to the next adapter in the list of adapters.

### `ComboIndex`

Type: **DWORD**

Reserved.

### `AdapterName`

Type: **char[MAX_ADAPTER_NAME_LENGTH + 4]**

An ANSI character string of the name of the adapter.

### `Description`

Type: **char[MAX_ADAPTER_DESCRIPTION_LENGTH + 4]**

An ANSI character string that contains the description of the adapter.

### `AddressLength`

Type: **UINT**

The length, in bytes, of the hardware address for the adapter.

### `Address`

Type: **BYTE[MAX_ADAPTER_ADDRESS_LENGTH]**

The hardware address for the adapter represented as a **BYTE** array.

### `Index`

Type: **DWORD**

The adapter index.

The adapter index may change when an adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

### `Type`

Type: **UINT**

The adapter type. Possible values for the adapter type are listed in the *Ipifcons.h* header file.

The table below lists common values for the adapter type although other values are possible on Windows Vista and later.

| Value | Meaning |
| --- | --- |
| **MIB_IF_TYPE_OTHER**<br><br>1 | Some other type of network interface. |
| **MIB_IF_TYPE_ETHERNET**<br><br>6 | An Ethernet network interface. |
| **IF_TYPE_ISO88025_TOKENRING**<br><br>9 | MIB_IF_TYPE_TOKENRING |
| **MIB_IF_TYPE_PPP**<br><br>23 | A PPP network interface. |
| **MIB_IF_TYPE_LOOPBACK**<br><br>24 | A software loopback network interface. |
| **MIB_IF_TYPE_SLIP**<br><br>28 | An ATM network interface. |
| **IF_TYPE_IEEE80211**<br><br>71 | An IEEE 802.11 wireless network interface.<br><br>**Note** This adapter type is returned on Windows Vista and later. On Windows Server 2003 and Windows XP , an IEEE 802.11 wireless network interface returns an adapter type of **MIB_IF_TYPE_ETHERNET**. |

### `DhcpEnabled`

Type: **UINT**

An option value that specifies whether the dynamic host configuration protocol (DHCP) is enabled for this adapter.

### `CurrentIpAddress`

Type: **PIP_ADDR_STRING**

Reserved.

### `IpAddressList`

Type: **IP_ADDR_STRING**

The list of IPv4 addresses associated with this adapter represented as a linked list of **IP_ADDR_STRING** structures. An adapter can have multiple IPv4 addresses assigned to it.

### `GatewayList`

Type: **IP_ADDR_STRING**

The IPv4 address of the gateway for this adapter represented as a linked list of **IP_ADDR_STRING** structures. An adapter can have multiple IPv4 gateway addresses assigned to it. This list usually contains a single entry for IPv4 address of the default gateway for this adapter.

### `DhcpServer`

Type: **IP_ADDR_STRING**

The IPv4 address of the DHCP server for this adapter represented as a linked list of **IP_ADDR_STRING** structures. This list contains a single entry for the IPv4 address of the DHCP server for this adapter. A value of 255.255.255.255 indicates the DHCP server could not be reached, or is in the process of being reached.

This member is only valid when the **DhcpEnabled** member is nonzero.

### `HaveWins`

Type: **BOOL**

An option value that specifies whether this adapter uses the Windows Internet Name Service (WINS).

### `PrimaryWinsServer`

Type: **IP_ADDR_STRING**

The IPv4 address of the primary WINS server represented as a linked list of **IP_ADDR_STRING** structures. This list contains a single entry for the IPv4 address of the primary WINS server for this adapter.

This member is only valid when the **HaveWins** member is **TRUE**.

### `SecondaryWinsServer`

Type: **IP_ADDR_STRING**

The IPv4 address of the secondary WINS server represented as a linked list of **IP_ADDR_STRING** structures. An adapter can have multiple secondary WINS server addresses assigned to it.

This member is only valid when the **HaveWins** member is **TRUE**.

### `LeaseObtained`

Type: **time_t**

The time when the current DHCP lease was obtained.

This member is only valid when the **DhcpEnabled** member is nonzero.

### `LeaseExpires`

Type: **time_t**

The time when the current DHCP lease expires.

This member is only valid when the **DhcpEnabled** member is nonzero.

## Remarks

The
**IP_ADAPTER_INFO** structure is limited to IPv4 information about a particular network adapter on the local computer. The
**IP_ADAPTER_INFO** structure is retrieved by calling the [GetAdaptersInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersinfo) function.

When using Visual Studio 2005 and later, the **time_t** datatype defaults to an 8-byte datatype, not the 4-byte datatype used for the **LeaseObtained** and **LeaseExpires** members on a 32-bit platform. To properly use the **IP_ADAPTER_INFO** structure on a 32-bit platform, define **_USE_32BIT_TIME_T** (use `-D _USE_32BIT_TIME_T` as an option, for example) when compiling the application to force the **time_t** datatype to a 4-byte datatype.

For use on Windows XP and later, the [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure contains both IPv4 and IPv6 information. The [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function retrieves IPv4 and IPv6 adapter information.

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
                printf("Lookback\n");
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

[GetAdaptersInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersinfo)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh)

[IP_ADDRESS_STRING](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_address_string)

[IP_ADDR_STRING](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_addr_string)