# AddIPAddress function

## Description

The
**AddIPAddress** function adds the specified IPv4 address to the specified adapter.

## Parameters

### `Address` [in]

The IPv4 address to add to the adapter, in the form of an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure.

### `IpMask` [in]

The subnet mask for the IPv4 address specified in the *Address* parameter. The **IPMask** parameter uses the same format as an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure.

### `IfIndex` [in]

The index of the adapter on which to add the IPv4 address.

### `NTEContext` [out]

A pointer to a **ULONG** variable. On successful return, this parameter points to the Net Table Entry (NTE) context for the IPv4 address that was added. The caller can later use this context in a call to
the [DeleteIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipaddress) function.

### `NTEInstance` [out]

A pointer to a **ULONG** variable. On successful return, this parameter points to the NTE instance for the IPv4 address that was added.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_DEV_NOT_EXIST** | The adapter specified by the *IfIndex* parameter does not exist. |
| **ERROR_DUP_DOMAINNAME** | The IPv4 address to add that is specified in the *Address* parameter already exists. |
| **ERROR_GEN_FAILURE** | A general failure. This error is returned for some values specified in the *Address* parameter, such as an IPv4 address normally considered to be a broadcast addresses. |
| **ERROR_INVALID_HANDLE** | The user attempting to make the function call is not an administrator. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is invalid. This error is returned if the *NTEContext* or *NTEInstance* parameters are **NULL**. This error is also returned when the IP address specified in the *Address* parameter is inconsistent with the interface index specified in the *IfIndex* parameter (for example, a loopback address on a non-loopback interface). |
| **ERROR_NOT_SUPPORTED** | The function call is not supported on the version of Windows on which it was run. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **AddIPAddress** function is used to add a new IPv4 address entry on a local computer. The IPv4 address added by
the **AddIPAddress** function is not persistent. The IPv4 address exists only as long as the adapter object exists. Restarting the computer destroys the IPv4 address, as does manually resetting the network interface card (NIC). Also, certain PnP events may destroy the address.

To create an IPv4 address that persists, the [EnableStatic method of the Win32_NetworkAdapterConfiguration Class](https://learn.microsoft.com/windows/desktop/CIMWin32Prov/enablestatic-method-in-class-win32-networkadapterconfiguration) in the Windows Management Instrumentation (WMI) controls may be used. The netsh commands can also be used to create a persistent IPv4 address.

For more information, please see the documentation on [Netsh.exe](https://learn.microsoft.com/windows/desktop/WinSock/netsh-exe) in the Windows Sockets documentation.

On Windows Server 2003, Windows XP, and Windows 2000, if the IPv4 address in the *Address* parameter already exists on the network, the **AddIPAddress** function returns **NO_ERROR** and the IPv4 address added is 0.0.0.0.

On Windows Vista and later, if the IPv4 address passed in the *Address* parameter already exists on the network, the **AddIPAddress** function returns **NO_ERROR** and the duplicate IPv4 address is added with the **IP_DAD_STATE** member in the [IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh) structure set to **IpDadStateDuplicate**.

An IPv4 address that is added using the **AddIPAddress** function can later be deleted by calling the [DeleteIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipaddress) function passing the *NTEContext* parameter returned by the **AddIPAddress** function.

For information about the **IPAddr** and **IPMask** data types, see
[Windows Data Types](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types). To convert an IPv4 address between dotted decimal notation and **IPAddr** format, use the
[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr) and
[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions.

On Windows Vista and later, the [CreateUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry) function can be used to add a new unicast IPv4 or IPv6 address entry on a local computer.

#### Examples

The following example retrieves the IP address table to determine the interface index for the first adapter, then adds the IP address specified on command line to the first adapter. The IP address that was added is then deleted.

```cpp
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int __cdecl main(int argc, char **argv)
{

    /* Variables used by GetIpAddrTable */
    PMIB_IPADDRTABLE pIPAddrTable;
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;
    IN_ADDR IPAddr;
    DWORD ifIndex;

    /* IPv4 address and subnet mask we will be adding */
    UINT iaIPAddress;
    UINT iaIPMask;

    /* Variables where handles to the added IP are returned */
    ULONG NTEContext = 0;
    ULONG NTEInstance = 0;

    /* Variables used to return error message */
    LPVOID lpMsgBuf;

    // Validate the parameters
    if (argc != 3) {
        printf("usage: %s IPAddress SubnetMask\n", argv[0]);
        exit(1);
    }

    iaIPAddress = inet_addr(argv[1]);
    if (iaIPAddress == INADDR_NONE) {
        printf("usage: %s IPAddress SubnetMask\n", argv[0]);
        exit(1);
    }

    iaIPMask = inet_addr(argv[2]);
    if (iaIPMask == INADDR_NONE) {
        printf("usage: %s IPAddress SubnetMask\n", argv[0]);
        exit(1);
    }

    // Before calling AddIPAddress we use GetIpAddrTable to get
    // an adapter to which we can add the IP.
    pIPAddrTable = (MIB_IPADDRTABLE *) MALLOC(sizeof (MIB_IPADDRTABLE));
    if (pIPAddrTable == NULL) {
        printf("Error allocating memory needed to call GetIpAddrTable\n");
        exit (1);
    }
    else {
        dwSize = 0;
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
    if ((dwRetVal = GetIpAddrTable(pIPAddrTable, &dwSize, 0)) == NO_ERROR) {
        // Save the interface index to use for adding an IP address
        ifIndex = pIPAddrTable->table[0].dwIndex;
        printf("\n\tInterface Index:\t%ld\n", ifIndex);
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[0].dwAddr;
        printf("\tIP Address:       \t%s (%lu%)\n", inet_ntoa(IPAddr),
               pIPAddrTable->table[0].dwAddr);
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[0].dwMask;
        printf("\tSubnet Mask:      \t%s (%lu%)\n", inet_ntoa(IPAddr),
               pIPAddrTable->table[0].dwMask);
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[0].dwBCastAddr;
        printf("\tBroadCast Address:\t%s (%lu%)\n", inet_ntoa(IPAddr),
               pIPAddrTable->table[0].dwBCastAddr);
        printf("\tReassembly size:  \t%lu\n\n",
               pIPAddrTable->table[0].dwReasmSize);
    } else {
        printf("Call to GetIpAddrTable failed with error %d.\n", dwRetVal);
        if (pIPAddrTable)
            FREE(pIPAddrTable);
        exit(1);
    }

    if (pIPAddrTable) {
        FREE(pIPAddrTable);
        pIPAddrTable = NULL;
    }

    if ((dwRetVal = AddIPAddress(iaIPAddress,
                                 iaIPMask,
                                 ifIndex,
                                 &NTEContext, &NTEInstance)) == NO_ERROR) {
        printf("\tIPv4 address %s was successfully added.\n", argv[1]);
    } else {
        printf("AddIPAddress failed with error: %d\n", dwRetVal);

        if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, dwRetVal, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),       // Default language
                          (LPTSTR) & lpMsgBuf, 0, NULL)) {
            printf("\tError: %s", lpMsgBuf);
            LocalFree(lpMsgBuf);
            exit(1);
        }
    }

// Delete the IP we just added using the NTEContext
// variable where the handle was returned
    if ((dwRetVal = DeleteIPAddress(NTEContext)) == NO_ERROR) {
        printf("\tIPv4 address %s was successfully deleted.\n", argv[1]);
    } else {
        printf("\tDeleteIPAddress failed with error: %d\n", dwRetVal);
        exit(1);
    }

    exit(0);
}

```

## See also

[CreateUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry)

[DeleteIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipaddress)

[GetAdapterIndex](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadapterindex)

[GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr)