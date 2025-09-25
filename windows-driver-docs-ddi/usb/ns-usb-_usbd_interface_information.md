# _USBD_INTERFACE_INFORMATION structure

## Description

The **USBD_INTERFACE_INFORMATION** structure holds information about an interface for a configuration on a USB device.

## Members

### `Length`

Specifies the length, in bytes, of this structure.

### `InterfaceNumber`

Specifies the device-defined index identifier for this interface.

### `AlternateSetting`

Specifies a device-defined index identifier that indicates which alternate setting this interface is using, should use, or describes.

### `Class`

Contains a USB-assigned identifier that specifies a USB-defined class that this interface conforms to.

### `SubClass`

Contains a USB-assigned identifier that specifies a USB-defined subclass that this interface conforms to. This code is specific to the code in **Class**.

### `Protocol`

Contains a USB-assigned identifier that specifies a USB-defined protocol that this interface conforms to. This code is specific to the codes in **Class** and **SubClass**.

### `Reserved`

Reserved.

### `InterfaceHandle`

Contains a host controller driver-defined handle that is used to access this interface. This member should be treated as opaque.

### `NumberOfPipes`

Specifies the number of pipes (endpoints) in this interface.

### `Pipes`

Pointer to the first element in the array of [USBD_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_pipe_information) structures. The length of the array depends on the number of endpoints in the interface descriptor.

## Remarks

Members that are part of this structure, but not described here, should be treated as opaque and considered to be reserved for system use.

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USBD_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_pipe_information)