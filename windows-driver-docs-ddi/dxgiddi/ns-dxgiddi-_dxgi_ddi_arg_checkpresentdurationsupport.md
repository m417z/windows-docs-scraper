# _DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT structure

## Description

Used in a call to the [pfnCheckPresentDurationSupport(DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-_dxgi_ddi_arg_checkpresentdurationsupport) function to check details on hardware device support for seamlessly switching to a new monitor refresh rate.

## Members

### `hDevice`

A handle to the display device (graphics context) on which the driver performs the presentation. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `VidPnSourceId`

The zero-based video present network (VidPN) source identification number of the input for which the hardware support is queried.

### `DesiredPresentDuration`

The desired duration of a single present operation, in units of 100 nanoseconds.

### `ClosestSmallerDuration`

The smallest supported desired duration of a single present operation on the given VidPN source, in units of 100 nanoseconds. The value must be ≤ **DesiredPresentDuration**.

See Remarks for more limitations on this value.

### `ClosestLargerDuration` [out]

The largest supported desired duration of a single present operation on the given VidPN source, in units of 100 nanoseconds. The value must be ≥ **DesiredPresentDuration**.

See Remarks for more limitations on this value.

## Remarks

Either **ClosestSmallerDuration** or **ClosestLargerDuration** can be zero. However, if both are zero, the device cannot seamlessly switch to a new refresh rate.

If both **ClosestSmallerDuration** and **ClosestLargerDuration** have the same value as **DesiredPresentDuration**, the device can precisely match **DesiredPresentDuration**.

The difference between **DesiredPresentDuration** and **ClosestSmallerDuration** (or **ClosestLargerDuration**) represents the driver’s knowledge of the device capabilities, but there will be additional error during execution. The final accuracy of the device when using per-present durations should typically be the same as the accuracy using existing presentation modes.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[pfnCheckPresentDurationSupport(DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-_dxgi_ddi_arg_checkpresentdurationsupport)