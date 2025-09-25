# PFND3DDDI_SETSCISSORRECT callback function

## Description

The *SetScissorRect* function marks a portion of a render target that rendering is confined to.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pRect* [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that specifies the 2-D portion of the render target to confine rendering to.

## Return value

*SetScissorRect* returns S_OK or an appropriate error result if the 2-D resource is not successfully marked.

## See also

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)