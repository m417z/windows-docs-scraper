# _AVCCONNECTINFO structure

## Description

The AVCCONNECTINFO structure is used to initialize a subunit driver and establish pin connections.

## Members

### `DeviceID`

A GUID representing the unit as a whole. All subunits within the same unit share the same GUID. No two units share the same GUID.

### `SubunitAddress`

The encoded subunit type and subunit ID of the subunit.

### `SubunitPlugNumber`

The plug number (within the subunit) described by the AVCPRECONNECTINFO structure.

### `DataFlow`

The direction of data flow on this subunit plug. Destination plugs have KSPIN_DATAFLOW_IN; source plugs have KSPIN_DATAFLOW_OUT.

### `hPlug`

A plug handle obtained from *61883.sys* by the intersect handler according to the bit flags set in the associated AVCPRECONNECTINFO structure for this pin. If the proposed connection is between two subunits within the same unit, this value is **NULL**.

### `UnitPlugNumber`

The plug number (within the subunit) described by the AVCPRECONNECTINFO structure.

## Remarks

This structure is used only as member inside the [AVC_SETCONNECT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_setconnect_info) structure. It is not used by itself.

## See also

[AVC_FUNCTION_SET_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-set-connectinfo)