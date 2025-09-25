# DrvQueryDeviceSupport function

## Description

The **DrvQueryDeviceSupport** function returns requested device-specific information.

## Parameters

### `pso`

Caller-supplied pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure.

### `pxlo`

Caller-supplied pointer to an [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure.

### `pxo`

Caller-supplied pointer to an [XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85)) structure.

### `iType`

Caller-supplied bit flag indicating the type of information being requested. One of the following flags can be specified:

| Flag | Definition |
| --- | --- |
| QDS_CHECKJPEGFORMAT | The buffer pointed to by *pvIn* contains a JPEG-compressed image. The function must return **TRUE** if the device can print the image. Otherwise it must return **FALSE**. |
| QDS_CHECKPNGFORMAT | The buffer pointed to by *pvIn* contains a PNG-compressed image. The function must return **TRUE** if the device can print the image. Otherwise it must return **FALSE**. |

### `cjIn`

Caller-supplied size of the buffer pointed to by *pvIn*.

### `pvIn` [in]

Caller-supplied pointer to an input buffer.

### `cjOut`

Caller-supplied size of the buffer pointed to by *pvOut*.

### `pvOut` [out]

Caller-supplied pointer to an output buffer.

## Return value

If the operation succeeds, the function should return **TRUE**; otherwise it should return **FALSE**.

## Remarks

If the QDS_CHECKJPEGFORMAT or QDS_CHECKPNGFORMAT flag is set in *iType*, the following rules apply:

* The *pvIn* parameter points to a buffer containing a JPEG-compressed or PNG-compressed image. The driver must return **TRUE** if the image can be printed, or **FALSE** otherwise.
* The *pxlo* parameter is valid but the only information of interest is the [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure's **flXlate** member. If either the XO_HOST_ICM or XO_DEVICE_ICM flag is set, the driver must only return **TRUE** if it can convert the image's color space to the printer's color space (or if the two color spaces are the same). For more information, see [Color Management of JPEG and PNG Images](https://learn.microsoft.com/windows-hardware/drivers/print/color-management-of-jpeg-and-png-images).

For more information about supporting JPEG and PNG compressed images, see the Remarks section for [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo).

## See also

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85))

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)