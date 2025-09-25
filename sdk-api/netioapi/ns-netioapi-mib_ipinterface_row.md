# MIB_IPINTERFACE_ROW structure

## Description

The
**MIB_IPINTERFACE_ROW** structure stores interface management information for a particular IP address family on a network interface.

## Members

### `Family`

Type: **ADDRESS_FAMILY**

The address family. Possible values for the address family are listed in the *Winsock2.h* header file. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

On Windows Vista and later as well as on the Windows SDK, the organization of header files has changed and possible values for this member are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET** or **AF_INET6**, which are the Internet
address family formats for IPv4 and IPv6.

| Value | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | The address family is unspecified. |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. |

### `InterfaceLuid`

Type: **[NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh)**

The locally unique identifier (LUID) for the network interface.

### `InterfaceIndex`

Type: **NET_IFINDEX**

The local index value for the network interface. This index value may change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

### `MaxReassemblySize`

Type: **ULONG**

The maximum reassembly size, in bytes, of a fragmented IP packet. This member is currently set to zero and reserved for future use.

### `InterfaceIdentifier`

Type: **ULONG64**

Reserved for future use. This member is currently set to zero.

### `MinRouterAdvertisementInterval`

Type: **ULONG**

The minimum router advertisement interval, in milliseconds, on this IP interface. This member defaults to 200 for IPv6. This member is only applicable if the **AdvertisingEnabled** member is set to **TRUE**.

### `MaxRouterAdvertisementInterval`

Type: **ULONG**

The maximum router advertisement interval, in milliseconds, on this IP interface. This member defaults to 600 for IPv6. This member is only applicable if the **AdvertisingEnabled** member is set to **TRUE**.

### `AdvertisingEnabled`

Type: **BOOLEAN**

A value that indicates if router advertising is enabled on this IP interface. The default for IPv6 is that router advertisement is enabled only if the interface is configured to act as a router. The default for IPv4 is that router advertisement is disabled.

### `ForwardingEnabled`

Type: **BOOLEAN**

A value that indicates if IP forwarding is enabled on this IP interface.

### `WeakHostSend`

Type: **BOOLEAN**

A value that indicates if weak host send mode is enabled on this IP interface.

### `WeakHostReceive`

Type: **BOOLEAN**

A value that indicates if weak host receive mode is enabled on this IP interface.

### `UseAutomaticMetric`

Type: **BOOLEAN**

A value that indicates if the IP interface uses automatic metric.

### `UseNeighborUnreachabilityDetection`

Type: **BOOLEAN**

A value that indicates if neighbor unreachability detection is enabled on this IP interface.

### `ManagedAddressConfigurationSupported`

Type: **BOOLEAN**

A value that indicates if the IP interface supports managed address configuration using DHCP.

### `OtherStatefulConfigurationSupported`

Type: **BOOLEAN**

A value that indicates if the IP interface supports other stateful configuration (route configuration, for example).

### `AdvertiseDefaultRoute`

Type: **BOOLEAN**

A value that indicates if the IP interface advertises the default route. This member is only applicable if the **AdvertisingEnabled** member is set to **TRUE**.

### `RouterDiscoveryBehavior`

Type: **NL_ROUTER_DISCOVERY_BEHAVIOR**

The router discovery behavior. This member can be one of the values from the **NL_ROUTER_DISCOVERY_BEHAVIOR** enumeration type defined in the *Nldef.h* header file. The member is described in RFC 2461. For more information, see [http://www.ietf.org/rfc/rfc2461.txt](https://www.ietf.org/rfc/rfc2461.txt).

| Value | Meaning |
| --- | --- |
| **RouterDiscoveryDisabled**<br><br>0 | Router discovery is disabled. |
| **RouterDiscoveryEnabled**<br><br>1 | Router discovery is enabled. This is the default value for IPv6. |
| **RouterDiscoveryDhcp**<br><br>2 | Router discovery is configured based on DHCP. This is the default value for IPv4. |
| **RouterDiscoveryUnchanged**<br><br>-1 | This value is used when setting the properties for an IP interface when the value for router discovery should be unchanged. |

### `DadTransmits`

Type: **ULONG**

The number of consecutive messages sent while performing duplicate address
detection on a tentative IP unicast address. A value of zero
indicates that duplicate address detection is not
performed on tentative IP addresses. A value of one
indicates a single transmission with no follow up
retransmissions. For IPv4, the default for this member is 3. For IPv6, the default for this member is 1. For IPv6, these messages will sent as neighbor solicitation requests.
This member is defined as DupAddrDetectTransmits in RFC 2462. For more information, see [http://www.ietf.org/rfc/rfc2462.txt](https://www.ietf.org/rfc/rfc2462.txt).

### `BaseReachableTime`

Type: **ULONG**

The base for random reachable time, in milliseconds. The member is described in RFC 2461. For more information, see [http://www.ietf.org/rfc/rfc2461.txt](https://www.ietf.org/rfc/rfc2461.txt).

### `RetransmitTime`

Type: **ULONG**

The neighbor solicitation timeout, in milliseconds. The member is described in RFC 2461. For more information, see [http://www.ietf.org/rfc/rfc2461.txt](https://www.ietf.org/rfc/rfc2461.txt).

### `PathMtuDiscoveryTimeout`

Type: **ULONG**

The path MTU discovery timeout, in milliseconds.

### `LinkLocalAddressBehavior`

Type: **NL_LINK_LOCAL_ADDRESS_BEHAVIOR**

The link local address behavior. This member can be one of the values from the **NL_LINK_LOCAL_ADDRESS_BEHAVIOR** enumeration type defined in the *Nldef.h* header file.

| Value | Meaning |
| --- | --- |
| **LinkLocalAlwaysOff**<br><br>0 | Never use a link local IP address. |
| **LinkLocalDelayed**<br><br>1 | Use a link local IP address only if no other address is available. This is the default setting for an IPv4 interface. |
| **LinkLocalAlwaysOn**<br><br>2 | Always use a link local IP address. This is the default setting for an IPv6 interface. |
| **LinkLocalUnchanged**<br><br>-1 | This value is used when setting the properties for an IP interface when the value for link local address behavior should be unchanged. |

### `LinkLocalAddressTimeout`

Type: **ULONG**

The link local IP address timeout, in milliseconds.

### `ZoneIndices`

Type: **ULONG[ScopeLevelCount]**

An array that specifies the zone part of scope IDs.

### `SitePrefixLength`

Type: **ULONG**

The site prefix length, in bits, of the IP interface address. The length, in bits, of the site prefix or network part of the IP interface address. For an IPv4 address, any value greater than 32 is an illegal value. For an IPv6 address, any value greater than 128 is an illegal value.
A value of 255 is commonly used to represent an illegal value.

### `Metric`

Type: **ULONG**

The interface metric. Note the actual route metric used to compute the route preference is the summation of the route metric offset specified in the **Metric** member of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure and the interface metric specified in this member.

### `NlMtu`

Type: **ULONG**

The network layer MTU size, in bytes.

### `Connected`

Type: **BOOLEAN**

A value that indicates if the interface is connected to a network access point.

### `SupportsWakeUpPatterns`

Type: **BOOLEAN**

A value that specifies if the network interface supports Wake on LAN.

### `SupportsNeighborDiscovery`

Type: **BOOLEAN**

A value that specifies if the IP interface support neighbor discovery.

### `SupportsRouterDiscovery`

Type: **BOOLEAN**

A value that specifies if the IP interface support router discovery.

### `ReachableTime`

Type: **ULONG**

The reachable timeout, in milliseconds.

### `TransmitOffload`

Type: **NL_INTERFACE_OFFLOAD_ROD**

A set of flags that indicate the transmit offload capabilities for the IP interface. The [NL_INTERFACE_OFFLOAD_ROD](https://learn.microsoft.com/windows/desktop/api/nldef/ns-nldef-nl_interface_offload_rod) structure is defined in the *Nldef.h* header file.

### `ReceiveOffload`

Type: **NL_INTERFACE_OFFLOAD_ROD**

A set of flags that indicate the receive offload capabilities for the IP interface. The [NL_INTERFACE_OFFLOAD_ROD](https://learn.microsoft.com/windows/desktop/api/nldef/ns-nldef-nl_interface_offload_rod) structure is defined in the *Nldef.h* header file.

### `DisableDefaultRoutes`

Type: **BOOLEAN**

A value that indicates if using default route on the interface should be disabled. This member can be used by VPN clients to restrict split tunneling.

## Remarks

The **MIB_IPINTERFACE_ROW** structure is defined on Windows Vista and later.

The **Family**, **InterfaceLuid**, and **InterfaceIndex** members uniquely identify a **MIB_IPINTERFACE_ROW** entry.

When a unicast packet arrives at a host, IP must determine whether the packet is locally destined (its destination matches an address that is assigned to an interface of the host). IP implementations that follow a weak host model accept any locally destined packet, regardless of the interface on which the packet was received. IP implementations that follow the strong host model only accept locally destined packets if the destination address in the packet matches an address assigned to the interface on which the packet was received. The weak host model provides better network connectivity. However, it also makes hosts susceptible to multihome-based network attacks.

The current IPv4 implementation in Windows Server 2003 and Windows XP uses the weak host model. In this case, all unicast packets are sent out the interface with the lowest metric for a route.

The TCP/IP stack on Windows Vista and later supports the strong host model for both IPv4 and IPv6 and is configured to use the strong host mode by default (the **WeakHostReceive** and **WeakHostSend** members are set to **FALSE**). With the strong host mode, a unicast packet can be sent out a specific interface that does not have the lowest metric for a route by binding the socket to the source address of the specific interface.

The TCP/IP stack on Windows Vista and later can be configured to use a weak host model.

A metric is a value that is assigned to an IP route for a particular network interface that identifies the cost that is associated with using that route. For example, the metric can be valued in terms of link speed, hop count, or time delay. Automatic metric is a feature on Windows XP and later that automatically configures the metric for the local routes that are based on link speed. The automatic metric feature is enabled by default (the **UseAutomaticMetric** is set to **TRUE**) on Windows XP and later. It can also be manually configured to assign a specific metric to an IP route.

The automatic metric feature can be useful when the routing table contains multiple routes for the same destination. For example, a computer with a 10 megabit network interface and a 100 megabit network interface has a default gateway that is configured on both network interfaces. When **UseAutomaticMetric** is **TRUE**, this feature can force all of the traffic that is destined for the Internet, for example, to use the fastest network interface that is available.

The interface metric specified in the **Metric** member represents just the metric for the interface. The complete routing metric is a combination of this interface metric added to the route metric offset specified in the **Metric** member of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure of a route entry specified on this interface.

Unprivileged simultaneous access to multiple networks of different security requirements creates a security hole and allows an unprivileged application to accidentally relay data between the two networks. A typical example is simultaneous access to a virtual private network (VPN) and the internet. Windows Server 2003 and Windows XP use a weak host model, where RAS prevents such simultaneous access by increasing the route metric of all default routes over other interfaces. Thus all traffic is routed through the VPN interface, disrupting other network connectivity.

On Windows Vista and later, a strong host model is used by default. If a source IP address is specified in the route lookup using [GetBestRoute2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getbestroute2) or [GetBestRoute](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestroute), the route lookup is restricted to the interface of the source IP address. The route metric modification by RAS has no effect as the list of potential routes does not even have the route for the VPN interface thereby allowing traffic to the internet. The **DisableDefaultRoutes** member of the **MIB_IPINTERFACE_ROW** structure can be used to disable using the default route on an interface. This member can be used as a security measure by VPN clients to restrict split tunneling when split tunneling is not required by the VPN client. A VPN client can call the [SetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipinterfaceentry) function to set the **DisableDefaultRoutes** member to **TRUE** when required. A VPN client can query the current state of the **DisableDefaultRoutes** member by calling the [GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry) function.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

#### Examples

To view an example that retrieves the [MIB_IPINTERFACE_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_table) structure and then prints out a few members of the **MIB_IPINTERFACE_ROW** structure entries in this table, see the [GetIpInterfaceTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfacetable) function.

## See also

[GetBestRoute](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestroute)

[GetBestRoute2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getbestroute2)

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[GetIpInterfaceTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfacetable)

[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2)

[MIB_IPINTERFACE_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_table)

[NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh)

[NL_INTERFACE_OFFLOAD_ROD](https://learn.microsoft.com/windows/desktop/api/nldef/ns-nldef-nl_interface_offload_rod)

[SetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipinterfaceentry)