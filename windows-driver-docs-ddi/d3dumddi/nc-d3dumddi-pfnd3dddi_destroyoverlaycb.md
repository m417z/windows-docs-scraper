# PFND3DDDI_DESTROYOVERLAYCB callback function

## Description

The **pfnDestroyOverlayCb** function disables the overlay hardware and destroys the kernel-mode overlay object.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_DESTROYOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_destroyoverlay) structure that contains a handle to the overlay object to be disabled.

## Return value

**pfnDestroyOverlayCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The overlay object was successfully disabled.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## See also

[D3DDDICB_DESTROYOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_destroyoverlay)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)