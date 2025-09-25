# DeleteIpForwardEntry function

## Description

The
**DeleteIpForwardEntry** function deletes an existing route in the local computer's IPv4 routing table.

## Parameters

### `pRoute` [in]

A pointer to an
[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure. This structure specifies information that identifies the route to delete. The caller must specify values for the **dwForwardIfIndex**, **dwForwardDest**, **dwForwardMask**, **dwForwardNextHop**, and **dwForwardProto** members of the structure.

## Return value

The function returns **NO_ERROR** (zero) if the routine is successful.

If the function fails, the return value is one of the following error codes.

| Error code | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned on Windows Vista and Windows Server 2008 under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An input parameter is invalid, no action was taken. This error is returned if the **pRoute** parameter is **NULL**, the **dwForwardMask** member of the [PMIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure is not a valid IPv4 subnet mask, the **dwForwardIfIndex** member is **NULL**, or one of the other members of the **MIB_IPFORWARDROW** structure is invalid. |
| **ERROR_NOT_FOUND** | The **pRoute** parameter points to a route entry that does not exist. |
| **ERROR_NOT_SUPPORTED** | The IPv4 transport is not configured on the local computer. |
| **(other)** | The function may return other error codes. |

If the function fails, use
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error.

## Remarks

The **dwForwardProto** member of
[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure pointer to by the *route* parameter must be set to **MIB_IPPROTO_NETMGMT** otherwise **DeleteIpForwardEntry** will fail. Routing protocol identifiers are used to identify route information for the specified routing protocol. For example, **MIB_IPPROTO_NETMGMT** is used to identify route information for IP routing set through network management such as the Dynamic Host Configuration Protocol (DHCP), the Simple Network Management Protocol (SNMP), or by calls to the [CreateIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipforwardentry), **DeleteIpForwardEntry**
, or [SetIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipforwardentry) functions.

On Windows Vista and Windows Server 2008, the **DeleteIpForwardEntry** only works on interfaces with a single sub-interface (where the interface LUID and subinterface LUID are the same). The **dwForwardIfIndex** member of the [MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure specifies the interface.

A number of members of the [MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure pointed to by the *route* parameter are not currently used by [CreateIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipforwardentry). These members include **dwForwardPolicy**, **dwForwardType**, **dwForwardAge**, **dwForwardNextHopAS**, **dwForwardMetric1**, **dwForwardMetric2**, **dwForwardMetric3**, **dwForwardMetric4**, and **dwForwardMetric5**.

To modify an existing route in the IPv4 routing table, use the
[SetIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipforwardentry) function. To retrieve the IPv4 routing table, call the [GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable) function.

On Windows Vista and later, the **DeleteIpForwardEntry** function can only be called by a user logged on as a member of the Administrators group. If **DeleteIpForwardEntry** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned.

The **DeleteIpForwardEntry** function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

**Note** On Windows NT 4.0 and Windows 2000 and later, this function executes a privileged operation. For this function to execute successfully, the caller must be logged on as a member of the Administrators group or the NetworkConfigurationOperators group.

#### Examples

The following code example shows how to change the default gateway to NewGateway. By calling GetIpForwardTable, changing the gateway, and then calling SetIpForwardEntry will not change the route, but will add a new one. If multiple default gateways exist, this code will delete them. Be aware that the new gateway must be viable; otherwise, TCP/IP will ignore the change.

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
    DWORD NewGateway = 0xDDBBCCAA;      // this is in host order Ip Address AA.BB.CC.DD is DDCCBBAA

    unsigned int i;

// Identify the required size of the buffer.
    dwStatus = GetIpForwardTable(pIpForwardTable, &dwSize, bOrder);
    if (dwStatus == ERROR_INSUFFICIENT_BUFFER) {
        // Allocate memory for the table.
        if (!(pIpForwardTable = (PMIB_IPFORWARDTABLE) malloc(dwSize))) {
            printf("Malloc failed. Out of memory.\n");
            exit(1);
        }
        // Retrieve the table.
        dwStatus = GetIpForwardTable(pIpForwardTable, &dwSize, bOrder);
    }

    if (dwStatus != ERROR_SUCCESS) {
        printf("getIpForwardTable failed.\n");
        if (pIpForwardTable)
            free(pIpForwardTable);
        exit(1);
    }
// Search for the required row in the table. The default gateway has a destination
// of 0.0.0.0. Be aware the table continues to be searched, but only
// one row is copied. This is to ensure that, if multiple gateways exist, all of them are deleted.
//
    for (i = 0; i < pIpForwardTable->dwNumEntries; i++) {
        if (pIpForwardTable->table[i].dwForwardDest == 0) {
            // The default gateway was found.
            if (!pRow) {
                // Allocate memory to store the row. This is easier than manually filling
                // the row structure; only the gateway address is changed.
                //
                pRow = (PMIB_IPFORWARDROW) malloc(sizeof (MIB_IPFORWARDROW));
                if (!pRow) {
                    printf("Malloc failed. Out of memory.\n");
                    exit(1);
                }
                // Copy the row.
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

// Set the nexthop field to our new gateway. All other properties of the route will
// remain the same.
    pRow->dwForwardNextHop = NewGateway;

// Create a new route entry for the default gateway.
    dwStatus = CreateIpForwardEntry(pRow);

    if (dwStatus == NO_ERROR)
        printf("Gateway changed successfully\n");
    else if (dwStatus == ERROR_INVALID_PARAMETER)
        printf("Invalid parameter.\n");
    else
        printf("Error: %d\n", dwStatus);

// Free the memory.
    if (pIpForwardTable)
        free(pIpForwardTable);
    if (pRow)
        free(pRow);

    exit(0);
}

```

## See also

[CreateIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipforwardentry)

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow)

[SetIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipforwardentry)