# PVIDEO_WRITE_DATA_LINE callback function

## Description

*WriteDataLine* sets the I2C serial data line to high or low.

## Parameters

### `HwDeviceExtension`

Pointer to the video miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `Data`

Supplies a value that specifies whether to set the serial data line to high or low. A value of 0 specifies that the data line should be set to low, and a value of 1 specifies that the data line should be set to high.

## Remarks

*WriteDataLine* should be made pageable.

## See also

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[I2C Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[ReadClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_clock_line)

[ReadDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_data_line)

[VideoPortDDCMonitorHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportddcmonitorhelper)

[WriteClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_clock_line)