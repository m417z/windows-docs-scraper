# PVIDEO_READ_CLOCK_LINE callback function

## Description

*ReadClockLine* reads a single data bit from the I2C serial clock line.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

## Return value

*ReadClockLine* returns 1 if the serial clock line is high and 0 if the serial clock line is low.

## Remarks

*ReadClockLine* should be made pageable.

## See also

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[I2C Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[ReadDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_data_line)

[VideoPortDDCMonitorHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportddcmonitorhelper)

[WriteClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_clock_line)

[WriteDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_data_line)