# DXGKDDI_RECOMMENDMONITORMODES callback function

## Description

The *DxgkDdiRecommendMonitorModes* function inspects the monitor source mode set that is associated with a particular video present target and possibly adds modes to the set.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pRecommendMonitorModes` [in]

A pointer to a [DXGKARG_RECOMMENDMONITORMODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_recommendmonitormodes) structure that contains function arguments.

## Return value

*DxgkDdiRecommendMonitorModes* returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_NO_MEMORY|The function failed because it was unable to allocate enough memory.|

The miniport driver should pass through any error code that it gets from the operating system for which it does not have a fallback code path.

## Remarks

*DxgkDdiRecommendMonitorModes* should be made pageable.

## See also

[Monitor Source Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)