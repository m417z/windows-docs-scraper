# DXGK_BRIGHTNESS_GET_POSSIBLE callback function

## Description

The *DxgkDdiGetPossibleBrightness* function retrieves the brightness levels that an integrated display panel supports.

## Parameters

### `Context` [in]

[in] A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem.

### `BufferSize` [in]

[in] The size, in bytes, of the buffer that is passed in the *BrightnessLevels* parameter.

### `LevelCount` [out]

[out] A pointer to a variable that receives the number of brightness levels that the driver returns in the buffer that the *BrightnessLevels* parameter points to.

### `BrightnessLevels` [out]

[in/out] A pointer to a buffer that receives the brightness levels that an integrated display panel supports.

## Return value

*DxgkDdiGetPossibleBrightness* returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes that are defined in *Ntstatus.h*.

## Remarks

The display miniport driver should return brightness levels in the buffer that the *BrightnessLevels* parameter points to in the following order:

* The first brightness level value is the brightness level that the BIOS uses when the computer runs on AC power.
* The second brightness level value is the brightness level that the BIOS uses when the computer runs on DC power.
* The remaining brightness level values are hardware-supported brightness levels.

To simplify your job of implementing a display miniport driver, the operating system provides the driver with the buffer that the *BrightnessLevels* parameter points to.

*DxgkDdiGetPossibleBrightness* should be made pageable.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)