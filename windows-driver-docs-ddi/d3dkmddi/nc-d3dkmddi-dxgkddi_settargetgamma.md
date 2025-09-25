# DXGKDDI_SETTARGETGAMMA callback function

## Description

Allows the gamma LUT to be set on a path which is identified by the target id.

**Note** This is functionally equivalent to the DxgkDdi_UpdateActiveVidPnPresentPath in previous WDDM versions if only the D3DKMDT_GAMMA_RAMP field is changed.

## Parameters

### `hAdapter`

A handle that identifies the adapter.

### `pSetTargetGammaArg`

A pointer to a [DXGKARG_SETTARGETGAMMA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_settargetgamma) structure that provides the target id to be modified and provides the gamma ramp to be set.

## Return value

If this routine succeeds, it returns STATUS_SUCCESS.

**Note** WDDM 2.2 has cap bits for each type of supported gamma ramp so unsupported types will be skipped by the OS. Therefore, if the type is supported there should be no reason to fail the call other than unavoidable failures like monitor unplug.

## Remarks

This function is always called at PASSIVE level so the supporting code should be made pageable.