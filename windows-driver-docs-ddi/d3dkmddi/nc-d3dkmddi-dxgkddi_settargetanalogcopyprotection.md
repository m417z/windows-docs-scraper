# DXGKDDI_SETTARGETANALOGCOPYPROTECTION callback function

## Description

Sets the analog copy protection on the specified target id. This is functionally equivalent to the DxgkDdiUpdateActiveVidPnPresentPath in previous WDDM versions if only the D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION is changed.

## Parameters

### `hAdapter`

Identifies the adapter.

### `pSetTargetAnalogCopyProtectionArg`

A pointer to a DXGKARG_SETTARGETANALOGCOPYPROTECTION structure that provides the target id and the analog content protection parameters being requested.

## Return value

If this routine succeeds, it returns STATUS_SUCCESS.

## Remarks

This is an optional DDI so the function pointer in the DRIVER_INITIALIZATION_DATA should be set to null if the DDI is not implemented for every adapter supported by the driver. Since analog content protection is only supported on analog targets and may not be supported through dongles it is increasingly likely over time that drivers will have no need to support this DDI.

The OEMCopyProtection byte array which is part of the D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION structure used in the old DDI has been dropped as it was reserved and never defined so always contained zeroes.

This function is always called at PASSIVE level so the supporting code should be made pageable.