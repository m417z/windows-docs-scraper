# NET_LUID_LH structure

## Description

The **NET_LUID** union is the locally unique identifier (LUID) for a network interface.

## Members

### `Value`

Type: **ULONG64**

A 64-bit value that represents the LUID.

### `Info`

A named union containing the component fields in the 64-bit LUID **Value** member.

### `Info.Reserved`

**Type: **ULONG64****
This field is reserved.

### `Info.NetLuidIndex`

**Type: **ULONG64****
The network interface LUID index.

### `Info.IfType`

**Type: **ULONG64****
The interface type as defined by the Internet Assigned Names Authority (IANA). Possible values for the interface type are listed in the *Ipifcons.h* include file.

The table below lists common values for the interface type although many other values are possible.

| Value | Meaning |
| --- | --- |
| **IF_TYPE_OTHER**<br><br>1 | Some other type of network interface. |
| **IF_TYPE_ETHERNET_CSMACD**<br><br>6 | An Ethernet network interface. |
| **IF_TYPE_ISO88025_TOKENRING**<br><br>9 | A token ring network interface. |
| **IF_TYPE_PPP**<br><br>23 | A PPP network interface. |
| **IF_TYPE_SOFTWARE_LOOPBACK**<br><br>24 | A software loopback network interface. |
| **IF_TYPE_ATM**<br><br>37 | An ATM network interface. |
| **IF_TYPE_IEEE80211**<br><br>71 | An IEEE 802.11 wireless network interface. |
| **IF_TYPE_TUNNEL**<br><br>131 | A tunnel type encapsulation network interface. |
| **IF_TYPE_IEEE1394**<br><br>144 | An IEEE 1394 (Firewire) high performance serial bus network interface. |

## Remarks

The **NET_LUID** structure is protocol independent and works with network interfaces for both the IPv6 and IPv4 protocol. The **NET_LUID** structure is defined on Windows Vista and later.

The **IF_LUID** and **NET_LUID_LH** structures are other names that can be used for the **NET_LUID** union.

The values for the **IfType** bitfield are defined in the *Ipifcons.h* include file. Only the possible values listed in the description of the **IfType** member are currently supported.

## See also

[ConvertInterfaceAliasToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacealiastoluid)

[ConvertInterfaceGuidToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceguidtoluid)

[ConvertInterfaceIndexToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceindextoluid)

[ConvertInterfaceLuidToGuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoguid)

[ConvertInterfaceLuidToIndex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoindex)

[ConvertInterfaceLuidToNameA](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtonamea)

[ConvertInterfaceLuidToNameW](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtonamew)

[ConvertInterfaceNameToLuidA](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacenametoluida)

[ConvertInterfaceNameToLuidW](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacenametoluidw)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)