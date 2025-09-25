# DXGKCB_ACQUIRE_POST_DISPLAY_OWNERSHIP2 callback function

## Description

Called by a display miniport driver to obtain the display information from the current power-on self-test (POST) display device or the previously running Windows Display Driver Model (WDDM) driver.

## Parameters

### `DeviceHandle`

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the member of the DXGKRNL_INTERFACE structure that was passed to DxgkDdiStartDevice.

### `DisplayInfo`

A pointer to a DXGK_DISPLAY_INFORMATION structure that is allocated by the display miniport driver. If DxgkCbAcquirePostDisplayOwnership returns STATUS_SUCCESS, this structure contains display information for the current display device that is used for POST operations.

### `Flags`

A pointer to a DXGK_DISPLAY_OWNERSHIP_FLAGS structure that is allocated by the display miniport driver. If DxgkCbAcquirePostDisplayOwnership2 returns STATUS_SUCCESS, this structure contains flags in bit fields describing the ownership of the display. The only bit fields defined in WDDM 2.2 contain a DXGK_FRAMEBUFFER_STATE enum indicating how the frame buffer was initialized.

## Return value

[DxgkCbAcquirePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership) returns STATUS_SUCCESS if it succeeds.

## Remarks

Register your implementation of this callback function by setting the appropriate member of and then calling .