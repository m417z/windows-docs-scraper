# _IRB_REQ_ISOCH_ALLOCATE_BANDWIDTH structure

## Description

This structure contains the fields necessary in order for the Bus driver to carry out an **IsochAllocateBandwidth** request.

## Members

### `nMaxBytesPerFrameRequested`

Specifies the bandwidth requested, in bytes per isochronous frame. If the host controller is configured to strip away the packet headers, the device driver does not need to include the packet header size in the number of bytes requested. The driver also does not need to round the value up to the nearest quadlet.

### `fulSpeed`

Specifies the connection speed to use in allocating bandwidth. The possible speed values are SPEED_FLAGS_xxx, where xxx is the (approximate) transfer rate in megabits per second. Existing hardware supports transfer rates of 100, 200, and 400 Mb/sec.

| Transfer Rate | Description |
| --- | --- |
| SPEED_FLAGS_100 | 100 Mb/s |
| SPEED_FLAGS_200 | 200 Mb/s |
| SPEED_FLAGS_400 | 400 Mb/s |

**Note** In Windows 7 and later versions of Windows, you can specify new values higher speed and greater sized payloads. For more information, see [New Flags for Speed and Payload Size](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) and [IEEE 1394 IOCTL Changes](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) in Device Driver Interface (DDI) Changes in Windows 7.

### `hBandwidth`

Specifies the handle to use to refer to the bandwidth resource. The caller can set the IRB_FLAG_ALLOW_REMOTE_FREE flag in **Flags** member of the [IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_irb) structure to indicate that the system should free the memory allocated for this handle. If caller does not set this flag, then caller will have to free the bandwidth handle.

### `BytesPerFrameAvailable`

Specifies the bytes per frame that are available after the allocation attempt. Drivers should not rely on this bandwidth being available, since another device may allocate or deallocate bandwidth at any time. The bus driver fills in this member, even if the request fails.

### `SpeedSelected`

Specifies the actual speed selected in allocating bandwidth. The value is one of SPEED_FLAGS_xxx (see the **fulSpeed** member description above).

**Note** In Windows 7 and later versions of Windows, you can specify new values higher speed and greater sized payloads. For more information, see [New Flags for Speed and Payload Size](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) and [IEEE 1394 IOCTL Changes](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) in Device Driver Interface (DDI) Changes in Windows 7.

### `nBandwidthUnitsRequired`

This is a pre-calculated value.