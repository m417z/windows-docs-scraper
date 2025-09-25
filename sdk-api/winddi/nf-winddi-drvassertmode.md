# DrvAssertMode function

## Description

The **DrvAssertMode** function sets the mode of the specified physical device to either the mode specified when the PDEV was initialized or to the default mode of the hardware.

## Parameters

### `dhpdev` [in]

Handle to the PDEV describing the hardware mode that should be set when *bEnable* is **TRUE**.

### `bEnable` [in]

Specifies the mode to which the hardware is to be set. If this parameter is **TRUE**, the driver should set the hardware to the original mode specified by the initialized PDEV. Otherwise, if this parameter is **FALSE**, the driver should set the hardware to its default mode so the video miniport driver can assume control.

## Return value

**DrvAssertMode** returns **TRUE** if it successfully changed the display mode; it returns **FALSE** if it was unable to change the display mode. A driver is permitted to return **FALSE** from a **DrvAssertMode** call with *bEnable* set to **FALSE**. A driver must return **TRUE** from a **DrvAssertMode** call with *bEnable* set to **TRUE**; that is, a driver cannot fail enabling a mode that was previously enabled.

## Remarks

GDI calls **DrvAssertMode** when it is required to switch among multiple desktops on a single display surface. To switch from one PDEV to another, GDI calls **DrvAssertMode** with the *bEnable* parameter set to **FALSE** for one PDEV, and **TRUE** for the other. To revert to the original PDEV, **DrvAssertMode** is called with *bEnable* set to **FALSE**, followed by another call to **DrvAssertMode**, with *bEnable* set to **TRUE** and **dhpdev** set to the original PDEV.

If the physical device is palette-managed, GDI will call [DrvSetPalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsetpalette) to reset the device's palette. The driver does not then need to keep track of the current pointer state because Window Manager selects the correct pointer shape and moves it to the current position. The console manager ensures that desktops are properly redrawn.

**DrvAssertMode** must be implemented in display drivers.

## See also

[DrvGetModes](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetmodes)

[DrvSetPalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsetpalette)