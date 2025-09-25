# UdecxUsbDeviceInitAddStringDescriptorRaw function

## Description

Adds a USB string descriptor to the initialization parameters used to create a virtual USB device.

## Parameters

### `UdecxUsbDeviceInit` [in, out]

A pointer to a WDF-allocated structure that contains initialization parameters for the virtual USB device. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitallocate).

### `Descriptor` [in]

A caller-allocated buffer that contains the USB descriptor to add to the device.

### `DescriptorLength` [in]

The length of the descriptor buffer.

### `DescriptorIndex` [in]

The index of the descriptor.

### `LanguageId` [in]

The language identifier of the string. The client driver must define constants for the language support, such as:

`const USHORT US_ENGLISH = 0x409;`

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[USB String Descriptors](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-string-descriptors)

[UdecxUsbDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitallocate)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)