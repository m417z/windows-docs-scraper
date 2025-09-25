# _AVCPRECONNECTINFO structure

## Description

The AVCPRECONNECTINFO structure is used to initialize a subunit driver and establish pin connections.

## Members

### `DeviceID`

A GUID representing the unit as a whole. All subunits within the same unit share the same GUID. No two units share the same GUID.

### `SubunitAddress`

The encoded subunit type and subunit ID of the subunit.

### `SubunitPlugNumber`

The plug number (within the subunit) described by the AVCPRECONNECTINFO structure.

### `DataFlow`

The direction of data flow on this subunit plug. Destination plugs have KSPIN_DATAFLOW_IN; source plugs have KSPIN_DATAFLOW_OUT.

### `Flags`

A bitmap with one or more bits set from the KSPIN_FLAG_AVC enumeration.

### `UnitPlugNumber`

The plug number (within the subunit) described by the AVCPRECONNECTINFO structure.

## Remarks

This structure is used with the [AVC_FUNCTION_GET_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-connectinfo) function code.

This structure is used only as member of the AVC_PRECONNECT_INFO structure. It is not used by itself.

## See also

[AVC_PRECONNECT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_preconnect_info)

[KSPIN_FLAG_AVC](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_kspin_flag_avc)