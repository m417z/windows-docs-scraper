# DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY callback function

## Description

Reports the colorimetry values selected by the OS for a target.

## Parameters

### `hAdapter` [in]

[in] Identifies the adapter.

### `TargetId` [in]

[in] The identifier of a display adapter's video present target.

### `AdjustedColorimetry` [in]

[in] A DXGK_COLORIMETRY structure containing the colorimetry related fields for the monitor attached to this target after the OS has processed the display device descriptor, all overrides and any adjustments.

## Return value

The driver returns STATUS_SUCCESS if it has updates its colorimetry values based on the supplied data.

If the driver fails, the OS will revert to standard SDR values for all parameters, 709 primaries, 2.2 gamma and 8-nit per color component RGB wire format but it will not call the driver as this should never fail. Instead, the driver should also update its internal representation of the display device to be standard SDR.

## Remarks

Since current display devices have been found to have incomplete and inaccurate descriptions of their colorimetry related parameters, overrides are necessary. The overrides take two forms: driver overrides and OS overrides for invalid parameters. In future OS versions it is expected that additional overrides will be implemented. To keep the driver in sync with the parameters that the OS is using, the OS will call DxgkDdiSetTargetAdjustedColorimetry for each target.

Typically, this call will only be made once after the driver has been queried for overrides and the OS validation has completed but before the display is activated. When the OS has other forms of overrides it is possible that they will arrive after the display is already active. In this case, the OS will still update the driver which is expected to make any necessary updates to its display pipeline within two frames. If necessary, the driver should glitch the display output in order to apply the change.

The FormatBitDepths and StandardColorimetryFlags in the DXGK_COLORIMETRY are zeroed as these are capability fields so only valid in queries.

This function is always called at PASSIVE level so the supporting code should be made pageable where possible.