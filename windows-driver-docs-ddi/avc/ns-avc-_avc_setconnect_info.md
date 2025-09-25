# _AVC_SETCONNECT_INFO structure

## Description

The AVC_SETCONNECT_INFO structure is used to initialize a subunit driver and establish pin connections.

## Members

### `PinId`

Specifies the offset (or ID) of the pin for which information is to be set.

### `ConnectInfo`

The AVCCONNECTINFO values for the specified pin.

## Remarks

This structure is used with the [AVC_FUNCTION_SET_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-set-connectinfo) function code.

This structure is used only as a member inside the AVC_MULTIFUNC_IRB structure. It is not used by itself.

See [How to Use Avc.sys](https://learn.microsoft.com/windows-hardware/drivers/stream/using-avc-sys) For information about building and sending an AV/C command.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_SET_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-set-connectinfo)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)