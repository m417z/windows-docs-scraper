# DXGK_MODE_BEHAVIOR_FLAGS structure

## Description

The high-level mode and setting behaviors which the OS may request. The same union is used in different fields to describe the input request to the driver and the output results from the driver.

## Members

### `PrioritizeHDR`

If set as input, the driver should prioritize high dynamic range (HDR) support when enumerating display modes and setting display modes over other constraints such as balancing modes available on different targets, supporting high frequencies or high resolutions. If not set, the driver should use its default policies for prioritizing the modes made available to the OS.

### `ColorimetricControl`

Controls the known color enhancements that affect the color accuracy of the display that the OS is not aware of. A value of one for **Request.ColorimetricControl** indicates that the OS is requesting the driver to disable any color enhancements that affect the color accuracy of the display. A zero value of **Request.ColorimetricControl** indicates the OS is informing the driver it is free to enable the any color enhancements that it had disabled.

### `Reserved`

Reserved.

### `Value`

## -union-fields

## Remarks

The following table describes how the driver should set the value of **ColorimetricControl** in the **Satisfied** and **NotSatisfied** members of the [DXGKARG_CONTROLMODEBEHAVIOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_controlmodebehavior) structure.

| Driver support | Satisfied.ColorimetricControl | NotSatisfied.ColorimetricControl |
|:-- | -- | -- |
| Driver supports controlling the color enhancements and successfully changed the state requested in **Request.ColorimetricControl** | 1| 0|
| Driver supports controlling the color enhancements but was unsuccessful in changing the state requested in **Request.ColorimetricControl** | 0| 1|
| Driver does not support controlling the color enhancement| 0| 0|

## See also

[DXGKARG_CONTROLMODEBEHAVIOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_controlmodebehavior)