# _AVC_PIN_ID structure

## Description

The AVC_PIN_ID structure describes a pin on a subunit.

## Members

### `PinId`

Specifies the offset (or ID) of the pin.

## Remarks

This structure is used with the [AVC_FUNCTION_ACQUIRE](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-acquire), [AVC_FUNCTION_RELEASE](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-release) and [AVC_FUNCTION_CLR_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-clr-connectinfo) function codes.

This structure is used only as a member inside the AVC_MULTIFUNC_IRB structure. It is not used by itself.

See [How to Use Avc.sys](https://learn.microsoft.com/windows-hardware/drivers/stream/using-avc-sys) For information about building and sending an AV/C command.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_ACQUIRE](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-acquire)

[AVC_FUNCTION_CLR_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-clr-connectinfo)

[AVC_FUNCTION_RELEASE](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-release)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)