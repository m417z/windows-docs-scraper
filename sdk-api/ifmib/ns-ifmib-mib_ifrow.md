# MIB_IFROW structure

## Description

The
**MIB_IFROW** structure stores information about a particular interface.

## Members

### `wszName`

Type: **WCHAR[MAX_INTERFACE_NAME_LEN]**

A pointer to a Unicode string that contains the name of the interface.

### `dwIndex`

Type: **DWORD**

The index that identifies the interface. This index value may change when a network adapter is disabled and then enabled, and should not be considered persistent.

### `dwType`

Type: **DWORD**

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
| **IF_TYPE_WWANPP2**<br><br>244 | An mobile broadband interface for CDMA-based devices.<br><br>**Note** This interface type is supported on Windows 7, Windows Server 2008 R2, and later. |

### `dwMtu`

Type: **DWORD**

The Maximum Transmission Unit (MTU) size in bytes.

### `dwSpeed`

Type: **DWORD**

The speed of the interface in bits per second.

### `dwPhysAddrLen`

Type: **DWORD**

The length, in bytes, of the physical address specified by the **bPhysAddr** member.

### `bPhysAddr`

Type: **BYTE[MAXLEN_PHYSADDR]**

The physical address of the adapter for this interface.

### `dwAdminStatus`

Type: **DWORD**

The interface is administratively enabled or disabled.

### `dwOperStatus`

Type: **DWORD**

The operational status of the interface. This member can be one of the following values defined in the INTERNAL_IF_OPER_STATUS enumeration defined in the *Ipifcons.h* header file.

| Value | Meaning |
| --- | --- |
| **IF_OPER_STATUS_NON_OPERATIONAL** | LAN adapter has been disabled, for example because of an address conflict. |
| **IF_OPER_STATUS_UNREACHABLE** | WAN adapter that is not connected. |
| **IF_OPER_STATUS_DISCONNECTED** | For LAN adapters: network cable disconnected. For WAN adapters: no carrier. |
| **IF_OPER_STATUS_CONNECTING** | WAN adapter that is in the process of connecting. |
| **IF_OPER_STATUS_CONNECTED** | WAN adapter that is connected to a remote peer. |
| **IF_OPER_STATUS_OPERATIONAL** | Default status for LAN adapters |

### `dwLastChange`

Type: **DWORD**

The length of time, in hundredths of seconds (10^-2 sec), starting from the last computer restart, when the interface entered its current operational state. This value rolls over after 2^32 hundredths of a second.

The **dwLastChange** member is not currently supported by NDIS. On Windows Vista and later, NDIS returns zero for this member. On earlier versions of Windows, an arbitrary value is returned in this member for the interfaces supported by NDIS. For interfaces supported by other interface providers, they might return an appropriate value.

### `dwInOctets`

Type: **DWORD**

The number of octets of data received through this interface.

### `dwInUcastPkts`

Type: **DWORD**

The number of unicast packets received through this interface.

### `dwInNUcastPkts`

Type: **DWORD**

The number of non-unicast packets received through this interface. Broadcast and multicast packets are included.

### `dwInDiscards`

Type: **DWORD**

The number of incoming packets that were discarded even though they did not have errors.

### `dwInErrors`

Type: **DWORD**

The number of incoming packets that were discarded because of errors.

### `dwInUnknownProtos`

Type: **DWORD**

The number of incoming packets that were discarded because the protocol was unknown.

### `dwOutOctets`

Type: **DWORD**

The number of octets of data sent through this interface.

### `dwOutUcastPkts`

Type: **DWORD**

The number of unicast packets sent through this interface.

### `dwOutNUcastPkts`

Type: **DWORD**

The number of non-unicast packets sent through this interface. Broadcast and multicast packets are included.

### `dwOutDiscards`

Type: **DWORD**

The number of outgoing packets that were discarded even though they did not have errors.

### `dwOutErrors`

Type: **DWORD**

The number of outgoing packets that were discarded because of errors.

### `dwOutQLen`

Type: **DWORD**

The transmit queue length. This field is not currently used.

### `dwDescrLen`

Type: **DWORD**

The length, in bytes, of the **bDescr** member.

### `bDescr`

Type: **BYTE[MAXLEN_IFDESCR]**

A description of the interface.

## Remarks

The **dwSpeed** member of the **MIB_IFROW** structure will be incorrect for very high-speed network interfaces (10 Gbit/s network adapter, for example) since the maximum value that can be store in a DWORD is 4,294,967,295. Applications should use the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure returned by the [GetIfEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifentry2) and [GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2) functions or the [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure returned by the [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function for determining the speed for very high-speed network interfaces.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIB_IFROW** structure is defined in the *Ifmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ifmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ifmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[GetIfEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getifentry)

[GetIfEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifentry2)

[IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh)

[MIB_IFSTATUS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-mib_ifstatus)

[MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)

[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0)