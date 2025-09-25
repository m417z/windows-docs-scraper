# _IRB_REQ_SET_DEVICE_XMIT_PROPERTIES structure

## Description

This structure contains the fields necessary to carry out a SetDeviceXmitProperties request.

## Members

### `fulSpeed`

Specifies the maximum speed for transactions to the device. The possible speed values are SPEED_FLAGS_xxx, where xxx is the (approximate) transfer rate in megabits per second. Existing hardware supports transfer rates of 100, 200, and 400 Mb/sec.

| Transfer Rate | Description |
| --- | --- |
| SPEED_FLAGS_100 | 100 Mb/s |
| SPEED_FLAGS_200 | 200 Mb/s |
| SPEED_FLAGS_400 | 400 Mb/s |

Reserved.

**Note** In Windows 7 and later versions of Windows, you can specify new values higher speed and greater sized payloads. For more information, see [New Flags for Speed and Payload Size](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) and [IEEE 1394 IOCTL Changes](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) in Device Driver Interface (DDI) Changes in Windows 7.

### `fulPriority`

Specifies the priority.

## Remarks

By default, the maximum permitted transmission speed is the physical maximum. A driver should use this request to lower the maximum permitted speed.