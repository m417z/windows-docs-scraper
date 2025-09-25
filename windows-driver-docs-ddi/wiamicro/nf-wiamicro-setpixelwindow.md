# SetPixelWindow function

## Description

The **SetPixelWindow** function sets the image area to be scanned.

## Parameters

### `pScanInfo` [in, out]

Points to a [SCANINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-_scaninfo) structure that represents the current state of the device. This is stored by the WIA Flatbed driver to guarantee synchronized settings between the microdriver and the WIA Flatbed driver.

### `x`

Specifies the horizontal position value for the left side of the selection rectangle in pixels.

### `y`

Specifies the vertical position value for the top of the selection rectangle in pixels.

### `xExtent`

Specifies the width of the selection rectangle in pixels.

### `yExtent`

Specifies the height of the selection rectangle in pixels.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns a standard COM error code.

## Remarks

In this function, the microdriver should set up the **Window** member of the [SCANINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-_scaninfo) structure, making any device-specific adjustments that are necessary.

## See also

[SCANINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-_scaninfo)

[WIA Microdriver Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)