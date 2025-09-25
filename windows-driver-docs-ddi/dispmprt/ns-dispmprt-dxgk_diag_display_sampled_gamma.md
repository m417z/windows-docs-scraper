# DXGK_DIAG_DISPLAY_SAMPLED_GAMMA structure

## Description

The **DXGK_DIAG_DISPLAY_SAMPLED_GAMMA** structure provides gamma samples during diagnostic data collection.

## Members

### `Red` [out]

MAX_NUM_OF_GAMMA_SAMPLES_FOR_DIAGNOSTICS gamma samples from the red channel, where the samples are equally spaced as much as is possible.

### `Green` [out]

MAX_NUM_OF_GAMMA_SAMPLES_FOR_DIAGNOSTICS gamma samples from the green channel, where the samples are equally spaced as much as is possible.

### `Blue` [out]

MAX_NUM_OF_GAMMA_SAMPLES_FOR_DIAGNOSTICS gamma samples from the blue channel, where the samples are equally spaced as much as is possible.

### `ColorMatrix` [out]

A 3X3 matrix should contain any global scalar multiplier baked in if applicable. If the driver has 3X4 matrix then it is ok to just ignore the last column.

## Remarks

The **DXGK_DIAG_DISPLAY_SAMPLED_GAMMA** structure is a member of the [**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive) structure, which is passed in calls to [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive) during diagnostic data collection.

In Windows 10 version 2004 and later, the gamma and CSC matrix requested by the operating system is global and not per plane. For the sampled gamma values, drivers should return the gamma/LUT values from the re-gamma stage so that the OS can get as close to the final gamma curve being applied on the pixels going out of the wire. If internally the drivers have any per plane gamma/LUT then they should just return the values for plane 0. Drivers should not do any complex calculations for the sampled gamma values for the diagnostic interface.

## See also

[**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive)

[**DXGKARG_GETDISPLAYSTATEINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystateintrusive)

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)