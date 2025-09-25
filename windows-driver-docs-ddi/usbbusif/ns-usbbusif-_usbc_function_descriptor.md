# _USBC_FUNCTION_DESCRIPTOR structure

## Description

The **USBC_FUNCTION_DESCRIPTOR** structure describes a USB function and its associated interface collection.

## Members

### `FunctionNumber`

The zero-based index of the interface collection.

### `NumberOfInterfaces`

The number of interfaces in the interface collection.

### `InterfaceDescriptorList`

An array of pointers to [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)-type structures that describe the interfaces in the interface collection.

### `HardwareId`

The hardware identifier of the interface collection.

### `CompatibleId`

The compatible identifier of the interface collection.

### `FunctionDescription`

A description of the interface collection in human-readable text.

### `FunctionFlags`

Vendor-defined flags that describe the interface collection.

### `Reserved`

Reserved.

## Remarks

For information on how to use user-defined callback routines to provide a custom definition of the interface collections on a device, see [Customizing Enumeration of Interface Collections for Composite Devices](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)