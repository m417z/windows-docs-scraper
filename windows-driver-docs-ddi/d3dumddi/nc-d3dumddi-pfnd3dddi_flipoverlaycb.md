# PFND3DDDI_FLIPOVERLAYCB callback function

## Description

The **pfnFlipOverlayCb** function changes the allocation to display on the overlay or indicates to display the other field of the currently displaying allocation, when deinterlacing an interleaved resource.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_FLIPOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_flipoverlay) structure that describes how to change the display on the overlay.

## Return value

**pfnFlipOverlayCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The display on the overlay object was successfully changed.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|
|E_OUTOFMEMORY|pfnFlipOverlayCb could not allocate memory that was required for it to complete.|

This function might also return other HRESULT values.

## See also

[D3DDDICB_FLIPOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_flipoverlay)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)