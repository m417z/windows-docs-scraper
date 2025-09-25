## Description

The **USBSCAN_PIPE_INFORMATION** structure is used to describe a USB transfer pipe for a still image device. An array of **USBSCAN_PIPE_INFORMATION** structures is supplied within a [**USBSCAN_PIPE_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_usbscan_pipe_configuration) structure.

## Members

### `MaximumPacketSize`

Maximum packet size for the transfer pipe.

### `EndpointAddress`

The address of the pipe's endpoint. The address is encoded as follows:

| Bits | Definition |
|---|---|
| 0..3 | Endpoint number. |
| 4..6 | Reserved, set to 0. |
| 7 | Direction, ignored for control endpoints: 0 - OUT endpoint 1 - IN endpoint |

For more information, see the *Universal Serial Bus Specification*.

### `Interval`

Polling interval, in milliseconds, for interrupt pipes. For more information, see the *Universal Serial Bus Specification*.

### `PipeType`

A [**RAW_PIPE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ne-usbscan-_raw_pipe_type)-typed value identifying the pipe type.

## See also

[**RAW_PIPE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ne-usbscan-_raw_pipe_type)

[**USBSCAN_PIPE_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_usbscan_pipe_configuration)