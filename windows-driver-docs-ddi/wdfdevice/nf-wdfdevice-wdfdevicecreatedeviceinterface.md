# WdfDeviceCreateDeviceInterface function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceCreateDeviceInterface** method creates a device interface for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `InterfaceClassGUID` [in]

A pointer to a GUID that identifies the device interface class.

### `ReferenceString` [in, optional]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that describes a reference string for the device interface. The string must not contain any path separator characters ("/" or "\\"). This parameter is optional and can be **NULL**. For more information, see the following Remarks section.

## Return value

**WdfDeviceCreateDeviceInterface** returns STATUS_SUCCESS if the operation succeeds.

For a list of other return values that **WdfDeviceCreateDeviceInterface** can return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The driver can call **WdfDeviceCreateDeviceInterface** from [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add), or after the device has started.
If the driver calls this function from its *EVT_WDF_DRIVER_DEVICE_ADD* callback function, the interface is automatically enabled when the device starts and disabled when the device stops. To prevent auto enable, the driver can call [**WdfDeviceSetDeviceInterfaceStateEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetdeviceinterfacestateex) with the **IsInterfaceEnabled** parameter set to **FALSE**.
If the driver calls this function after the device has already started, the interface remains disabled. The driver can call [**WdfDeviceSetDeviceInterfaceState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetdeviceinterfacestate) as appropriate.

Drivers can use the *ReferenceString* parameter to differentiate different instances of a single interface. In other words, if a driver calls **WdfDeviceCreateDeviceInterface** twice for the same device interface class, the driver can specify a different *ReferenceString* parameter each time. When an instance of an interface is opened, the I/O manager passes the instance's reference string to the driver. The reference string is appended to the path component of the interface instance's name. The driver can then use the reference string to determine which instance of the device interface class is being opened.

For more information about device interfaces and the **WdfDeviceCreateDeviceInterface** method, see [Using Device Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces).

#### Examples

The following example registers the COM port interface class for a device.

```cpp
NTSTATUS  status;

status = WdfDeviceCreateDeviceInterface(
                                        Device,
                                        (LPGUID) &GUID_DEVINTERFACE_COMPORT,
                                        NULL
                                        );
```

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfDeviceSetDeviceInterfaceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetdeviceinterfacestate)