# CreateIpForwardEntry function

## Description

The
**CreateIpForwardEntry** function creates a route in the local computer's IPv4 routing table.

## Parameters

### `pRoute` [in]

A pointer to a
[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure that specifies the information for the new route. The caller must specify values for all members of this structure. The caller must specify **MIB_IPPROTO_NETMGMT** for the **dwForwardProto** member of
**MIB_IPFORWARDROW**.

## Return value

The function returns **NO_ERROR** (zero) if the function is successful.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned on Windows Vista and Windows Server 2008 under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An input parameter is invalid, no action was taken. This error is returned if the *pRoute* parameter is **NULL**, the **dwForwardProto** member of [MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) was not set to **MIB_IPPROTO_NETMGMT**, the **dwForwardMask** member of the **PMIB_IPFORWARDROW** structure is not a valid IPv4 subnet mask, or one of the other members of the **MIB_IPFORWARDROW** structure is invalid. |
| **ERROR_NOT_SUPPORTED** | The IPv4 transport is not configured on the local computer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **dwForwardProto** member of
[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure pointed to by the *route* parameter must be set to **MIB_IPPROTO_NETMGMT** otherwise **CreateIpForwardEntry** will fail. Routing protocol identifiers are used to identify route information for the specified routing protocol. For example, **MIB_IPPROTO_NETMGMT** is used to identify route information for IP routing set through network management such as the Dynamic Host Configuration Protocol (DHCP), the Simple Network Management Protocol (SNMP), or by calls to the **CreateIpForwardEntry**, [DeleteIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipforwardentry), or [SetIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipforwardentry) functions.

On Windows Vista and Windows Server 2008, the route metric specified in the **dwForwardMetric1** member of the [MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure pointed to by *pRoute* parameter represents a combination of the route metric added to the interface metric specified in the **Metric** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure of the associated interface. So the **dwForwardMetric1** member of the **MIB_IPFORWARDROW** structure should be equal to or greater than **Metric** member of the associated **MIB_IPINTERFACE_ROW** structure. If an application would like to set the route metric to 0, then the **dwForwardMetric1** member of the **MIB_IPFORWARDROW** structure should be set equal to the value of the interface metric specified in the **Metric** member of the associated **MIB_IPINTERFACE_ROW** structure. An application can retrieve the interface metric by calling the [GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry) function.

On Windows Vista and Windows Server 2008, the **CreateIpForwardEntry** only works on interfaces with a single sub-interface (where the interface LUID and subinterface LUID are the same). The **dwForwardIfIndex** member of the [MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure specifies the interface.

A number of members of the [MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure pointed to by the *route* parameter are not currently used by **CreateIpForwardEntry**. These members include **dwForwardPolicy**, **dwForwardType**, **dwForwardAge**, **dwForwardNextHopAS**, **dwForwardMetric2**, **dwForwardMetric3**, **dwForwardMetric4**, and **dwForwardMetric5**.

A new route created by **CreateIpForwardEntry** will automatically have a default value for **dwForwardAge** of INFINITE.

To modify an existing route in the IPv4 routing table, use the
[SetIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipforwardentry) function. To retrieve the IPv4 routing table, call the [GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable) function.

On Windows Vista and later, the **CreateIpForwardEntry** function can only be called by a user logged on as a member of the Administrators group. If **CreateIpForwardEntry** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned.

The **CreateIpForwardEntry** function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

**Note** On Windows NT 4.0 and Windows 2000 and later, this function executes a privileged operation. For this function to execute successfully, the caller must be logged on as a member of the Administrators group or the NetworkConfigurationOperators group.

#### Examples

The following example demonstrates how to change the default gateway to NewGateway. Simply calling GetIpForwardTable, changing the gateway, and then calling SetIpForwardEntry will not change the route, but rather will just add a new one. If for some reason there are multiple default gateways present, this code will delete them. Note that the new gateway must be viable; otherwise, TCP/IP will ignore the change.

**Note** Executing this code will change your IP routing tables and will likely cause network activity to fail.

```cpp
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "iphlpapi.lib")

int main()
{
    // Declare and initialize variables

    PMIB_IPFORWARDTABLE pIpForwardTable = NULL;
    PMIB_IPFORWARDROW pRow = NULL;
    DWORD dwSize = 0;
    BOOL bOrder = FALSE;
    DWORD dwStatus = 0;
    DWORD NewGateway = 0xDDCCBBAA;  // this is in host order Ip Address AA.BB.CC.DD is DDCCBBAA

    unsigned int i;

// Find out how big our buffer needs to be.
    dwStatus = GetIpForwardTable(pIpForwardTable, &dwSize, bOrder);
    if (dwStatus == ERROR_INSUFFICIENT_BUFFER) {
        // Allocate the memory for the table
        if (!(pIpForwardTable = (PMIB_IPFORWARDTABLE) malloc(dwSize))) {
            printf("Malloc failed. Out of memory.\n");
            exit(1);
        }
        // Now get the table.
        dwStatus = GetIpForwardTable(pIpForwardTable, &dwSize, bOrder);
    }

    if (dwStatus != ERROR_SUCCESS) {
        printf("getIpForwardTable failed.\n");
        if (pIpForwardTable)
            free(pIpForwardTable);
        exit(1);
    }
    // Search for the row in the table we want. The default gateway has a destination
    // of 0.0.0.0. Notice that we continue looking through the table, but copy only
    // one row. This is so that if there happen to be multiple default gateways, we can
    // be sure to delete them all.
    for (i = 0; i < pIpForwardTable->dwNumEntries; i++) {
        if (pIpForwardTable->table[i].dwForwardDest == 0) {
            // We have found the default gateway.
            if (!pRow) {
                // Allocate some memory to store the row in; this is easier than filling
                // in the row structure ourselves, and we can be sure we change only the
                // gateway address.
                pRow = (PMIB_IPFORWARDROW) malloc(sizeof (MIB_IPFORWARDROW));
                if (!pRow) {
                    printf("Malloc failed. Out of memory.\n");
                    exit(1);
                }
                // Copy the row
                memcpy(pRow, &(pIpForwardTable->table[i]),
                       sizeof (MIB_IPFORWARDROW));
            }
            // Delete the old default gateway entry.
            dwStatus = DeleteIpForwardEntry(&(pIpForwardTable->table[i]));

            if (dwStatus != ERROR_SUCCESS) {
                printf("Could not delete old gateway\n");
                exit(1);
            }
        }
    }

    // Set the nexthop field to our new gateway - all the other properties of the route will
    // be the same as they were previously.
    pRow->dwForwardNextHop = NewGateway;

    // Create a new route entry for the default gateway.
    dwStatus = CreateIpForwardEntry(pRow);

    if (dwStatus == NO_ERROR)
        printf("Gateway changed successfully\n");
    else if (dwStatus == ERROR_INVALID_PARAMETER)
        printf("Invalid parameter.\n");
    else
        printf("Error: %d\n", dwStatus);

    // Free resources
    if (pIpForwardTable)
        free(pIpForwardTable);
    if (pRow)
        free(pRow);

    exit(0);
}

```

## See also

[DeleteIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipforwardentry)

[GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable)

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[IP Helper
Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper
Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow)

[SetIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipforwardentry)