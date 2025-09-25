# _BUS_RESET_DATA structure

## Description

The **BUS_RESET_DATA** structure specifies the context for the extended bus reset notification routine.

## Members

### `ResetContext`

Pointer to a client driver-defined context when a bus reset occurs. The argument that is specified in the **u.BusResetNotification.ResetContext** parameter when the [REQUEST_BUS_RESET_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request is sent.

### `GenerationCount`

The current generation of the 1394 bus.

### `DeviceNodeId`

The 1394 address for the device.

### `LocalNodeId`

The 1394 address for the local host.

### `SpeedToNode`

The negotiated speed to the device. The possible values are as follows:

| Flag | Value | Description |
| --- | --- | --- |
| SPEED_FLAGS_800 | 0x08 | 800 Mb/s |
| SPEED_FLAGS_1600 | 0x10 | 160 Mb/s |
| SPEED_FLAGS_3200 | 0x20 | 3200 Mb/s |

## See also

[Device Driver Interface (DDI) Changes in Windows 7](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7)