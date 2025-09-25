# SerCxDeviceInitConfig function

## Description

The **SerCxDeviceInitConfig** method is called by the serial controller driver to attach the serial framework extension (SerCx) to the I/O pipeline for a framework device object (FDO or PDO) that it is creating.

## Parameters

### `DeviceInit` [in, out]

A pointer to the [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that is to be configured.

## Return value

**SerCxDeviceInitConfig** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status code.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | Could not allocate system resources (typically memory). |

## Remarks

This method associates SerCx's configuration information with the **WDFDEVICE_INIT** structure for the framework device object (PDO or FDO) that is to be created. Call **SerCxDeviceInitConfig** before you call the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) method to create the device object.

The controller driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function receives a pointer to an initialized **WDFDEVICE_INIT** structure as an input parameter.

SerCx sets a default security descriptor that the serial controller driver can, if necessary, override. For example, this default security descriptor enables a user-mode driver to send an I/O request to a peripheral device that is connected to a port on the serial controller. To change this setting in the security descriptor, the serial controller driver can call the [WdfDeviceInitAssignSDDLString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignsddlstring) method. This call must occur after the **SerCxDeviceInitConfig** call, but before the call to the **WdfDeviceCreate** method.

#### Examples

In the following code example, a controller driver's *EvtDriverDeviceAdd* callback function passes an initialized **WDFDEVICE_INIT** structure to the **SerCxDeviceInitConfig** method. The call to **SerCxDeviceInitConfig** must occur before the **WdfDeviceCreate** call that creates the FDO for the serial controller device (UART).

```cpp
//
// FxDeviceInit is a pointer to an initialized WDFDEVICE_INIT structure.
// Drivers receive a pointer to this structure as an input parameter to an
// EvtDriverDeviceAdd callback function, or as a return value from the
// WdfControlDeviceInitAllocate method.
//

status = SerCxDeviceInitConfig(FxDeviceInit);

if (!NT_SUCCESS(status))
{
    return status;
}

//
// Set WDF and SerCx device-level configuration options.
//

...

//
// Call the WdfDeviceCreate method.
//

...

```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[WdfDeviceInitAssignSDDLString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignsddlstring)