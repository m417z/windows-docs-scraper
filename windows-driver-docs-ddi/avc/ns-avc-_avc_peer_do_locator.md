# _AVC_PEER_DO_LOCATOR structure

## Description

The AVC_PEER_DO_LOCATOR describes nonvirtual (peer) instances of *avc.sys*.

## Members

### `NodeAddress`

Set to the NodeAddress of the device whose driver instance is to be located.

### `Generation`

Set to the Generation obtained with the NodeAddress.

### `DeviceObject`

On success, points to the FDO of the *avc.sys* instance. The caller must release the reference to this object (by using **ObDereferenceObject**) when finished with it.

## Remarks

This structure is used with the [AVC_FUNCTION_FIND_PEER_DO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-find-peer-do) function code.

This structure is used only as a member inside the AVC_MULTIFUNC_IRB structure. It is not used by itself.

See [How to Use Avc.sys](https://learn.microsoft.com/windows-hardware/drivers/stream/using-avc-sys) For information about building and sending an AV/C command.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_FIND_PEER_DO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-find-peer-do)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)