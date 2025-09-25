# _IRB_REQ_ASYNC_STREAM structure

## Description

This structure contains the fields necessary for the 1394 bus driver to carry out an asynchronous write request.

## Members

### `nNumberOfBytesToStream`

Specifies the number of bytes to write.

### `fulFlags`

Reserved. Drivers must set this to zero.

### `Mdl`

Specifies the source buffer.

### `ulTag`

Specifies the Tag field for any packets generated from this request.

### `nChannel`

Specifies the channel to which the data will be written.

### `ulSynch`

Specifies the Sy field for any packets generated from this request.

### `Reserved`

Reserved. Drivers must set this to zero.

### `nSpeed`

Specifies the transfer rate. The possible speed values are SPEED_FLAGS_xxx, where xxx is the (approximate) transfer rate in megabits per second. Existing hardware currently supports transfer rates of 100, 200, and 400 Mb/sec.

| Transfer Rate | Description |
| --- | --- |
| SPEED_FLAGS_100 | 100 Mb/s |
| SPEED_FLAGS_200 | 200 Mb/s |
| SPEED_FLAGS_400 | 400 Mb/s |

**Note** In Windows 7 and later versions of Windows, you can specify new values higher speed and greater sized payloads. For more information, see [New Flags for Speed and Payload Size](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) and [IEEE 1394 IOCTL Changes](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) in Device Driver Interface (DDI) Changes in Windows 7.