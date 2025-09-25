# FWPM_NET_EVENT_CLASSIFY_DROP2 structure

## Description

The **FWPM_NET_EVENT_CLASSIFY_DROP2** structure contains information that describes a layer drop failure.
[FWPM_NET_EVENT_CLASSIFY_DROP1](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_classify_drop1) is available. For Windows Vista, [FWPM_NET_EVENT_CLASSIFY_DROP0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_classify_drop0) is available.

## Members

### `filterId`

A LUID identifying the filter where the failure occurred.

### `layerId`

Indicates the identifier of the filtering layer where the failure occurred. For more information, see [Filtering Layer Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

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
| ----- | ------- |
| FWP_DIRECTION_IN <br> 0x00003900L | The packet is inbound. |
| FWP_DIRECTION_OUT <br> 0x00003901L | The packet is outbound. |
| FWP_DIRECTION_FORWARD <br> 0x00003902L | The packet is traversing an interface which it must pass through on the way to its destination. |

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