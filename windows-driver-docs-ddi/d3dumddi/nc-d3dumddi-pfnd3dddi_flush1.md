# PFND3DDDI_FLUSH1 callback function

## Description

Called by the Microsoft Direct3D runtime to submit outstanding hardware commands that are in the hardware command buffer to the display miniport driver. Must be implemented by Windows Display Driver Model (WDDM) 1.3 and later user-mode display drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `FlushFlags`

A value from the [D3DDDI_FLUSH_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_flush_flags) enumeration that indicates whether the driver should continue to submit command buffers if there have been no new commands.

## Return value

If this routine succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[D3DDDI_FLUSH_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_flush_flags)