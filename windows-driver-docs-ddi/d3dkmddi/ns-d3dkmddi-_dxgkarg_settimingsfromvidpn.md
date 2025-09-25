# _DXGKARG_SETTIMINGSFROMVIDPN structure

## Description

Used to hold the arguments for [DXGKDDI_SETTIMINGSFROMVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn).

## Members

### `hFunctionalVidPn`

A handle to a D3DKMDT_HVIDPN that represents a functional VidPn which describes the display configuration the OS is attempting to apply.

The D3DKMDT_HVIDPN data type is defined in *D3dkmdt.h*.

### `SetFlags`

 A [DXGK_SET_TIMING_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_set_timing_flags) structure that requests specific actions from the driver on the SetTimingsFromVidPn call.

### `pResultsFlags`

Pointer to a [DXGK_SET_TIMING_RESULTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_set_timing_results) structure that the driver should use to report overall results from the [SetTimingsFromVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn) call.

### `PathCount`

Number of pointers in the array pointed to by **pSetTimingPathInfo**.

### `pSetTimingPathInfo`

An array of pointers to [DXGK_SET_TIMING_PATH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_set_timing_path_info) structures that specify per path details of the timings to be set. It also allows feedback from the driver on additional work the OS needs to do either before the timings changes can be made, or after changes are complete.