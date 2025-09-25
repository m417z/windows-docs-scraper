# FWPM_NET_EVENT_CLASSIFY_DROP_MAC0 structure

## Description

The **FWPM_NET_EVENT_CLASSIFY_DROP_MAC0** structure contains information that describes a MAC layer drop failure.

## Members

### `localMacAddr`

The local MAC address.

### `remoteMacAddr`

The remote MAC address.

### `mediaType`

The media type of the NDIS port.

### `ifType`

The interface type, as defined by the Internet Assigned Names Authority (IANA). Possible values for the interface type are listed in the Ipifcons.h include file.

### `etherType`

Indicates which protocol is encapsulated in the frame data. The values used for this field comes from the Ethernet V2 specification's numbering space.

### `ndisPortNumber`

The number assigned to the NDIS port.

### `reserved`

Reserved for internal use.

### `vlanTag`

The VLAN (802.1p/q) VID, CFI, and Priority fields marshaled into a 16-bit value. (See VLAN_TAG in netiodef.h.)

### `ifLuid`

The interface LUID corresponding to the network interface with which this packet is associated.

### `filterId`

The LUID identifying the filter where the failure occurred.

### `layerId`

The identifier of the filtering layer where the failure occurred. For more information, see [Filtering Layer Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-)

### `reauthReason`

Indicates the reason for reauthorizing a previously authorized connection.

### `originalProfile`

Indicates the identifier of the profile to which the packet was received (or from which the packet was sent).

### `currentProfile`

Indicates the identifier of the profile where the packet was when the failure occurred.

### `msFwpDirection`

Indicates the direction of the packet transmission.

Possible values:

| Value | Meaning |
| --- | --- |
| **FWP_DIRECTION_IN** | The packet is inbound.<br><br>0x00003900L |
| **FWP_DIRECTION_OUT** | The packet is outbound.<br><br>0x00003901L |
| **FWP_DIRECTION_FORWARD** | The packet is traversing an interface which it must pass through on the way to its destination.<br><br>0x00003902L |

### `isLoopback`

Indicates whether the packet originated from (or was heading to) the loopback adapter.

### `vSwitchId`

GUID identifier of a vSwitch.

### `vSwitchSourcePort`

Transient source port of a packet within the vSwitch.

### `vSwitchDestinationPort`

Transient destination port of a packet within the vSwitch.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)