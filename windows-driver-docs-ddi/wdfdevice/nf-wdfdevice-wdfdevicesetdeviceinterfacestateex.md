## Description

The **WdfDeviceSetDeviceInterfaceStateEx** method enables or disables a device interface for a specified device.

## Parameters

### `Device`

A handle to a framework device object.

### `InterfaceClassGUID`

A pointer to a GUID that identifies the device interface class.

### `ReferenceString`

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that describes a reference string for the device interface. This parameter is optional and can be **NULL**.

### `IsInterfaceEnabled`

A Boolean value that, if **TRUE**, enables the specified device interface instance or, if **FALSE**, disables it.

## Remarks

The driver can call this function either before or after the device has started.

When called before the device starts (for example from [*EvtDriverDeviceAdd*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add), [*EvtChildListCreateDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device), or [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)), the driver should set **IsInterfaceEnabled** to FALSE to prevent the interface from being automatically enabled during PnP start. Setting the parameter to TRUE before the device starts is redundant and such a call should be removed.

When calling after the device has started, the behavior is the same as [**WdfDeviceSetDeviceInterfaceState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetdeviceinterfacestate).

## See also

[**WdfDeviceSetDeviceInterfaceState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetdeviceinterfacestate)

[Enabling and Disabling a Device Interface](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces#enabling-and-disabling-a-device-interface)