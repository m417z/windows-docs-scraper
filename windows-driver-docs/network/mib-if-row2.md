# MIB\_IF\_ROW2 structure

The MIB\_IF\_ROW2 structure stores information about a particular interface.

## Members

- **InterfaceLuid**
The locally unique identifier (LUID) for the network interface.

- **InterfaceIndex**
The index that identifies the network interface. This index value might change when a network adapter is disabled and then enabled, and should not be considered persistent.

- **InterfaceGuid**
The GUID for the network interface.

- **Alias**
A NULL-terminated Unicode string that contains the alias name of the network interface.

- **Description**
A NULL-terminated Unicode string that contains a description of the network interface.

- **PhysicalAddressLength**
The length, in bytes, of the physical hardware address that the PhysicalAddress member specifies.

- **PhysicalAddress**
The physical hardware address of the adapter for this network interface.

- **PermanentPhysicalAddress**
The permanent physical hardware address of the adapter for this network interface.

- **Mtu**
The maximum transmission unit (MTU) size, in bytes, for this network interface.

- **Type**
The interface type as defined by the Internet Assigned Names Authority (IANA). For more information, see [IANAifType-MIB DEFINITIONS](https://go.microsoft.com/fwlink/p/?linkid=60066). Possible values for the interface type are listed in the Ipifcons.h header file.

 The following table lists common values for the interface type, although many other values are possible.

| Value | Meaning |
| --- | --- |
| IF_TYPE_OTHER<br><br>1 | Some other type of network interface |
| IF_TYPE_ETHERNET_CSMACD<br><br>6 | An Ethernet network interface |
| IF_TYPE_ISO88025_TOKENRING<br><br>9 | A token ring network interface |
| IF_TYPE_PPP<br><br>23 | A PPP network interface |
| IF_TYPE_SOFTWARE_LOOPBACK<br><br>24 | A software loopback network interface |
| IF_TYPE_ATM<br><br>37 | An ATM network interface |
| IF_TYPE_IEEE80211<br><br>71 | An IEEE 802.11 wireless network interface |
| IF_TYPE_TUNNEL<br><br>131 | A tunnel type encapsulation network interface |
| IF_TYPE_IEEE1394<br><br>144 | An IEEE 1394 (Firewire) high performance serial bus network interface |

- **TunnelType**
If the Type member is IF\_TYPE\_TUNNEL, a [**TUNNEL\_TYPE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-tunnel_type) type that defines the encapsulation method that a tunnel uses.

- **MediaType**
The NDIS media type for the interface. This member can be one of the following values from the NDIS\_MEDIUM enumeration type that is defined in the Ntddndis.h header file.

| Value | Meaning |
| --- | --- |
| NdisMedium802_3<br><br>0 | An Ethernet (802.3) network. |
| NdisMedium802_5<br><br>1 | A Token Ring (802.5) network. |
| NdisMediumFddi<br><br>2 | A Fiber Distributed Data Interface (FDDI) network. |
| NdisMediumWan<br><br>3 | A wide area network (WAN). This type covers various forms of point-to-point and WAN NICs and variant address/header formats that must be negotiated between the protocol driver and the underlying driver after the binding is established. |
| NdisMediumLocalTalk<br><br>4 | A LocalTalk network. |
| NdisMediumDix<br><br>5 | An Ethernet network for which the drivers use the DIX Ethernet header format. |
| NdisMediumArcnetRaw<br><br>6 | An ARCNET network. |
| NdisMediumArcnet878_2<br><br>7 | An ARCNET (878.2) network. |
| NdisMediumAtm<br><br>8 | An ATM network. Connection-oriented client protocol drivers can bind themselves to an underlying miniport driver that returns this value. Otherwise, legacy protocol drivers bind themselves to the system-supplied LanE intermediate driver, which reports its medium type as either **NdisMedium802_3** or NdisMedium802_5, depending on how the network administrator configures the LanE driver. |
| NdisMediumWirelessWan<br><br>9 | A wireless network. NDIS 5. x miniport drivers that support wireless LAN (WLAN) or wireless WAN (WWAN) packets declare their medium as **NdisMedium802_3** and emulate Ethernet to higher-level NDIS drivers.<br><br>Note This media type is not available for use on Windows Vista or later versions of Windows. |
| NdisMediumIrda<br><br>10 | An infrared (IrDA) network. |
| NdisMediumBpc<br><br>11 | A broadcast computer network. |
| NdisMediumCoWan<br><br>12 | A wide area network in a connection-oriented environment. |
| NdisMedium1394<br><br>13 | An IEEE 1394 (fire wire) network. |
| NdisMediumInfiniBand<br><br>14 | An InfiniBand network. |
| NdisMediumTunnel<br><br>15 | A tunnel network. |
| NdisMediumNative802_11<br><br>16 | A native IEEE 802.11 network. |
| NdisMediumLoopback<br><br>17 | An NDIS loopback network. |

- **PhysicalMediumType**
The NDIS physical medium type. This member can be one of the following values from the NDIS\_PHYSICAL\_MEDIUM enumeration type that is defined in the Ntddndis.h header file.

| Value | Meaning |
| --- | --- |
| NdisPhysicalMediumUnspecified<br><br>0 | The physical medium is none of the following values. For example, a one-way satellite feed is an unspecified physical medium. |
| NdisPhysicalMediumWirelessLan<br><br>1 | Packets are transferred over a wireless LAN network through a miniport driver that complies with the 802.11 interface. |
| NdisPhysicalMediumCableModem<br><br>2 | Packets are transferred over a DOCSIS-based cable network. |
| NdisPhysicalMediumPhoneLine<br><br>3 | Packets are transferred over standard telephone lines. This type includes HomePNA media. |
| NdisPhysicalMediumPowerLine<br><br>4 | Packets are transferred over wiring that is connected to a power distribution system. |
| NdisPhysicalMediumDSL<br><br>5 | Packets are transferred over a Digital Subscriber Line (DSL) network. This type includes ADSL, UADSL (G.Lite), and SDSL. |
| NdisPhysicalMediumFibreChannel<br><br>6 | Packets are transferred over a Fibre Channel interconnect. |
| NdisPhysicalMedium1394<br><br>7 | Packets are transferred over an IEEE 1394 bus. |
| NdisPhysicalMediumWirelessWan<br><br>8 | Packets are transferred over a Wireless WAN link. This type includes CDPD, CDMA and GPRS. |
| NdisPhysicalMediumNative802_11<br><br>9 | Packets are transferred over a wireless LAN network through a miniport driver that complies with the Native 802.11 interface.<br><br>Note The Native 802.11 interface is supported in NDIS 6.0 and later versions. |
| NdisPhysicalMediumBluetooth<br><br>10 | Packets are transferred over a Bluetooth network. Bluetooth is a short-range wireless technology that uses the 2.4 GHz spectrum. |
| NdisPhysicalMediumInfiniband<br><br>11 | Packets are transferred over an InfiniBand interconnect. |
| NdisPhysicalMediumUWB<br><br>13 | Packets are transferred over an ultra wide band network. |
| NdisPhysicalMedium802_3<br><br>14 | Packets are transferred over an Ethernet (802.3) network. |
| NdisPhysicalMedium802_5<br><br>15 | Packets are transferred over a Token Ring (802.5) network. |
| NdisPhysicalMediumIrda<br><br>16 | Packets are transferred over an infrared (IrDA) network. |
| NdisPhysicalMediumWiredWAN<br><br>17 | Packets are transferred over a wired WAN network. |
| NdisPhysicalMediumWiredCoWan<br><br>18 | Packets are transferred over a wide area network in a connection-oriented environment. |
| NdisPhysicalMediumOther<br><br>19 | Packets are transferred over a network that is not described by other possible values. |

- **AccessType**
A [**NET\_IF\_ACCESS\_TYPE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_access_type) NDIS network interface access type.

- **DirectionType**
A [**NET\_IF\_DIRECTION\_TYPE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type) NDIS network interface direction type.

- **InterfaceAndOperStatusFlags**
A set of the following flags that provide information about the interface. These flags are combined with a bitwise OR operation. If none of the flags applies, this member is set to zero.

    - **HardwareInterface**
The network interface is for hardware.

    - **FilterInterface**
The network interface is for a filter module.

    - **ConnectorPresent**
A connector is present on the network interface. This value is set if there is a physical network adapter.

    - **NotAuthenticated**
The default port for the network interface is not authenticated. If a network interface is not authenticated by the target, the network interface is not in an operational mode. Although this situation applies to both wired and wireless network connections, authentication is more common for wireless network connections.

    - **NotMediaConnected**
The network interface is not in a media-connected state. If a network cable is unplugged for a wired network, this value is set. For a wireless network, this value is set for the network adapter that is not connected to a network.

    - **Paused**
The network stack for the network interface is in the paused or pausing state. This value does not mean that the computer is in a hibernated state.

    - **LowPower**
The network interface is in a low power state.

    - **EndPointInterface**
The network interface is an endpoint device and not a true network interface that connects to a network. This value can be set by devices, such as smartphones, that use networking infrastructure to communicate to the computer but do not provide connectivity to an external network. These types of devices must set this flag.

- **OperStatus**
A [**IF\_OPER\_STATUS**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-if_oper_status) NDIS network interface operational status type.

- **AdminStatus**
The [**NET\_IF\_ADMIN\_STATUS**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_admin_status) administrative status type.

- **MediaConnectState**
The [**NET\_IF\_MEDIA\_CONNECT\_STATE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_media_connect_state) connection state type.

- **NetworkGuid**
The GUID that is associated with the network that the interface belongs to.

- **ConnectionType**
A [**NET\_IF\_CONNECTION\_TYPE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_connection_type) NDIS network interface connection type.

- **TransmitLinkSpeed**
The speed, in bits per second, of the transmit link.

- **ReceiveLinkSpeed**
The speed, in bits per second, of the receive link.

- **InOctets**
The number of octets of data that are received without errors through this interface. This value includes octets in unicast, broadcast, and multicast packets.

- **InUcastPkts**
The number of unicast packets that are received without errors through this interface.

- **InNUcastPkts**
The number of non-unicast packets that are received without errors through this interface. This value includes broadcast and multicast packets.

- **InDiscards**
The number of incoming packets that were discarded even though they did not have errors.

- **InErrors**
The number of incoming packets that were discarded because of errors.

- **InUnknownProtos**
The number of incoming packets that were discarded because the protocol was unknown.

- **InUcastOctets**
The number of octets of data that are received without errors in unicast packets through this interface.

- **InMulticastOctets**
The number of octets of data that are received without errors in multicast packets through this interface.

- **InBroadcastOctets**
The number of octets of data that are received without errors in broadcast packets through this interface.

- **OutOctets**
The number of octets of data that are transmitted without errors through this interface. This value includes octets in unicast, broadcast, and multicast packets.

- **OutUcastPkts**
The number of unicast packets that are transmitted without errors through this interface.

- **OutNUcastPkts**
The number of non-unicast packets that are transmitted without errors through this interface. This value includes broadcast and multicast packets.

- **OutDiscards**
The number of outgoing packets that were discarded even though they did not have errors.

- **OutErrors**
The number of outgoing packets that were discarded because of errors.

- **OutUcastOctets**
The number of octets of data that are transmitted without errors in unicast packets through this interface.

- **OutMulticastOctets**
The number of octets of data that are transmitted without errors in multicast packets through this interface.

- **OutBroadcastOctets**
The number of octets of data that are transmitted without errors in broadcast packets through this interface.

- **OutQLen**
The transmit queue length. This field is not currently used.

## Remarks

The values for the Type field are defined in the Ipifcons.h header file. Only the possible values that are listed in the description of the Type member are currently supported.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**GetIfEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getifentry2)

[**GetIfTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2)

[**MIB\_IF\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-table2)

[**NET\_IF\_ACCESS\_TYPE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_access_type)

[**NET\_IF\_ADMIN\_STATUS**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_admin_status)

[**NET\_IF\_CONNECTION\_TYPE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_connection_type)

[**NET\_IF\_DIRECTION\_TYPE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type)

[**NET\_IF\_MEDIA\_CONNECT\_STATE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_media_connect_state)

[**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value)

[**TUNNEL\_TYPE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-tunnel_type)