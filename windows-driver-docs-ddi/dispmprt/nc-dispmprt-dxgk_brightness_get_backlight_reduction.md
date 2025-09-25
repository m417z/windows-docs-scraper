# DXGK_BRIGHTNESS_GET_BACKLIGHT_REDUCTION callback function

## Description

Retrieves the current level of backlight reduction that is applied to the integrated display panel.

## Parameters

### `Context` [in]

A handle to a [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) context block that is associated with a display adapter. The display miniport driver's function previously provided this handle to the DirectX graphics kernel subsystem.

### `BacklightInfo` [out]

A value of type [DXGK_BACKLIGHT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_backlight_info) that provides the current absolute level of backlight reduction.

## Return value

Returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes that are defined in Ntstatus.h.

## Remarks

This function is mostly used for debugging and testing purposes to ensure a quality user experience with the display panel. The display miniport driver must always provide accurate information about the integrated display panel when this function is called.

Note that for some hardware a value of zero for *BacklightInfo*->**BacklightUsersetting** or *BacklightInfo*->**BacklightEffective** might not correspond to a Windows brightness level of zero percent. The operating system therefore requires absolute brightness information given by **BacklightUsersetting** and **BacklightEffective**. If the hardware uses brightness levels of 0 to 255, it must multiply those values by 256 to correctly map them to the 0 to 65535 range of **BacklightUsersetting** and **BacklightEffective**.

This function should be made pageable.

### Computing backlight reduction ratio

The backlight reduction ratio (*BRR*) is calculated as (**BacklightUsersetting** - **BacklightEffective**) / **BacklightUsersetting**.

The operating system assumes that, in response to a new brightness level request, the driver will boost pixel brightness by a factor of **BacklightUsersetting** / **BacklightEffective** = 1.0 / (1.0 - *BRR*).

As an example, if *BRR* = 0.2, the driver will typically boost brightness by a factor of 1.0 / (1.0 - *BRR*) = 1.25, so any pixel with a brightness value above 255 * (1.0 - *BRR*) = 204 will saturate. Using the value of *BacklightInfo*->**GammaRamp** provided by the driver, the operating system can more accurately estimate the distortion of pixel brightness for a particular image.

## See also

[DXGK_BACKLIGHT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_backlight_info)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)