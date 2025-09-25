# _USBFN_CLASS_INFORMATION_PACKET structure

## Description

Describes device interface class information associated with a USB interface. This structure can only hold information about a single function interface.

## Members

### `FullSpeedClassInterface`

A [USBFN_CLASS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_class_interface) structure that describes an interface for full speed device.

### `HighSpeedClassInterface`

A [USBFN_CLASS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_class_interface) structure that describes an interface for high speed device.

### `InterfaceName`

A string that contains the interface name.

### `InterfaceGuid`

A string from which the driver can derive the device interface GUID.

### `HasInterfaceGuid`

Determines whether the driver has published a device interface is GUID.

### `SuperSpeedClassInterface`

A [USBFN_CLASS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_class_interface) structure that describes an interface for SuperSpeed device.

## See also

- [USBFN_CLASS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_class_interface)
- [WdfDeviceCreateSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreatesymboliclink)
- [WdfDeviceSetDeviceInterfaceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetdeviceinterfacestate)