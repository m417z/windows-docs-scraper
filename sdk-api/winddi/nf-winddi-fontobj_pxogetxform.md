# FONTOBJ_pxoGetXform function

## Description

The **FONTOBJ_pxoGetXform** function retrieves the notional-to-device transform for the specified font.

## Parameters

### `pfo`

Pointer to the [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure for which the transform is to be retrieved.

## Return value

The return value is a pointer to an [XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85)) structure that describes the transform. The XFORMOBJ structure can be used by the **XFORMOBJ_*****Xxx*** service routines. The XFORMOBJ structure assumes that:

* The distance between the pixels is in device space units.
* Both notional and device space have positive values of y in the top-to-bottom direction.

If the font is a raster font, the return value is **NULL**.

## Remarks

The driver needs the notional-to-device transform to realize a driver-supplied font.

## See also

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)

[XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85))