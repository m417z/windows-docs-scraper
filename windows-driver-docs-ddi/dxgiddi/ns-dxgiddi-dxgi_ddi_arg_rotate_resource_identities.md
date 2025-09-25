# DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES structure

## Description

Describes a list of resources to rotate.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) on which the driver rotates resources. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `pResources` [in]

A pointer to an array of handles to the resources to rotate.

Beginning in Windows 8, the driver must support rotation of stereo back buffers.

### `Resources` [in]

The number of elements in the *pResources* array.

## See also

[RotateResourceIdentitiesDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)