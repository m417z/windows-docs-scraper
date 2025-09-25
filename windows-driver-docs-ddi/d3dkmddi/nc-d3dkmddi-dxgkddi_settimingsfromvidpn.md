# DXGKDDI_SETTIMINGSFROMVIDPN callback function

## Description

DXGKDDI_SETTIMINGSFROMVIDPN is called to set or modify the display timings on an adapter. This DDI replaces DxgkDdiCommitVidPn.

## Parameters

### `hAdapter` [in]

Identifies the adapter upon which the display timings should be set.

### `pSetTimings` [in, out]

A pointer to a [DXGKARG_SETTIMINGSFROMVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_settimingsfromvidpn) structure that describes the display timings to be set.

## Return value

If this routine succeeds, it returns STATUS_SUCCESS.

**Note** The driver should always return a success code unless there is an error in the parameters or a failure to process the request. If the driver is unable to set one or more paths as requested, it should describe the condition using the output fields but still report success.

## Remarks

The kernel mode driver evaluates the parameters and initiates the changes if no conditions prevent attempting them. If conditions such as exceeding target bandwidth limitations prevent the changes from being made, the driver should describe the conditions. If changing the timings would be possible but requires preparation work to be completed first, the driver should indicate that in the output flags.

This function is always called at PASSIVE level.

This function is registered by DriverEntry of the display miniport driver.

Starting in WDDM 2.6, when display synchronization is available and more than one display is to be enabled, the OS will indicate that the displays should be synchronized in the DXGKDDI_SETTIMINGSFROMVIDPN call. Each path to be synchronized will have a non-zero value in the **SyncLockGroup** bit-field and the selected synchronization style in the **SyncLockStyle** field, both of which are in the [DXGK_SET_TIMING_PATH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_set_timing_path_info) structure.