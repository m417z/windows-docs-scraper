# _USBFN_CLASS_INTERFACE_EX structure

## Description

Describes an interface and its endpoints.

## Members

### `BaseInterfaceNumber`

The index number of the interface.

### `InterfaceCount`

The number of USB interfaces contained in the selected function.

### `PipeCount`

The number of endpoints contained in the interface.

### `PipeArr`

An array of [USBFN_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_pipe_information) structures that describes the endpoints in the interface.