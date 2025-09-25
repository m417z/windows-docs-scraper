# _D3DDDIARG_CREATEDEVICE structure

## Description

The D3DDDIARG_CREATEDEVICE structure contains information that describes the display device to create.

## Members

### `hDevice` [in/out]

A handle to the display device (graphics context). On input to the [CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice) function, **hDevice** specifies the handle that the driver should use when it calls back into the Microsoft Direct3D runtime.

The driver generates a unique handle and passes it back to the Direct3D runtime. On output from the [CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice) function, **hDevice** specifies the handle that the Direct3D runtime uses in subsequent driver calls to identify the display device.

### `Interface` [in]

The Direct3D/DirectDraw interface version (for example, 7, 8, or 9) that creates the device.

### `Version` [in]

A number that the driver can use to identify when the Direct3D/DirectDraw runtime was built. For example, the driver can use the version number to differentiate between a runtime that is released with Windows Vista and a runtime that is released with a subsequent service pack, which might contain a fix that the driver requires.

### `pCallbacks` [in]

A pointer to a [D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks) structure that contains a table of Direct3D runtime callback functions that the driver can use.

### `pCommandBuffer` [in]

Obsolete. To receive a pointer to the first buffer that the user-mode display driver can use to batch commands, the driver must first call the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function to create a context for the newly created device.

### `CommandBufferSize` [in]

Obsolete.

### `pAllocationList` [in]

Obsolete. To receive an array of [D3DDDI_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist) structures for the starting allocation list, the driver must first call the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function to create a context for the newly created device.

### `AllocationListSize` [in]

Obsolete.

### `pPatchLocationList` [in]

Obsolete. To receive an array of [D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures for the starting patch-location list, the driver must first call the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function to create a context for the newly created device.

### `PatchLocationListSize` [in]

Obsolete.

### `pDeviceFuncs`

 [out] A pointer to a [D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs) structure that the user-mode display driver fills with a table of its functions. The Direct3D runtime uses these functions to communicate with the user-mode display driver.

### `Flags` [in]

A [D3DDDI_CREATEDEVICEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_createdeviceflags) structure that identifies how to create the device.

### `CommandBuffer`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[D3DDDI_CREATEDEVICEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_createdeviceflags)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)