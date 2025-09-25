# _IRB_REQ_ISOCH_MODIFY_STREAM_PROPERTIES structure

## Description

This structure contains the fields necessary for the Bus driver to carry out an **IsochModifyStreamProperties** request.
This request is used to dynamically change the properties of an allocated
resource, without the need to free and re-allocate the resource.
The resource must not be streaming when this is issued. The caller should
issue an ISOCH_STOP first and then an ISOCH_START. Also, no buffer can be
pending after the ISOCH_STOP and before this call is made.

## Members

### `hResource`

The handle for the allocated resource.

### `ChannelMask`

Specifies the allocated channel.

### `fulSpeed`

Specifies the connection speed to use for communication on the channel. The possible speed values are SPEED_FLAGS_xxx, where xxx is the (approximate) transfer rate in megabits per second. Existing hardware supports transfer rates of 100, 200, and 400 Mb/sec.

| Transfer Rate | Description |
| --- | --- |
| SPEED_FLAGS_100 | 100 Mb/s |
| SPEED_FLAGS_200 | 200 Mb/s |
| SPEED_FLAGS_400 | 400 Mb/s |

**Note** In Windows 7 and later versions of Windows, you can specify new values higher speed and greater sized payloads. For more information, see [New Flags for Speed and Payload Size](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) and [IEEE 1394 IOCTL Changes](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) in Device Driver Interface (DDI) Changes in Windows 7.

## Remarks

The resource must not be streaming when [REQUEST_ISOCH_MODIFY_STREAM_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) is issued. Before issuing **REQUEST_ISOCH_MODIFY_STREAM_PROPERTIES**, the caller must send a [REQUEST_ISOCH_STOP](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request followed by a start request. Also make sure that there are no pending buffers after the caller sends a **REQUEST_ISOCH_STOP** request and before the caller sends a **REQUEST_ISOCH_MODIFY_STREAM_PROPERTIES** request.