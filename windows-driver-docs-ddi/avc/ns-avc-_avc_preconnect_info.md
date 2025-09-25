# _AVC_PRECONNECT_INFO structure

## Description

The AVC_PRECONNECT_INFO structure specifies the preconnection information for the specified pin ID (zero-based offset) on an AV/C subunit device.

## Members

### `PinId`

Specifies the offset (or ID) of the pin for which information is to be retrieved.

### `ConnectInfo`

The AVCPRECONNECTINFO values for the specified pin.

## Remarks

This structure is used with the [AVC_FUNCTION_GET_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-connectinfo) function code.

This structure is used only as a member inside the AVC_MULTIFUNC_IRB structure. It is not used by itself.

See [How to Use Avc.sys](https://learn.microsoft.com/windows-hardware/drivers/stream/using-avc-sys) for information about building and sending an AV/C command.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_GET_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-connectinfo)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)