# VideoPortDDCMonitorHelper function

## Description

Queries a monitor for [EDID](https://learn.microsoft.com/windows-hardware/drivers/) information using the DDC protocol.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the miniport driver's device extension.

### `DDCControl` [in]

A pointer to a [DDC_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_ddc_control) structure.

### `EdidBuffer` [in, out]

A pointer to a buffer in which the video port driver returns the [EDID](https://learn.microsoft.com/windows-hardware/drivers/) structure. For ACPI devices, the first four bytes are preset by the video port driver to indicate an attempt to read the *EDID*.

### `EdidBufferSize` [in]

The size in bytes of the buffer to which *EdidBuffer* points.

## Return value

**VideoPortDDCMonitorHelper** returns **TRUE** if successful.

## Remarks

**Note**

This function existed prior to the Windows XP release, but has been changed.

The video miniport driver's [HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor) function can call **VideoPortDDCMonitorHelper** for assistance in reading the [EDID](https://learn.microsoft.com/windows-hardware/drivers/) structure from a DDC2-compliant monitor. **VideoPortDDCMonitorHelper** implements the details of reading the EDID structure according to the I²C specification, but must call back into the video miniport driver to read and write individual data bits to the I²C serial clock and data lines.

The four functions, implemented by the video miniport driver, that read and write individual bits to the I²C clock and data lines are [ReadClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_clock_line), [ReadDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_data_line), [WriteClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_clock_line), and [WriteDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_data_line). When the video miniport driver calls **VideoPortDDCMonitorHelper**, it supplies pointers to those four functions in *DDCControl***->I2CCallbacks**.

The [EDID](https://learn.microsoft.com/windows-hardware/drivers/) can be obtained using the ACPI_METHOD_OUTPUT_DDC method whose alias is defined in Dispmprt.h. This method is required for integrated LCDs that do not have another standard mechanism for returning EDID data.

In a 256-byte buffer, a caller of this function can receive:

* One 128-byte EDID
* Two 128-byte EDIDs
* One 256-byte EDID (from P&D display)
* No EDID

The caller should always ask for the full 256 bytes, because it is impossible to read just the second 128-byte block of the segment.

## See also

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[I2C Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[ReadClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_clock_line)

[ReadDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_read_data_line)

[WriteClockLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_clock_line)

[WriteDataLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_write_data_line)