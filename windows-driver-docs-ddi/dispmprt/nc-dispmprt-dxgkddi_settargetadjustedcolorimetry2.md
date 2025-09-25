# DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY2 callback function

## Description

Reports the colorimetry values selected by the OS for a target. The OS will call this routine whenever any of the values in the [DXGK_COLORIMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_colorimetry) changes or the **SdrWhiteLevel** in [DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES3 structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes3) changes for a target.

## Parameters

### `hAdapter`

A handle to an adapter.

### `pArgSetTargetAdjustedColorimetry`

Pointer to a [DXGKARG_SETTARGETADJUSTEDCOLORIMETRY2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkarg_settargetadjustedcolorimetry2) structure containing the colorimetry related fields for the monitor attached to this target after the OS has processed the display device descriptor, all overrides and any adjustments.

## Return value

The driver returns STATUS_SUCCESS if it has updates its colorimetry values based on the supplied data.

If the driver fails, the OS will revert to standard SDR values for all parameters (i.e. 709 primaries, 2.2 gamma and 8-bit per color component RGB wire format), but it will not call the driver as this should never fail.

## Prototype

```cpp
//Declaration

DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY2 DxgkddiSettargetadjustedcolorimetry2;

// Definition

NTSTATUS DxgkddiSettargetadjustedcolorimetry2
(
	IN_CONST_HANDLE hAdapter
	IN_PDXGKARG_SETTARGETADJUSTEDCOLORIMETRY2 pArgSetTargetAdjustedColorimetry
)
{...}

```

## Remarks

This callback function replaces [DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_settargetadjustedcolorimetry) and is more extensible in the future, as it contains a pointer to the DXGKARG_SETTARGETADJUSTEDCOLORIMETRY2 that can change over new releases.

## See also