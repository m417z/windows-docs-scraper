# WdfDeviceSetDeviceInterfaceState function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceSetDeviceInterfaceState** method enables or disables a device interface for a specified device.

> [!NOTE]
> The driver should only call this function after the device has started. To change interface state from device add, call [**WdfDeviceSetDeviceInterfaceStateEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetdeviceinterfacestateex) instead.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `InterfaceClassGUID` [in]

A pointer to a GUID that identifies the device interface class.

### `ReferenceString` [in, optional]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that describes a reference string for the device interface. This parameter is optional and can be **NULL**.

### `IsInterfaceEnabled` [in]

A Boolean value that, if **TRUE**, enables the specified device interface instance or, if **FALSE**, disables it.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

For more information about device interfaces and the **WdfDeviceSetDeviceInterfaceState** method, see [Using Device Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces).

#### Examples

The following code example disables a driver's COM port interface.

```cpp
WdfDeviceSetDeviceInterfaceState (
                                  Device,
                                  (LPGUID) &GUID_DEVINTERFACE_COMPORT,
                                  NULL,
                                  FALSE
                                  );
```

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfDeviceCreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreatedeviceinterface)
[**WdfDeviceSetDeviceInterfaceStateEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetdeviceinterfacestateex)