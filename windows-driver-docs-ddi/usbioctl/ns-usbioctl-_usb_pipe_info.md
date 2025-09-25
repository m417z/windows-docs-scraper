# _USB_PIPE_INFO structure

## Description

The **USB_PIPE_INFO** structure is used in conjunction with the [USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex) structure and the [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex) request to obtain information about a connection and its associated pipes.

## Members

### `EndpointDescriptor`

Describes the endpoint descriptor. For more information about the endpoint descriptor, see [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor).

### `ScheduleOffset`

Indicates the schedule offset assigned to the endpoint for this pipe. See the remarks section for a discussion of the range of values that this member can take.

## Remarks

The USB specification labels isochronous and interrupt transfers as "periodic," because certain periods of transmission time are set aside for these types of transfers. The port driver further divides these periods into "schedule offsets" and distributes the available offsets between those endpoints that are doing periodic transfers. The number of offsets that are available depends on the period. The following table lists the offset values that are available for each period.

| Period | Available Offsets |
| --- | --- |
| 1 | 0 |
| 2 | 0 to 1 |
| 4 | 0 to 3 |
| 8 | 0 to 7 |
| 16 | 0 to 15 |
| 32 | 0 to 31 |

## See also

[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor)