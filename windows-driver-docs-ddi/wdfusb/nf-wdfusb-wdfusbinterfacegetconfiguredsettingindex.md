# WdfUsbInterfaceGetConfiguredSettingIndex function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbInterfaceGetConfiguredSettingIndex** method returns the alternate setting index that is currently selected for a specified USB device interface.

## Parameters

### `Interface` [in]

A handle to a USB interface object that was obtained by calling [WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface).

## Return value

If the operation succeeds, **WdfUsbInterfaceGetConfiguredSettingIndex** returns the alternate setting index that is currently selected for the specified interface. If the interface is not configured, the method returns zero.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the **WdfUsbInterfaceGetConfiguredSettingIndex** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains the index for the currently selected alternate setting of a specified USB interface.

```cpp
BYTE settingIndex;

settingIndex = WdfUsbInterfaceGetConfiguredSettingIndex(UsbInterface);
```

## See also

[WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface)