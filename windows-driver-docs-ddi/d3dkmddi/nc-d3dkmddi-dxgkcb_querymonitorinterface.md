# DXGKCB_QUERYMONITORINTERFACE callback function

## Description

**DXGKCB_QUERYMONITORINTERFACE** obtains a pointer to a [**DXGK_MONITOR_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface) structure, which contains pointers to functions that the display miniport driver can call to obtain other interfaces that provide access to monitor descriptors, modes, and frequency ranges.

## Parameters

### `hAdapter` [in]

A handle that represents a display adapter. The VidPN manager provided this handle to the display miniport driver in a call to [**DxgkDdiRecommendFunctionalVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn), [**DxgkDdiIsSupportedVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn), [**DxgkDdiEnumVidPnCofuncModality**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality), or [**DxgkDdiCommitVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn).

### `MonitorInterfaceVersion` [in]

A value from the [**DXGK_MONITOR_INTERFACE_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_monitor_interface_version) enumeration that specifies the version of the monitor interface being requested.

### `ppMonitorInterface` [out]

A pointer to a pointer to the [**DXGK_MONITOR_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface) structure.

## Return value

**DXGKCB_QUERYMONITORINTERFACE** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbQueryMonitorInterface** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGK_MONITOR_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitor_interface)

[**DXGK_MONITOR_INTERFACE_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_monitor_interface_version)