# DrvSaveScreenBits function

## Description

The **DrvSaveScreenBits** function causes a display driver to save or restore a given rectangle of the displayed image.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface.

### `iMode`

Specifies the operation to perform. This parameter can be one of the following values:

#### SS_SAVE

The driver should save the data from the rectangle defined by *prcl*. The driver is responsible for managing this data in its [off-screen memory](https://learn.microsoft.com/windows-hardware/drivers/). The *ident* parameter is ignored.

Upon success, **DrvSaveScreenBits** should return an identifier for the saved data. The driver can return a handle or even a pointer to its off-screen memory. This function returns zero if it fails.

#### SS_RESTORE

The driver should restore the data identified by *ident* to the rectangle *prcl* on the display; that is, the driver should restore the bitmap to its original position. The driver can assume that the rectangle at *prcl* is exactly the same size as the rectangle that was saved. The data should be discarded after this call.

**DrvSaveScreenBits** should return **TRUE** if the data has been restored to the display, or **FALSE** if the data cannot be restored.

#### SS_FREE

The data identified by *ident* is no longer needed and can be freed. The value of *prcl* is undefined and should not be used. The driver should not restore the saved rectangle to the display.

**DrvSaveScreenBits** should return **TRUE**.

### `ident`

Pointer to a driver-defined value that was returned by a previous call to **DrvSaveScreenBits** if *iMode* is SS_RESTORE or SS_FREE. The driver should ignore this parameter when *iMode* is SS_SAVE.

### `prcl`

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the portion of the screen to be saved or restored.

## Return value

The return value is dependent on the value of the *iMode* parameter.

## Remarks

Some display drivers might be able to move data to or from off-screen device memory much faster than the area can be redrawn. This might be useful when Window Manager must display a menu or dialog box.

**DrvSaveScreenBits** is optional for display drivers.

## See also

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)