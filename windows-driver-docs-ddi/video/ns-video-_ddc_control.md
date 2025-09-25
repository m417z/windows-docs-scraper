# _DDC_CONTROL structure

## Description

The DDC_CONTROL structure holds function pointers and [EDID](https://learn.microsoft.com/windows-hardware/drivers/) segment information needed by the [VideoPortDDCMonitorHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportddcmonitorhelper) function, which is exported by the video port driver. The [HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor) function, implemented by the video miniport driver, can call **VideoPortDDCMonitorHelper** for assistance in reading the EDID blocks from its child monitor devices.

## Members

### `Size`

Specifies the size, in bytes, of this DDC_CONTROL structure.

### `I2CCallbacks`

Is an [I2C_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_i2c_callbacks) structure that contains pointers to functions, implemented by the video miniport driver, that read and write individual data bits to the I2C serial clock and data lines.

### `EdidSegment`

Specifies the particular EDID segment. Currently, this member is meaningful only for EEDID (EDID Version 1.3); for other EDID versions, this member should always be set to 0. For EEDID (EDID Version 1.3), segment numbers can range from 0 through 127, where each segment is 256 bytes in length. Since the EDID version number is in segment 0, this member must be set to 0 the first time the video miniport driver calls [VideoPortDDCMonitorHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportddcmonitorhelper) regarding a particular monitor.

## See also

[I2C Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[ReadClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_clock_line)

[ReadDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_data_line)

[WriteClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_clock_line)

[WriteDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_data_line)