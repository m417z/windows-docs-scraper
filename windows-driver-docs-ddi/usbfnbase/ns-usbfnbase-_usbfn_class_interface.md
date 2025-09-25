# _USBFN_CLASS_INTERFACE structure

## Description

Describes an interface and its endpoints.

## Members

### `InterfaceNumber`

The index number of the interface.

### `PipeCount`

The number of endpoints contained in the interface.

### `PipeArr`

An array of [USBFN_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_pipe_information) structures that describes the endpoints in the interface.

## See also

[USBFN_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_pipe_information)