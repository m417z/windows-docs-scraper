# MIB_IF_ROW2 structure

## Description

The
**MIB_IF_ROW2** structure stores information about a particular interface.

## Members

### `InterfaceLuid`

Type: **[NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh)**

The locally unique identifier (LUID) for the network interface.

### `InterfaceIndex`

Type: **NET_IFINDEX**

The index that identifies the network interface. This index value may change when a network adapter is disabled and then enabled, and should not be considered persistent.

### `InterfaceGuid`

Type: **GUID**

The GUID for the network interface.

### `Alias`

Type: **WCHAR[IF_MAX_STRING_SIZE + 1]**

A NULL-terminated Unicode string that contains the alias name of the network interface.

### `Description`

Type: **WCHAR[IF_MAX_STRING_SIZE + 1]**

A NULL-terminated Unicode string that contains a description of the network interface.

### `PhysicalAddressLength`

Type: **ULONG**

The length, in bytes, of the physical hardware address specified by the **PhysicalAddress** member.

### `PhysicalAddress`

Type:  **UCHAR[IF_MAX_PHYS_ADDRESS_LENGTH]**

The physical hardware address of the adapter for this network interface.

### `PermanentPhysicalAddress`

Type:  **UCHAR[IF_MAX_PHYS_ADDRESS_LENGTH]**

The permanent physical hardware address of the adapter for this network interface.

### `Mtu`

Type: **ULONG**

The maximum transmission unit (MTU) size, in bytes, for this network interface.

### `Type`

Type: **IFTYPE**

The interface type as defined by the Internet Assigned Names Authority (IANA). For more information, see [http://www.iana.org/assignments/ianaiftype-mib](https://www.iana.org/assignments/ianaiftype-mib). Possible values for the interface type are listed in the *Ipifcons.h* header file.

The table below lists common values for the interface type although many other values are possible.

| Value | Meaning |
| --- | --- |
| **IF_TYPE_OTHER**<br><br>1 | Some other type of network interface. |
| **IF_TYPE_ETHERNET_CSMACD**<br><br>6 | An Ethernet network interface. |
| **IF_TYPE_ISO88025_TOKENRING**<br><br>9 | A token ring network interface. |
| **IF_TYPE_FDDI**<br><br>15 | A Fiber Distributed Data Interface (FDDI) network interface. |
| **IF_TYPE_PPP**<br><br>23 | A PPP network interface. |
| **IF_TYPE_SOFTWARE_LOOPBACK**<br><br>24 | A software loopback network interface. |
| **IF_TYPE_ATM**<br><br>37 | An ATM network interface. |
| **IF_TYPE_IEEE80211**<br><br>71 | An IEEE 802.11 wireless network interface. |
| **IF_TYPE_TUNNEL**<br><br>131 | A tunnel type encapsulation network interface. |
| **IF_TYPE_IEEE1394**<br><br>144 | An IEEE 1394 (Firewire) high performance serial bus network interface. |
| **IF_TYPE_IEEE80216_WMAN**<br><br>237 | A mobile broadband interface for WiMax devices.<br><br>**Note** This interface type is supported on Windows 7, Windows Server 2008 R2, and later. |
| **IF_TYPE_WWANPP**<br><br>243 | A mobile broadband interface for GSM-based devices.<br><br>**Note** This interface type is supported on Windows 7, Windows Server 2008 R2, and later. |
| **IF_TYPE_WWANPP2**<br><br>244 | A mobile broadband interface for CDMA-based devices.<br><br>**Note** This interface type is supported on Windows 7, Windows Server 2008 R2, and later. |

### `TunnelType`

Type: **TUNNEL_TYPE**

The encapsulation method used by a tunnel if the **Type** member is **IF_TYPE_TUNNEL**. The tunnel type is defined by the Internet Assigned Names Authority (IANA). For more information, see [http://www.iana.org/assignments/ianaiftype-mib](https://www.iana.org/assignments/ianaiftype-mib). This member can be one of the values from the **TUNNEL_TYPE** enumeration type defined in the *Ifdef.h* header file.

| Value | Meaning |
| --- | --- |
| **TUNNEL_TYPE_NONE**<br><br>0 | Not a tunnel. |
| **TUNNEL_TYPE_OTHER**<br><br>1 | None of the following tunnel types. |
| **TUNNEL_TYPE_DIRECT**<br><br>2 | A packet is encapsulated directly within a normal IP header, with no intermediate header, and unicast to the remote tunnel endpoint. |
| **TUNNEL_TYPE_6TO4**<br><br>11 | An IPv6 packet is encapsulated directly within an IPv4 header, with no intermediate header, and unicast to the destination determined by the 6to4 protocol. |
| **TUNNEL_TYPE_ISATAP**<br><br>13 | An IPv6 packet is encapsulated directly within an IPv4 header, with no intermediate header, and unicast to the destination determined by the ISATAP protocol. |
| **TUNNEL_TYPE_TEREDO**<br><br>14 | Teredo encapsulation. |

### `MediaType`

Type: **NDIS_MEDIUM**

The NDIS media type for the interface. This member can be one of the values from the **NDIS_MEDIUM** enumeration type defined in the *Ntddndis.h* header file.

| Value | Meaning |
| --- | --- |
| **NdisMedium802_3**<br><br>0 | An Ethernet (802.3) network. |
| **NdisMedium802_5**<br><br>1 | A Token Ring (802.5) network. |
| **NdisMediumFddi**<br><br>2 | A Fiber Distributed Data Interface (FDDI) network. |
| **NdisMediumWan**<br><br>3 | A wide area network (WAN). This type covers various forms of point-to-point and WAN NICs, as well as variant address/header formats that must be negotiated between the protocol driver and the underlying driver after the binding is established. |
| **NdisMediumLocalTalk**<br><br>4 | A LocalTalk network. |
| **NdisMediumDix**<br><br>5 | An Ethernet network for which the drivers use the DIX Ethernet header format. |
| **NdisMediumArcnetRaw**<br><br>6 | An ARCNET network. |
| **NdisMediumArcnet878_2**<br><br>7 | An ARCNET (878.2) network. |
| **NdisMediumAtm**<br><br>8 | An ATM network. Connection-oriented client protocol drivers can bind themselves to an underlying miniport driver that returns this value. Otherwise, legacy protocol drivers bind themselves to the system-supplied LanE intermediate driver, which reports its medium type as either NdisMedium802_3 or NdisMedium802_5, depending on how the LanE driver is configured by the network administrator. |
| **NdisMediumWirelessWan**<br><br>9 | A wireless network. NDIS 5.X miniport drivers that support wireless LAN (WLAN) or wireless WAN (WWAN) packets do not use this NDIS media type, but declare their media type as NdisMedium802_3 and emulate Ethernet to higher-level NDIS drivers.<br><br>**Note** This media type is supported and can be used for Mobile Broadband only on Windows 7, Windows Server 2008 R2, and later. |
| **NdisMediumIrda**<br><br>10 | An infrared (IrDA) network. |
| **NdisMediumBpc**<br><br>11 | A broadcast PC network. |
| **NdisMediumCoWan**<br><br>12 | A wide area network in a connection-oriented environment. |
| **NdisMedium1394**<br><br>13 | An IEEE 1394 (fire wire) network. |
| **NdisMediumInfiniBand**<br><br>14 | An InfiniBand network. |
| **NdisMediumTunnel**<br><br>15 | A tunnel network.<br><br>**Note** This media type is supported on Windows Vista, Windows Server 2008, and later. |
| **NdisMediumNative802_11**<br><br>16 | A native IEEE 802.11 network.<br><br>**Note** This media type is supported on Windows Vista, Windows Server 2008, and later. |
| **NdisMediumLoopback**<br><br>17 | An NDIS loopback network.<br><br>**Note** This media type is supported on Windows Vista, Windows Server 2008, and later. |
| **NdisMediumWiMax**<br><br>18 | An WiMax network.<br><br>**Note** This media type is supported on Windows 7, Windows Server 2008 R2, and later. |

### `PhysicalMediumType`

Type: **NDIS_PHYSICAL_MEDIUM**

The NDIS physical medium type. This member can be one of the values from the **NDIS_PHYSICAL_MEDIUM** enumeration type defined in the *Ntddndis.h* header file.

| Value | Meaning |
| --- | --- |
| **NdisPhysicalMediumUnspecified**<br><br>0 | The physical medium is none of the below values. For example, a one-way satellite feed is an unspecified physical medium. |
| **NdisPhysicalMediumWirelessLan**<br><br>1 | Packets are transferred over a wireless LAN network through a miniport driver that conforms to the 802.11 interface. |
| **NdisPhysicalMediumCableModem**<br><br>2 | Packets are transferred over a DOCSIS-based cable network. |
| **NdisPhysicalMediumPhoneLine**<br><br>3 | Packets are transferred over standard phone lines. This includes HomePNA media, for example. |
| **NdisPhysicalMediumPowerLine**<br><br>4 | Packets are transferred over wiring that is connected to a power distribution system. |
| **NdisPhysicalMediumDSL**<br><br>5 | Packets are transferred over a Digital Subscriber Line (DSL) network. This includes ADSL, UADSL (G.Lite), and SDSL, for example. |
| **NdisPhysicalMediumFibreChannel**<br><br>6 | Packets are transferred over a Fibre Channel interconnect. |
| **NdisPhysicalMedium1394**<br><br>7 | Packets are transferred over an IEEE 1394 bus. |
| **NdisPhysicalMediumWirelessWan**<br><br>8 | Packets are transferred over a Wireless WAN link. This includes mobile broadband devices that support CDPD, CDMA, GSM, and GPRS, for example. |
| **NdisPhysicalMediumNative802_11**<br><br>9 | Packets are transferred over a wireless LAN network through a miniport driver that conforms to the Native 802.11 interface.<br><br>**Note** The Native 802.11 interface is supported in NDIS 6.0 and later versions. |
| **NdisPhysicalMediumBluetooth**<br><br>10 | Packets are transferred over a Bluetooth network. Bluetooth is a short-range wireless technology that uses the 2.4 GHz spectrum. |
| **NdisPhysicalMediumInfiniband**<br><br>11 | Packets are transferred over an Infiniband interconnect. |
| **NdisPhysicalMediumWiMax**<br><br>12 | Packets are transferred over a WiMax network. |
| **NdisPhysicalMediumUWB**<br><br>13 | Packets are transferred over an ultra wide band network. |
| **NdisPhysicalMedium802_3**<br><br>14 | Packets are transferred over an Ethernet (802.3) network. |
| **NdisPhysicalMedium802_5**<br><br>15 | Packets are transferred over a Token Ring (802.5) network. |
| **NdisPhysicalMediumIrda**<br><br>16 | Packets are transferred over an infrared (IrDA) network. |
| **NdisPhysicalMediumWiredWAN**<br><br>17 | Packets are transferred over a wired WAN network. |
| **NdisPhysicalMediumWiredCoWan**<br><br>18 | Packets are transferred over a wide area network in a connection-oriented environment. |
| **NdisPhysicalMediumOther**<br><br>19 | Packets are transferred over a network that is not described by other possible values. |

### `AccessType`

Type: **NET_IF_ACCESS_TYPE**

The interface access type. This member can be one of the values from the **NET_IF_ACCESS_TYPE** enumeration type defined in the *Ifdef.h* header file.

| Value | Meaning |
| --- | --- |
| **NET_IF_ACCESS_LOOPBACK**<br><br>1 | Loopback access type. This access type indicates that the interface loops back transmit data as receive data. |
| **NET_IF_ACCESS_BROADCAST**<br><br>2 | The LAN access type which includes Ethernet. This access type indicates that the interface provides native support for multicast or broadcast services.<br><br>**Note** Mobile broadband interfaces with a **MediaType** of **NdisMedium802_3** use this access type. |
| **NET_IF_ACCESS_POINT_TO_POINT**<br><br>3 | Point-to-point access that supports CoNDIS/WAN, except for non-broadcast multi-access (NBMA) interfaces.<br><br>**Note** Mobile broadband interfaces with a **MediaType** of **NdisMediumWirelessWan** use this access type. |
| **NET_IF_ACCESS_POINT_TO_MULTI_POINT**<br><br>4 | Point-to-multipoint access that supports non-broadcast multi-access (NBMA) media, including the "RAS Internal" interface, and native (non-LANE) ATM. |
| **NET_IF_ACCESS_MAXIMUM**<br><br>5 | The maximum possible value for the **NET_IF_ACCESS_TYPE** enumeration type. This is not a legal value for *AccessType* member. |

### `DirectionType`

Type: **NET_IF_DIRECTION_TYPE**

The interface direction type. This member can be one of the values from the **NET_IF_DIRECTION_TYPE** enumeration type defined in the *Ifdef.h* header file.

| Value | Meaning |
| --- | --- |
| **NET_IF_DIRECTION_SENDRECEIVE**<br><br>0 | The send and receive direction type. This direction type indicates that the NDIS network interface can send and receive data. |
| **NET_IF_DIRECTION_SENDONLY**<br><br>1 | The send only direction type. This direction type indicates that the NDIS network interface can only send data. |
| **NET_IF_DIRECTION_RECEIVEONLY**<br><br>2 | The receive only direction type. This direction type indicates that the NDIS network interface can only receive data. |
| **NET_IF_DIRECTION_MAXIMUM**<br><br>3 | The maximum possible value for the **NET_IF_DIRECTION_TYPE** enumeration type. This is not a legal value for *DirectionType* member. |

### `InterfaceAndOperStatusFlags`

A set of flags that provide information about the interface. These flags are combined with a bitwise OR operation. If none of the flags applies, then this member is set to zero.

### `InterfaceAndOperStatusFlags.HardwareInterface`

**Type: **BOOLEAN****
Set if the network interface is for hardware.

### `InterfaceAndOperStatusFlags.FilterInterface`

**Type: **BOOLEAN****
Set if the network interface is for a filter module.

### `InterfaceAndOperStatusFlags.ConnectorPresent`

**Type: **BOOLEAN****
Set if a connector is present on the network interface. This value is set if there is a physical network adapter.

### `InterfaceAndOperStatusFlags.NotAuthenticated`

**Type: **BOOLEAN****
Set if the default port for the network interface is not authenticated. If a network interface is not authenticated by the target, then the network interface is not in an operational mode.
Although this applies to both wired and wireless network connections, authentication is more common for wireless network connections.

### `InterfaceAndOperStatusFlags.NotMediaConnected`

**Type: **BOOLEAN****
Set if the network interface is not in a media-connected state. If a network cable is unplugged for a wired network, this would be set. For a wireless network, this is set for the network adapter that is not connected to a network.

### `InterfaceAndOperStatusFlags.Paused`

**Type: **BOOLEAN****
Set if the network stack for the network interface is in the paused or pausing state. This does not mean that the computer is in a hibernated state.

### `InterfaceAndOperStatusFlags.LowPower`

**Type: **BOOLEAN****
Set if the network interface is in a low power state.

### `InterfaceAndOperStatusFlags.EndPointInterface`

**Type: **BOOLEAN****
Set if the network interface is an endpoint device and not a true network interface that connects to a network. This can be set by devices such as smart phones which use networking infrastructure to communicate to the PC but do not provide connectivity to an external network. It is mandatory for these types of devices to set this flag.

### `OperStatus`

Type: **IF_OPER_STATUS**

The operational status for the interface as defined in RFC 2863 as IfOperStatus. For more information, see [http://www.ietf.org/rfc/rfc2863.txt](https://www.ietf.org/rfc/rfc2863.txt). This member can be one of the values from the **IF_OPER_STATUS** enumeration type defined in the *Ifdef.h* header file.

| Value | Meaning |
| --- | --- |
| **IfOperStatusUp**<br><br>1 | The interface is up and able to pass packets. |
| **IfOperStatusDown**<br><br>2 | The interface is down and not in a condition to pass packets. The **IfOperStatusDown** state has two meanings, depending on the value of **AdminStatus** member.<br><br> If **AdminStatus** is not set to **NET_IF_ADMIN_STATUS_DOWN** and **ifOperStatus** is set to **IfOperStatusDown** then a fault condition is presumed to exist on the interface.<br><br> If **AdminStatus** is set to **IfOperStatusDown**, then **ifOperStatus** will normally also be set to **IfOperStatusDown** or **IfOperStatusNotPresent** and there is not necessarily a fault condition on the interface. |
| **IfOperStatusTesting**<br><br>3 | The interface is in testing mode. |
| **IfOperStatusUnknown**<br><br>4 | The operational status of the interface is unknown. |
| **IfOperStatusDormant**<br><br>5 | The interface is not actually in a condition to pass packets (it is not up), but is in a pending state, waiting for some external event. For on-demand interfaces, this new state identifies the situation where the interface is waiting for events to place it in the **IfOperStatusUp** state. |
| **IfOperStatusNotPresent**<br><br>6 | A refinement on the **IfOperStatusDown** state which indicates that the relevant interface is down specifically because some component (typically, a hardware device) is not present in the managed system. |
| **IfOperStatusLowerLayerDown**<br><br>7 | A refinement on the **IfOperStatusDown** state. This new state indicates that this interface runs on top of one or more other interfaces and that this interface is down specifically because one or more of these lower-layer interfaces are down. |

### `AdminStatus`

Type: **NET_IF_ADMIN_STATUS**

The administrative status for the interface as defined in RFC 2863. For more information, see [http://www.ietf.org/rfc/rfc2863.txt](https://www.ietf.org/rfc/rfc2863.txt). This member can be one of the values from the **NET_IF_ADMIN_STATUS** enumeration type defined in the *Ifdef.h* header file.

| Value | Meaning |
| --- | --- |
| **NET_IF_ADMIN_STATUS_UP**<br><br>1 | The interface is initialized and enabled. But the interface is not necessarily ready to transmit and receive network data because that depends on the operational status of the interface. |
| **NET_IF_ADMIN_STATUS_DOWN**<br><br>2 | The interface is down, and this interface cannot be used to transmit or receive network data. |
| **NET_IF_ADMIN_STATUS_TESTING**<br><br>3 | The interface is in a test mode, and no network data can be transmitted or received. |

### `MediaConnectState`

Type: **NET_IF_MEDIA_CONNECT_STATE**

The connection state of the interface. This member can be one of the values from the **NET_IF_MEDIA_CONNECT_STATE** enumeration type defined in the *Ifdef.h* header file.

| Value | Meaning |
| --- | --- |
| **MediaConnectStateUnknown**<br><br>0 | The connection state of the interface is unknown. |
| **MediaConnectStateConnected**<br><br>1 | The interface is connected to the network. |
| **MediaConnectStateDisconnected**<br><br>2 | The interface is not connected to the network. |

### `NetworkGuid`

Type: **NET_IF_NETWORK_GUID**

The GUID that is associated with the network that the interface belongs to.

### `ConnectionType`

Type: **NET_IF_CONNECTION_TYPE**

The NDIS network interface connection type. This member can be one of the values from the **NET_IF_CONNECTION_TYPE** enumeration type defined in the *Ifdef.h* header file.

| Value | Meaning |
| --- | --- |
| **NET_IF_CONNECTION_DEDICATED**<br><br>1 | The connection type is dedicated. The connection comes up automatically when media sense is TRUE. For example, an Ethernet connection is dedicated. |
| **NET_IF_CONNECTION_PASSIVE**<br><br>2 | The connection type is passive. The remote end must bring up the connection to the local station. For example, a RAS interface is passive. |
| **NET_IF_CONNECTION_DEMAND**<br><br>3 | The connection type is demand-dial. A connection of this type comes up in response to a local action (sending a packet, for example). |
| **NET_IF_CONNECTION_MAXIMUM**<br><br>4 | The maximum possible value for the **NET_IF_CONNECTION_TYPE** enumeration type. This is not a legal value for **ConnectionType** member. |

### `TransmitLinkSpeed`

Type: **ULONG64**

The speed in bits per second of the transmit link.

### `ReceiveLinkSpeed`

Type: **ULONG64**

The speed in bits per second of the receive link.

### `InOctets`

Type: **ULONG64**

The number of octets of data received without errors through this interface. This value includes octets in unicast, broadcast, and multicast packets.

### `InUcastPkts`

Type: **ULONG64**

The number of unicast packets received without errors through this interface.

### `InNUcastPkts`

Type: **ULONG64**

The number of non-unicast packets received without errors through this interface. This value includes broadcast and multicast packets.

### `InDiscards`

Type: **ULONG64**

The number of inbound packets which were chosen to be discarded even though no errors were detected to prevent the packets from being deliverable to a higher-layer protocol.

### `InErrors`

Type: **ULONG64**

The number of incoming packets that were discarded because of errors.

### `InUnknownProtos`

Type: **ULONG64**

The number of incoming packets that were discarded because the protocol was unknown.

### `InUcastOctets`

Type: **ULONG64**

The number of octets of data received without errors in unicast packets through this interface.

### `InMulticastOctets`

Type: **ULONG64**

The number of octets of data received without errors in multicast packets through this interface.

### `InBroadcastOctets`

Type: **ULONG64**

The number of octets of data received without errors in broadcast packets through this interface.

### `OutOctets`

Type: **ULONG64**

The number of octets of data transmitted without errors through this interface. This value includes octets in unicast, broadcast, and multicast packets.

### `OutUcastPkts`

Type: **ULONG64**

The number of unicast packets transmitted without errors through this interface.

### `OutNUcastPkts`

Type: **ULONG64**

The number of non-unicast packets transmitted without errors through this interface. This value includes broadcast and multicast packets.

### `OutDiscards`

Type: **ULONG64**

The number of outgoing packets that were discarded even though they did not have errors.

### `OutErrors`

Type: **ULONG64**

The number of outgoing packets that were discarded because of errors.

### `OutUcastOctets`

Type: **ULONG64**

The number of octets of data transmitted without errors in unicast packets through this interface.

### `OutMulticastOctets`

Type: **ULONG64**

The number of octets of data transmitted without errors in multicast packets through this interface.

### `OutBroadcastOctets`

Type: **ULONG64**

The number of octets of data transmitted without errors in broadcast packets through this interface.

### `OutQLen`

Type: **ULONG64**

The transmit queue length. This field is not currently used.

## Remarks

The **MIB_IF_ROW2** structure is defined on Windows Vista and later.

The values for the **Type** field are defined in the *Ipifcons.h* header file. Only the possible values listed in the description of the **Type** member are currently supported.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[GetIfEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifentry2)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)

[NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh)