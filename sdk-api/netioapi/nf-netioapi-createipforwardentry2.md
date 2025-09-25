# CreateIpForwardEntry2 function

## Description

The
**CreateIpForwardEntry2** function creates a new IP route entry on the local computer.

## Parameters

### `Row` [in]

A pointer to a
[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure entry for an IP route entry.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **DestinationPrefix** member of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) pointed to by the *Row* parameter was not specified, the **NextHop** member of the **MIB_IPFORWARD_ROW2** pointed to by the *Row* parameter was not specified, or both the **InterfaceLuid** or **InterfaceIndex** members of the **MIB_IPFORWARD_ROW2** pointed to by the *Row* parameter were unspecified. This error is also returned if the **PreferredLifetime** member specified in the **MIB_IPFORWARD_ROW2** is greater than the **ValidLifetime** member or if the **SitePrefixLength** in the **MIB_IPFORWARD_ROW2** is greater than the prefix length specified in the **DestinationPrefix**. |
| **ERROR_NOT_FOUND** | The specified interface could not be found. This error is returned if the network interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) pointed to by the *Row* parameter could not be found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if the interface specified does not support routes. This error is also returned if no IPv4 stack is on the local computer and **AF_INET** was specified in the address family in the **DestinationPrefix** member of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) pointed to by the *Row* parameter. This error is also returned if no IPv6 stack is on the local computer and **AF_INET6** was specified for the address family in the **DestinationPrefix** member. |
| **ERROR_OBJECT_ALREADY_EXISTS** | The object already exists. This error is returned if the **DestinationPrefix** member of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) pointed to by the *Row* parameter is a duplicate of an existing IP route entry on the interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the **MIB_IPFORWARD_ROW2**. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **CreateIpForwardEntry2** function is defined on Windows Vista and later.

The **CreateIpForwardEntry2** function is used to add a new neighbor IP address entry on a local computer. The [InitializeIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeipforwardentry) function should be used to initialize the members of a
[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure entry with default values. An application can then change the
members in the **MIB_IPFORWARD_ROW2** entry it wishes to modify, and then call the **CreateIpForwardEntry2** function.

The **DestinationPrefix** member in the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure pointed to by the *Row* parameter must be initialized to a valid IPv4 or IPv6 address prefix. The **NextHop** member in the **MIB_IPFORWARD_ROW2** structure pointed to by the *Row* parameter must be initialized to a valid IPv4 or IPv6 address and family. In addition, at least one of the following members in the **MIB_IPFORWARD_ROW2** structure pointed to the *Row* parameter must be initialized to the interface: the **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface on which to add the IP route entry. If no value was set for the **InterfaceLuid** member (the values of this member was set to zero), then the **InterfaceIndex** member is next used to determine the interface.

The route metric offset specified in the **Metric** member of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure pointed to by *Row* parameter represents only part of the complete route metric. The complete metric is a combination of this route metric offset added to the interface metric specified in the **Metric** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure of the associated interface. An application can retrieve the interface metric by calling the [GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry) function.

The **Age** and **Origin** members of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure pointed to by the *Row* are ignored when the **CreateIpForwardEntry2** function is called. These members are set by the network stack and cannot be set using the **CreateIpForwardEntry2** function.

The **CreateIpForwardEntry2** function will fail if the **DestinationPrefix** and **NextHop** members of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) pointed to by the *Row* parameter are a duplicate of an existing IP route entry on the interface specified in the **InterfaceLuid** or **InterfaceIndex** members.

The **CreateIpForwardEntry2** function can only be called by a user logged on as a member of the Administrators group. If **CreateIpForwardEntry2** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned. This function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

## See also

[DeleteIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipforwardentry2)

[GetBestRoute2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getbestroute2)

[GetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardentry2)

[GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2)

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[InitializeIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeipforwardentry)

[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2)

[MIB_IPFORWARD_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_table2)

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)

[NotifyRouteChange2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyroutechange2)

[SetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipforwardentry2)