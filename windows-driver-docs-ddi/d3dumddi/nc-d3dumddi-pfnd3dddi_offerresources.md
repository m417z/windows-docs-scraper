# PFND3DDDI_OFFERRESOURCES callback function

## Description

Called by the Microsoft Direct3D runtime to request that the user-mode display driver offer video memory resources for reuse.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_OFFERRESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_offerresources) structure that defines the video memory resources that the driver offers.

## Return value

Returns one of the following values.

|Return code|Description|
|--- |--- |
|S_OK|The video memory resources were successfully offered.|
|D3DDDIERR_DEVICEREMOVED|The driver detected that the display adapter was removed, so the driver did not complete the operation.<br>If the driver is not aware of the adapter removal, the driver is not required to return this error code.|

## Remarks

If the user-mode driver does not have outstanding work queued that references an allocation that it has been asked to offer, then it can offer the allocation immediately or postpone the offer until the next call is made to the [Flush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfworkitem-flush) or [Present](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present) functions. However, the driver must always process all batched offer calls that have been submitted through *Flush* or *Present*.

If the driver uses the [renaming service](https://learn.microsoft.com/windows-hardware/drivers/display/requesting-to-rename-an-allocation) of the video memory manager, then the driver should offer the last allocation instance.

## See also

[D3DDDIARG_OFFERRESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_offerresources)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[Flush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfworkitem-flush)

[Present](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present)

[ReclaimResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimresources)