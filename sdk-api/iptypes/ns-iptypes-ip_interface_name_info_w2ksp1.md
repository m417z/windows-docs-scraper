# IP_INTERFACE_NAME_INFO_W2KSP1 structure

## Description

The **IP_INTERFACE_NAME_INFO** structure contains information about an IPv4 interface on the local computer.

## Members

### `Index`

Type: **ULONG**

The index of the IP interface for the active instance.

### `MediaType`

Type: **ULONG**

The interface type as defined by the Internet Assigned Names Authority (IANA). Possible values for the interface type are listed in the Ipifcons.h header file.

The table below lists common values for the interface type; although, many other values are possible.

| Value | Meaning |
| --- | --- |
| **IF_TYPE_OTHER**<br><br>1 | Some other type of network interface. |
| **IF_TYPE_ETHERNET_CSMACD**<br><br>6 | An Ethernet network interface. |
| **IF_TYPE_ISO88025_TOKENRING**<br><br>9 | A token ring network interface. |
| **IF_TYPE_PPP**<br><br>23 | A PPP network interface. |
| **IF_TYPE_SOFTWARE_LOOPBACK**<br><br>24 | A software loopback network interface. |
| **IF_TYPE_ATM**<br><br>37 | An ATM network interface. |
| **IF_TYPE_IEEE80211**<br><br>71 | An IEEE 802.11 wireless network interface. On Windows Vista and later, wireless network cards are reported as **IF_TYPE_IEEE80211**.<br><br>**Windows Server 2003, Windows 2000 Server with SP1 and Windows XP/2000:** Wireless network cards are reported as **IF_TYPE_ETHERNET_CSMACD**. |
| **IF_TYPE_TUNNEL**<br><br>131 | A tunnel type encapsulation network interface. |
| **IF_TYPE_IEEE1394**<br><br>144 | An IEEE 1394 (Firewire) high performance serial bus network interface. |

### `ConnectionType`

Type: **UCHAR**

The interface connection type for the adapter.

The possible values for this member are defined in the Ipifcons.h header file.

| Value | Meaning |
| --- | --- |
| **IF_CONNECTION_DEDICATED**<br><br>1 | The connection type is dedicated. The connection comes up automatically when media sense is **TRUE**. For example, an Ethernet connection is dedicated. |
| **IF_CONNECTION_PASSIVE**<br><br>2 | The connection type is passive. The remote end must bring up the connection to the local station. For example, a RAS interface is passive. |
| **IF_CONNECTION_DEMAND**<br><br>3 | The connection type is demand-dial. A connection of this type comes up in response to a local action (sending a packet, for example). |

### `AccessType`

Type: **UCHAR**

A value of the [IF_ACCESS_TYPE](https://learn.microsoft.com/windows/desktop/api/ifdef/ne-ifdef-net_if_access_type) enumeration that specifies the access type for the interface.

**Windows Server 2003, Windows 2000 Server with SP1 and Windows XP/2000:** The possible values for this member are defined in the Ipifcons.h header file.

| Value | Meaning |
| --- | --- |
| **IF_ACCESS_LOOPBACK**<br><br>1 | The loopback access type. This value indicates that the interface loops back transmit data as receive data. |
| **IF_ACCESS_BROADCAST**<br><br>2 | The LAN access type which includes Ethernet. This value indicates that the interface provides native support for multicast or broadcast services. |
| **IF_ACCESS_POINT_TO_POINT**<br><br>3 | The point to point access type. This value indicates support for CoNDIS/WAN, except for non-broadcast multi-access (NBMA) interfaces.<br><br>**Windows Server 2003, Windows 2000 Server with SP1 and Windows XP/2000:** This value was defined as **IF_ACCESS_POINTTOPOINT** in the Ipifcons.h header file. |
| **IF_ACCESS_POINT_TO_MULTI_POINT**<br><br>4 | The point to multipoint access type. This value indicates support for non-broadcast multi-access media, including the RAS internal interface and native ATM.<br><br>**Windows Server 2003, Windows 2000 Server with SP1 and Windows XP/2000:** This value was defined as **IF_ACCESS_POINTTOMULTIPOINT** in the Ipifcons.h header file. |

### `DeviceGuid`

Type: **GUID**

The GUID that identifies the underlying device for the interface. This member can be a zero GUID.

### `InterfaceGuid`

Type: **GUID**

The GUID that identifies the interface mapped to the device. Optional. This member can be a zero GUID.

## Remarks

In the Microsoft Windows Software Development Kit (SDK), the version of the structure for use on Windows 2000 with Service Pack 1 (SP1) and later is defined as **IP_INTERFACE_NAME_INFO_W2KSP1**. When compiling an application if the target platform is Windows 2000 with SP1 and later (`NTDDI_VERSION >= NTDDI_WIN2KSP1`, `_WIN32_WINNT >= 0x0500`, or `WINVER >= 0x0500`), the **IP_INTERFACE_NAME_INFO_W2KSP1** structure is typedefed to the **IP_INTERFACE_NAME_INFO** structure.

The **MediaType**, **ConnectionType**, and **AccessType** members, definitions and assigned values are available from the Ipifcons.h header file.

The optional **InterfaceGuid** member is often set for dial-up interfaces, and can be used to distinguish multiple dial-up interfaces that share the same device GUID.

## See also

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[NhpAllocateAndGetInterfaceInfoFromStack](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-nhpallocateandgetinterfaceinfofromstack)