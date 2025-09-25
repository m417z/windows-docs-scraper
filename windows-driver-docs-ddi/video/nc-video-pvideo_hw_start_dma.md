## Description

A video miniport driver's **HwStartDma** function starts a DMA transfer. Reserved for system use.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `pDma`

Opaque type for DMA handle.

## Return value

**HwStartDma** returns a HW_DMA_RETURN enumeration value.

## See also

[**VIDEO_HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data)