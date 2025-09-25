# DXGI_GAMMA_CONTROL_CAPABILITIES structure

## Description

The DXGI_GAMMA_CONTROL_CAPABILIITES structure describes gamma capabilities.

## Members

### `ScaleAndOffsetSupported` [out]

A BOOL value that indicates whether the device supports scale and offset. **TRUE** indicates that the device supports scale and offset; **FALSE** indicates that the device does not support scale and offset.

### `MaxConvertedValue` [out]

A single-precision float vector for the maximum converted value for the gamma control.

### `MinConvertedValue` [out]

A single-precision float vector for the minimum converted value for the gamma control.

### `NumGammaControlPoints` [out]

The number of elements in the array that the **ControlPointPositions** member specifies.

### `ControlPointPositions` [out]

An array of single-precision float vectors that describe the gamma control point positions.

## See also

[DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_get_gamma_control_caps)

[GetGammaCapsDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)