# PFND3D10DDI_SETVIEWPORTS callback function

## Description

The *SetViewports* function sets viewports.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `NumViewports` [in]

The total number of viewports that the *pViewports* parameter specifies.

### `ClearViewports` [in]

The number of viewports after the number of viewports that *NumViewports* specifies to be set to **NULL**. This number represents the difference between the previous number of viewports (that is, when the Microsoft Direct3D runtime previously called *SetViewports*) and the new number of viewports.

Note that the number that *ClearViewports* specifies is only an optimization aid because the user-mode display driver could calculate this number.

### `unnamedParam4`

*pViewports* [in]

An array of [D3D10_DDI_VIEWPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_viewport) structures for the viewports to set.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

Viewports specify the transformation post clip to the output render target and depth stencil resources. Any viewports that are not defined in a call to *SetViewports* are set to **NULL**. A **NULL** viewport is defined as follows.

```cpp
struct D3D10_DDI_VIEWPORT {
  FLOAT  TopLeftX = NaN;
  FLOAT  TopLeftY = NaN;
  FLOAT  Width = NaN;
  FLOAT  Height = NaN;
  FLOAT  MinDepth = NaN;
  FLOAT  MaxDepth = NaN;
} D3D10_DDI_VIEWPORT;</pre>
```

This definition implies that the viewport is off.

The user-mode display driver must set all viewports atomically as one operation.

Although the *NumViewports* parameter specifies the number of viewports in the array that the *pViewports* parameter specifies, some values in the array can be **NULL**.

The range of viewports between the number that *NumViewports* specifies and the maximum number of viewports that are allowed is required to contain all **NULL** or unbound values. The number that the *ClearViewports* parameter specifies informs the driver about how many viewports the driver must clear out for the current atomic operation.

If the previous call to *SetViewports* passed a value of 2 in the *NumViewports* parameter and the current call to *SetViewports* passes a value of 4 in *NumViewports*, the current call to *SetViewports* also passes a value of 0 in the *ClearViewports* parameter. If the next successive call to *SetViewports* passes a value of 1 in *NumViewports*, the successive call also passes a value of 3 (4 - 1) in *ClearViewports*.

When the value of clear viewports is requested during user-mode query operations, the value is the difference between the maximum number of viewports and the viewports value.

*SetViewports* ensures that the viewports are valid. That is, *SetViewports* ensures that the dimensions of the viewports are within range (D3D10_VIEWPORT_BOUNDS_MIN, D3D10_VIEWPORT_BOUNDS_MAX, D3D10_MIN_DEPTH, and D3D10_MAX_DEPTH). *SetViewports* also ensures that no coordinates are NaN and flushes denormalized float values to zero.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Microsoft Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *SetViewports* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[D3D10_DDI_VIEWPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_viewport)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)