# FWPM_NET_EVENT_CLASSIFY_ALLOW0 structure

## Description

The **FWPM_NET_EVENT_CLASSIFY_ALLOW0** structure contains information that describes allowed traffic as enforced by the WFP classify engine.

## Members

### `filterId`

Type: **UINT64**

A LUID identifying the WFP filter allowing this traffic.

### `layerId`

Type: **UINT16**

The identifier of the WFP filtering layer where the filter specified in **filterId** is stored. For more information, see [Filtering Layer Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

### `reauthReason`

Type: **UINT32**

The reason for reauthorizing a previously authorized connection.

### `originalProfile`

Type: **UINT32**

The identifier of the profile to which the packet was received (or from which the packet was sent).

### `currentProfile`

Type: **UINT32**

The identifier of the profile where the packet was when the failure occurred.

### `msFwpDirection`

Type: **UINT32**

Indicates the direction of the packet transmission. Possible values are **FWP_DIRECTION_INBOUND** or **FWP_DIRECTION_OUTBOUND**.

### `isLoopback`

Type: **BOOL**

If true, indicates that the packet originated from (or was heading to) the loopback adapter; otherwise, false.

## See also

[FWPM_NET_EVENT2](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event2)