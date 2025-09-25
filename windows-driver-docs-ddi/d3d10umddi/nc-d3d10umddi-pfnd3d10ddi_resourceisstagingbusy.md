# PFND3D10DDI_RESOURCEISSTAGINGBUSY callback function

## Description

The *ResourceIsStagingBusy* function determines whether a resource is currently being used by the graphics pipeline.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hResource* [in]

A handle to the resource.

## Return value

*ResourceIsStagingBusy* returns a Boolean value that specifies whether the resource that the *hResource* parameter specifies is currently being used by the graphics pipeline. **TRUE** indicates that the graphics pipeline currently uses the resource; **FALSE** indicates that the graphics pipeline currently does not use the resource.

## Remarks

The Microsoft Direct3D runtime call to *ResourceIsStagingBusy* is roughly equivalent to the call to the [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function with the D3D10_DDI_MAP_FLAG_DONOTWAIT flag set in the *Flags* parameter, except that *ResourceMap* can perform only one subresource at a time and *ResourceIsStagingBusy* can be called while some of the subresources are currently mapped.

The user-mode display driver is not required to flush any partially built command buffer. If the driver is resident in the partially built command buffer, the driver qualifies as busy.

*ResourceIsStagingBusy* should not encounter any errors. However, *ResourceIsStagingBusy* might call the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function for critical errors.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)