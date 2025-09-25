# MIB_IPSTATS_LH structure

## Description

The
**MIB_IPSTATS** structure stores information about the IP protocol running on a particular computer.

## Members

### `dwForwarding`

Type: **DWORD**

Specifies whether IP forwarding is enabled or disabled for a protocol (IPv4 or IPv6).

On Windows Vista and later, this member is defined as a union containing a **DWORD dwForwarding** member and a **MIB_IPSTATS_FORWARDING Forwarding** member where **MIB_IPSTATS_FORWARDING** is an enumeration defined in the *Ipmib.h* header file.

**Note** This member applies to the entire system per protocol (IPv4 or IPv6) and doesn’t return per interface configuration for IP forwarding.

| Value | Meaning |
| --- | --- |
| **MIB_IP_FORWARDING**<br><br>1 | IP forwarding is enabled. |
| **MIB_IP_NOT_FORWARDING**<br><br>2 | IP forwarding is not enabled. |
| **MIB_USE_CURRENT_FORWARDING**<br><br>0xffff | Use the current IP forwarding setting. This value is only applicable when setting the forwarding and time-to-live (TTL) options using the **SetIpStatistics** and [SetIpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipstatisticsex) functions. |

### `Forwarding`

### `dwDefaultTTL`

Type: **DWORD**

The default initial time-to-live (TTL) for datagrams originating on a particular computer.

This member can be set to **MIB_USE_CURRENT_TTL** to use the current default TTL value when setting the forwarding and time-to-live (TTL) options using the **SetIpStatistics** and [SetIpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipstatisticsex) functions.

### `dwInReceives`

Type: **DWORD**

The number of datagrams received.

### `dwInHdrErrors`

Type: **DWORD**

The number of datagrams received that have header errors.

### `dwInAddrErrors`

Type: **DWORD**

The number of datagrams received that have address errors.

### `dwForwDatagrams`

Type: **DWORD**

The number of datagrams forwarded.

### `dwInUnknownProtos`

Type: **DWORD**

The number of datagrams received that have an unknown protocol.

### `dwInDiscards`

Type: **DWORD**

The number of received datagrams discarded.

### `dwInDelivers`

Type: **DWORD**

The number of received datagrams delivered.

### `dwOutRequests`

Type: **DWORD**

The number of outgoing datagrams that IP is requested to transmit. This number does not include forwarded datagrams.

### `dwRoutingDiscards`

Type: **DWORD**

The number of outgoing datagrams discarded.

### `dwOutDiscards`

Type: **DWORD**

The number of transmitted datagrams discarded.

### `dwOutNoRoutes`

Type: **DWORD**

The number of datagrams for which this computer did not have a route to the destination IP address. These datagrams were discarded.

### `dwReasmTimeout`

Type: **DWORD**

The amount of time allowed for all pieces of a fragmented datagram to arrive. If all pieces do not arrive within this time, the datagram is discarded.

### `dwReasmReqds`

Type: **DWORD**

The number of datagrams that require re-assembly.

### `dwReasmOks`

Type: **DWORD**

The number of datagrams that were successfully reassembled.

### `dwReasmFails`

Type: **DWORD**

The number of datagrams that cannot be reassembled.

### `dwFragOks`

Type: **DWORD**

The number of datagrams that were fragmented successfully.

### `dwFragFails`

Type: **DWORD**

The number of datagrams that have not been fragmented because the IP header specifies no fragmentation. These datagrams are discarded.

### `dwFragCreates`

Type: **DWORD**

The number of fragments created.

### `dwNumIf`

Type: **DWORD**

The number of interfaces.

### `dwNumAddr`

Type: **DWORD**

The number of IP addresses associated with this computer.

### `dwNumRoutes`

Type: **DWORD**

The number of routes in the IP routing table.

## Remarks

The
**MIB_IPSTATS** structure stores information per protocol (IPv4 or IPv6).

The **dwForwarding** member specifies the per-protocol forwarding state for IPv4 or IPv6, not the forwarding state for an interface. The forwarding state of each interface state is the state that is in affect for that interface. The per-protocol state returned by the **GetIpStatistics** or the **GetIpStatisticsEx** function is not the forwarding state in affect. The **dwForwarding** member exists to serve two purposes:

* Provides a default value for the forwarding state when a new interface is created with no specific forwarding state (neither disabled nor enabled) . This value is inherited per-protocol state.
* Provides a value set by a domain administrator to enable or disable a per-protocol forwarding state. The forwarding states of all interfaces using that protocol are also enabled or disabled.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIB_IPSTATS** structure is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

**GetIpStatistics**

**GetIpStatisticsEx**

**SetIpStatistics**

[SetIpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipstatisticsex)