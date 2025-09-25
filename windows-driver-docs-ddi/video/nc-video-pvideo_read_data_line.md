# PVIDEO_READ_DATA_LINE callback function

## Description

*ReadDataLine* reads a single data bit from the I2C serial data line.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

## Return value

*ReadDataLine* returns 1 if the serial data line is high and 0 if the serial data line is low.

## Remarks

*ReadDataLine* should be made pageable.

## See also

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[I2C Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[ReadClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_clock_line)

[VideoPortDDCMonitorHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportddcmonitorhelper)

[WriteClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_clock_line)

[WriteDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_data_line)