# PFND3D10DDI_SO_SETTARGETS callback function

## Description

The *SoSetTargets* function sets stream output target resources.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `NumBuffers` [in]

The number of elements in the array that *phResource* specifies.

### `ClearTargets` [in]

The number of handles to stream output target resources that represents the difference between the previous number of stream output target resources (before the Microsoft Direct3D runtime calls *SoSetTargets*) and the new number of stream output target resources.

Note that the number that i*ClearTargets* specifies is only an optimization aid because the user-mode display driver could calculate this number.

### `unnamedParam4`

*phResource* [in]

An array of handles to the stream output target resources to set. Note that some handle values can be **NULL**.

### `unnamedParam5`

*pOffsets* [in]

An array of offsets, in bytes, into the stream output target resources in the array that *phResource* specifies.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The range of stream output target resources between the number that the *SOTargets* parameter specifies and the maximum number of stream output target resources that are allowed is required to contain all **NULL** or unbound values. The number that the *ClearTargets* parameter specifies informs the driver about how many bind points the driver must clear out for the current operation. If the previous call to *SoSetTargets* passed a value of 2 in *SOTargets*and the current call to *SoSetTargets* passes a value of 4 in *SOTargets*, the current call to *SoSetTargets* also passes a value of 0 in the *ClearTargets* parameter. If the next successive call to *SoSetTargets* passes a value of 1 in *SOTargets*, the successive call also passes a value of 3 (4 - 1) in *ClearTargets*.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Microsoft Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *SOTargets* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)