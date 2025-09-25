# _AVC_UNIQUE_ID structure

## Description

The AVC_UNIQUE_ID describe the unique ID of the AV/C unit.

## Members

### `DeviceID`

A GUID representing the unit as a whole. All subunits within the same unit share the same GUID. No two units share the same GUID.

## Remarks

This structure is used with the [AVC_FUNCTION_GET_UNIQUE_ID](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-unique-id) function code.

This structure is used only as a member inside the AVC_MULTIFUNC_IRB structure. It is not used by itself.

See [How to Use Avc.sys](https://learn.microsoft.com/windows-hardware/drivers/stream/using-avc-sys) For information about building and sending an AV/C command.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_GET_UNIQUE_ID](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-unique-id)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)