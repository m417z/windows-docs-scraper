# VideoPortScanRom function

## Description

The **VideoPortScanRom** function is **obsolete** in Windows XP and later versions. It is supported only for backward compatibility.

**VideoPortScanRom** performs a case-sensitive search for a specified string in ROM.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `RomBase`

Specifies the base ROM address at which the search should start. The given *RomBase* must be in a mapped range returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

### `RomLength`

Specifies the size in bytes of the mapped ROM to be searched.

### `String`

Pointer to the driver-allocated string to search for.

## Return value

If the string is found, **VideoPortScanRom** returns **TRUE**. Otherwise, it returns **FALSE**.

## Remarks

**VideoPortScanRom** cannot be called from a miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_timer) functions, or from [VideoPortQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueuedpc), or from a callback to [VideoPortSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsynchronizeexecution).

## See also

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortGetRomImage](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetromimage)