# D2D1_DC_INITIALIZE_MODE enumeration

## Description

 Specifies how a device context is initialized for GDI rendering when it is retrieved from the render target.

## Constants

### `D2D1_DC_INITIALIZE_MODE_COPY:0`

The current contents of the render target are copied to the device context when it is initialized.

### `D2D1_DC_INITIALIZE_MODE_CLEAR:1`

The device context is cleared to transparent black when it is initialized.

### `D2D1_DC_INITIALIZE_MODE_FORCE_DWORD:0xffffffff`

## Remarks

Use this enumeration with the [ID2D1GdiInteropRenderTarget::GetDC](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1gdiinteroprendertarget-getdc) method to specify how the device context is initialized for GDI rendering.

## See also

[ID2D1GdiInteropRenderTarget::GetDC](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1gdiinteroprendertarget-getdc)