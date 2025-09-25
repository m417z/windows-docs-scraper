# _USBFN_CLASS_INFORMATION_PACKET_EX structure

## Description

Describes device interface class information associated with a USB interface. This structure can be used to describe single and multi-interface functions.

## Members

### `FullSpeedClassInterfaceEx`

A [USBFN_CLASS_INTERFACE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_class_interface_ex) structure that describes an interface for full speed device.

### `HighSpeedClassInterfaceEx`

A structure that describes an interface for high speed device.

### `SuperSpeedClassInterfaceEx`

A [USBFN_CLASS_INTERFACE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_class_interface_ex) structure that describes an interface for SuperSpeed device.

### `InterfaceName`

A string that contains the interface name.

### `InterfaceGuid`

A string from which the driver can derive the device interface GUID.

### `HasInterfaceGuid`

Determines whether the driver has published a device interface is GUID.

## See also

- [USBFN_CLASS_INTERFACE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnbase/ns-usbfnbase-_usbfn_class_interface_ex)
- [WdfDeviceCreateSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreatesymboliclink)
- [WdfDeviceSetDeviceInterfaceStateEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetdeviceinterfacestateex)