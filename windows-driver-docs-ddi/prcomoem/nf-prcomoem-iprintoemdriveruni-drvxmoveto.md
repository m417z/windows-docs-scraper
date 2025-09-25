# IPrintOemDriverUni::DrvXMoveTo

## Description

The `IPrintOemDriverUni::DrvXMoveTo` method is provided by the Unidrv driver so that a [rendering plug-in](https://learn.microsoft.com/windows-hardware/drivers/print/rendering-plug-ins) can notify the driver of cursor x-position changes.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `x`

Caller-supplied value representing the number of units the cursor should be moved. The unit is defined by the MV_GRAPHICS flags in *dwFlags*.

### `dwFlags`

One or more of the following caller-supplied bit flags:

| Flag | Definition |
| --- | --- |
| MV_GRAPHICS | If set, the *x* parameter's value is expressed in dots, based on the printer's current resolution. For example, if the x resolution is 150 DPI and *x* is 75, the movement is ?? inch.<br><br>If not set, the *x* parameter's value is expressed in master units. For example, if the x master unit is 600 and *x* is 300, the movement is ?? inch. |
| MV_PHYSICAL | If set, the *x* parameter's value is relative to the cursor origin.<br><br>If not set, the *x* parameter's value is relative to the printable area's origin.<br><br>Cannot be set if MV_RELATIVE is set. |
| MV_RELATIVE | If set, specifies that the cursor should be moved *x* units from its current position.<br><br>If not set, specifies that the cursor should be moved *x* units from its origin. |
| MV_UPDATE | If set, specifies that Unidrv should update its current calculation of the cursor position without actually moving the cursor. (Should be set if [IPrintOemUni::ImageProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-imageprocessing) has moved the cursor.)<br><br>If not set, specifies that Unidrv should update its current calculation of the cursor position and also move the cursor. |

### `piResult` [out]

Receives the method-supplied result of subtracting the actual new cursor position from the requested new cursor position. This value might be zero, but it is always nonnegative.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemDriverUni::DrvXMoveTo` and [IPrintOemDriverUni::DrvYMoveTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvymoveto) methods allow a rendering plug-in to send image data to the printer spooler without causing the printer driver to lose track of the printer's cursor position. If you provide an [IPrintOemUni::ImageProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-imageprocessing) method that sends image data directly to the print spooler instead of returning it to the printer driver, the method should call `IPrintOemDriverUni::DrvXMoveTo` and `IPrintOemDriverUni::DrvYMoveTo`.

Either of two techniques can be used for updating the cursor position:

* Whenever an **IPrintOemUni::ImageProcessing** method needs to update the cursor position, it can call `IPrintOemDriverUni::DrvXMoveTo` or `IPrintOemDriverUni::DrvYMoveTo` with the MV_UPDATE flag cleared. This causes Unidrv to send cursor commands to the print spooler and to update its internal calculation of the current cursor position.
* The **IPrintOemUni::ImageProcessing** method can update the cursor by sending cursor commands directly to the print spooler. When the method has finished its spooling operation, it can call `IPrintOemDriverUni::DrvXMoveTo` or `IPrintOemDriverUni::DrvYMoveTo` with the MV_UPDATE flag set. This causes Unidrv to update its internal calculation of the current cursor position without sending cursor commands to the print spooler.