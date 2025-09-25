# WdfUsbInterfaceGetDescriptor function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbInterfaceGetDescriptor** method retrieves the USB interface descriptor that is associated with a specified alternate setting of a specified USB interface.

## Parameters

### `UsbInterface` [in]

A handle to a USB interface object that was obtained by calling [WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface).

### `SettingIndex` [in]

An index value that identifies an alternate setting for the interface. For more information about alternate settings, see the USB specification.

### `InterfaceDescriptor` [out]

A pointer to a caller-allocated [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure that the framework fills in.

## Remarks

If the *SettingIndex* value is invalid, the [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure can receive invalid data.

A bug check occurs if the driver supplies an invalid object handle.

For more information about the **WdfUsbInterfaceGetDescriptor** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains the alternate setting index for a specified USB interface. Then, the example obtains the USB interface descriptor that represents the USB interface's current alternate setting.

```cpp
BYTE  settingIndex;
USB_INTERFACE_DESCRIPTOR  interfaceDescriptor;

settingIndex = WdfUsbInterfaceGetConfiguredSettingIndex(
                             UsbInterface
                             );

WdfUsbInterfaceGetDescriptor(
                             UsbInterface,
                             settingIndex,
                             &interfaceDescriptor
                             );
```

## See also

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)

[WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface)