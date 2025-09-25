# SetIpInterfaceEntry function

## Description

The
**SetIpInterfaceEntry** function sets the properties of an IP interface on the local computer.

## Parameters

### `Row` [in, out]

A pointer to a
[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure entry for an interface. On input, the **Family** member of the **MIB_IPINTERFACE_ROW** must be set to **AF_INET6** or **AF_INET** and the **InterfaceLuid** or the **InterfaceIndex** member of the **MIB_IPINTERFACE_ROW** must be specified. On a successful return, the **InterfaceLuid** member of the **MIB_IPINTERFACE_ROW** is filled in if **InterfaceIndex** member of the **MIB_IPINTERFACE_ROW** entry was specified.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned if the network interface LUID or interface index specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) pointed to by the *Row* parameter was not a value on the local machine. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Family** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) pointed to by the *Row* parameter was not specified as **AF_INET** or **AF_INET6**, or both the **InterfaceLuid** or **InterfaceIndex** members of the **MIB_IPINTERFACE_ROW** pointed to by the *Row* parameter were unspecified. |
| **ERROR_NOT_FOUND** | The specified interface could not be found. This error is returned if the network interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) pointed to by the *Row* parameter does not match the IP address family specified in the **Family** member in the **MIB_IPINTERFACE_ROW** structure. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **SetIpInterfaceEntry** function is defined on Windows Vista and later.

The **SetIpInterfaceEntry** function can is used to modify an existing IP interface entry.

On input, the **Family** member in the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure pointed to by the *Row* parameter must be initialized to either **AF_INET** or **AF_INET6**. In addition on input, at least one of the following members in the **MIB_IPINTERFACE_ROW** structure pointed to the *Row* parameter must be initialized: the **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the values of this member was set to zero), then the **InterfaceIndex** member is next used to determine the interface.

On output, the **InterfaceLuid** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure pointed to by the *Row* parameter is filled in if the **InterfaceIndex** was specified.

The **MaxReassemblySize**, **MinRouterAdvertisementInterval**, **MaxRouterAdvertisementInterval** , **Connected**, **SupportsWakeUpPatterns**, **SupportsNeighborDiscovery**, **SupportsRouterDiscovery**, **ReachableTime**, **TransmitOffload**, and **ReceiveOffload** members of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure pointed to by the *Row* are ignored when the **SetIpInterfaceEntry** function is called. These members are set by the network stack and cannot be changed using the **SetIpInterfaceEntry** function.

An application would typically call the [GetIpInterfaceTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfacetable) function to retrieve the IP interface entries on the local computer or call the [GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry) function to retrieve just the IP interface entry to modify. The [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure for the specific IP interface entry could then be modified and a pointer to this structure passed to the **SetIpInterfaceEntry** function in the *Row* parameter. However for IPv4, an application must not try to modify the **SitePrefixLength** member of the **MIB_IPINTERFACE_ROW** structure. For IPv4, the **SitePrefixLength** member must be set to 0.

Another possible method to modify an existing IP interface entry is to use [InitializeIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeipinterfaceentry) function to initialize the fields of a
[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure entry with default values. Then set the **Family** member and either the **InterfaceIndex** or **InterfaceLuid** members in the **MIB_IPINTERFACE_ROW** structure pointed to by the *Row* parameter to match the IP interface to change. An application can then change the
fields in the **MIB_IPINTERFACE_ROW** entry it wishes to modify, and then call the **SetIpInterfaceEntry** function. However for IPv4, an application must not try to modify the **SitePrefixLength** member of the **MIB_IPINTERFACE_ROW** structure. For IPv4, the **SitePrefixLength** member must be set to 0. Caution must be used with this approach because the only way to determine all of the fields being changed would be to compare the fields in the **MIB_IPINTERFACE_ROW** of the specific IP interface entry with fields set by the **InitializeIpInterfaceEntry** function when a **MIB_IPINTERFACE_ROW** is initialized to default values.

Unprivileged simultaneous access to multiple networks of different security requirements creates a security hole and allows an unprivileged application to accidentally relay data between the two networks. A typical example is simultaneous access to a virtual private network (VPN) and the Internet. Windows Server 2003 and Windows XP use a weak host model, where RAS prevents such simultaneous access by increasing the route metric of all default routes over other interfaces. Thus all traffic is routed through the VPN interface, disrupting other network connectivity.

On Windows Vista and later, a strong host model is used by default. If a source IP address is specified in the route lookup using [GetBestRoute2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getbestroute2) or [GetBestRoute](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestroute), the route lookup is restricted to the interface of the source IP address. The route metric modification by RAS has no effect as the list of potential routes does not even have the route for the VPN interface thereby allowing traffic to the Internet. The **DisableDefaultRoutes** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) can be used to disable using the default route on an interface. This member can be used as a security measure by VPN clients to restrict split tunneling when split tunneling is not required by the VPN client. A VPN client can call the **SetIpInterfaceEntry** function to set the **DisableDefaultRoutes** member to **TRUE** when required. A VPN client can query the current state of the **DisableDefaultRoutes** member by calling the [GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry) function.

The

The **SetIpInterfaceEntry** function can only be called by a user logged on as a member of the Administrators group. If **SetIpInterfaceEntry** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned. This function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

## See also

[GetBestRoute](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestroute)

[GetBestRoute2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getbestroute2)

[GetIfEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifentry2)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex)

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[GetIpInterfaceTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfacetable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[InitializeIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeipinterfaceentry)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)

[MIB_IPINTERFACE_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_table)

[NotifyIpInterfaceChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyipinterfacechange)