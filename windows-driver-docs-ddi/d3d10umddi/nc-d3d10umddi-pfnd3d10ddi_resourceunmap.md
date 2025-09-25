# PFND3D10DDI_RESOURCEUNMAP callback function

## Description

The *ResourceUnmap* function unmaps a subresource of a resource.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hResource* [in]

A handle to the resource to unmap.

### `unnamedParam3`

*Subresource* [in]

An index that indicates the subresource to unmap.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver can call [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) to set the **D3DDDIERR_DEVICEREMOVED** error code; however, the driver is not required to set **D3DDDIERR_DEVICEREMOVED** if the device was removed. Calls to **pfnSetErrorCb** to set any other error code are critical.

### Restrictions on input values

For Windows Display Driver Model (WDDM) 1.3 and later drivers, the Microsoft Direct3D runtime supplies a restricted set of input values used by this function. For a list of all restricted values, see [Direct3D rendering performance improvements](https://learn.microsoft.com/windows-hardware/drivers/display/direct3d-rendering-performance-improvements).

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)