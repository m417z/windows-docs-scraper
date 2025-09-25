# _AVC_EXT_PLUG_COUNTS structure

## Description

The AVC_EXT_PLUG_COUNTS structure describes the number of external plugs on the subunit.

## Members

### `ExtInputs`

Ignored on input. On output, this contains the count of external input plugs.

### `ExtOutputs`

Ignored on input. On output, this contains the count of external output plugs.

## Remarks

This structure is used with the [AVC_FUNCTION_GET_EXT_PLUG_COUNTS](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-ext-plug-counts) function code.

This structure is used only as a member inside the AVC_MULTIFUNC_IRB structure. It is not used by itself.

See [How to Use Avc.sys](https://learn.microsoft.com/windows-hardware/drivers/stream/using-avc-sys) For information about building and sending an AV/C command.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_GET_EXT_PLUG_COUNTS](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-ext-plug-counts)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)