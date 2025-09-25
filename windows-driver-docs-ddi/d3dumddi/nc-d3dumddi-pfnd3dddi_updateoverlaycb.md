# PFND3DDDI_UPDATEOVERLAYCB callback function

## Description

The **pfnUpdateOverlayCb** function modifies a kernel-mode overlay object.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_UPDATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_updateoverlay) structure that describes how to modify the overlay.

## Return value

**pfnUpdateOverlayCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The overlay object was successfully modified.|
|D3DDDIERR_NOTAVAILABLE|pfnUpdateOverlayCb failed because of a lack of overlay hardware or bandwidth.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|
|E_OUTOFMEMORY|pfnUpdateOverlayCb could not allocate memory that was required for it to complete.|

This function might also return other HRESULT values.

## See also

[D3DDDICB_UPDATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_updateoverlay)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)