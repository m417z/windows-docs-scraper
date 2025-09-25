# D3D10_DDI_MAP_FLAG enumeration

## Description

The D3D10_DDI_MAP_FLAG enumeration type contains flags that identify how to map to a subresource in a call to the driver's [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function.

## Constants

### `D3D10_DDI_MAP_FLAG_DONOTWAIT`

The driver can call the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function to set the ERR_WASSTILLDRAWING error code if contention exists between an application and hardware when the driver receives the call to [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap).

### `D3D10_DDI_MAP_FLAG_MASK`

A mask value that indicates the valid bitfields in a bitwise OR combination of the values from this enumeration.

## See also

[ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)