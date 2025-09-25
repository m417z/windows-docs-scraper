# PFND3D10DDI_SETSCISSORRECTS callback function

## Description

The *SetScissorRects* function marks portions of render targets that rendering is confined to.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `NumRects` [in]

The total number of render-target portions that the *pRects* parameter specifies.

### `ClearRects` [in]

The number of render-target portions after the number of render-target portions that *NumScissorRects* specifies to be set to **NULL**. This number represents the difference between the previous number of render-target portions (that is, when the Microsoft Direct3D runtime previously called *SetScissorRects*) and the new number of render-target portions.

Note that the number that *ClearScissorRects* specifies is only an optimization aid because the user-mode display driver could calculate this number.

### `unnamedParam4`

*pRects* [in]

An array of [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structures for the render-target portions to mark.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The D3D10_DDI_RECT structure is defined as a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure.

```cpp
typedef RECT D3D10_DDI_RECT;
```

The user-mode display driver must set all render-target portions atomically as one operation.

Although the *NumScissorRects* parameter specifies the number of render-target portions in the array that the *pRects* parameter specifies, some values in the array can be **NULL**.

The range of render-target portions between the number that *NumScissorRects* specifies and the maximum number of render-target portions that are allowed is required to contain all **NULL** or unbound values. The number that the *ClearScissorRects* parameter specifies informs the driver about how many render-target portions the driver must clear out for the current atomic operation.

If the previous call to *SetScissorRects* passed a value of 2 in the *NumScissorRects* parameter and the current call to *SetScissorRects* passes a value of 4 in *NumScissorRects*, the current call to *SetScissorRects* also passes a value of 0 in the *ClearScissorRects* parameter. If the next successive call to *SetScissorRects* passes a value of 1 in *NumScissorRects*, the successive call also passes a value of 3 (4 - 1) in *ClearScissorRects*.

When the value of clear render-target portions is requested during user-mode query operations, the value is the difference between the maximum number of render-target portions and the render-target portions value.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Microsoft Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *SetScissorRects* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)