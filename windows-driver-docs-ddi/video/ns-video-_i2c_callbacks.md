# _I2C_CALLBACKS structure

## Description

The I2C_CALLBACKS structure contains pointers to functions, implemented by the video miniport driver, that read from and write to the serial data and serial clock lines of the I2C bus.

## Members

### `WriteClockLine`

A pointer to the [WriteClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_clock_line) function implemented by the video miniport driver.

### `WriteDataLine`

A pointer to the [WriteDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_data_line) function implemented by the video miniport driver.

### `ReadClockLine`

A pointer to the [ReadClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_clock_line) function implemented by the video miniport driver.

### `ReadDataLine`

A pointer to the [ReadDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_data_line) function implemented by the video miniport driver.

## See also

[DDC_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_ddc_control)

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[I2C Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[VideoPortDDCMonitorHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportddcmonitorhelper)