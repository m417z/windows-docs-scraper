# _AVC_PIN_COUNT structure

## Description

The AVC_PIN_COUNT structure specifies the number of pins on an AV/C subunit device.

## Members

### `PinCount`

This value is filled in by *avc.sys* on return from the **AVC_FUNCTION_GET_PIN_COUNT** function.

## Remarks

This structure is used with the [AVC_FUNCTION_GET_PIN_COUNT](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-pin-count) function code.

This structure is used only as a member inside the AVC_MULTIFUNC_IRB structure. It is not used by itself.

See [How to Use Avc.sys](https://learn.microsoft.com/windows-hardware/drivers/stream/using-avc-sys) For information about building and sending an AV/C command.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_GET_PIN_COUNT](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-pin-count)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)