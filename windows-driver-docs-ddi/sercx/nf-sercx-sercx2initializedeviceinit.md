# SerCx2InitializeDeviceInit function

## Description

The **SerCx2InitializeDeviceInit** method enables version 2 of the serial framework extension (SerCx2) to register extension-specific properties with the driver framework during the creation of the framework device object for the serial controller.

## Parameters

### `DeviceInit` [in, out]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure, which is an opaque structure that stores information that the Kernel Mode Driver Framework (KMDF) uses to create a framework device object. The serial controller driver receives a pointer to this structure as an input parameter to the driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

## Return value

**SerCx2InitializeDeviceInit** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The method was called at the wrong IRQL, or the *DeviceInit* parameter is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to perform the requested operation. |

## Remarks

The serial controller driver must call this method from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function before it creates a WDFDEVICE object for the serial controller.

**SerCx2InitializeDeviceInit** attaches extension-specific information to the driver's [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure. This information enables SerCx2 to perform certain actions on behalf of the serial controller driver. For example, SerCx2 receives I/O requests that clients send to the serial controller.

The serial controller driver must call **SerCx2InitializeDeviceInit** before creating a framework device object to represent the serial controller, and before calling the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method to finish initializing the device object. The driver calls a method such as [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) to create the device object.

**SerCx2InitializeDeviceInit** sets a default security descriptor that allows both kernel-mode drivers and user-mode drivers to send I/O requests to SerCx2. The descriptor allows applications to send these requests only if they run with administrator privileges. To specify this descriptor, SerCx2 uses the following SDDL string:

`"D:P(A;;GA;;;SY)(A;;GA;;;BA)(A;;GA;;;UD)"`
If necessary, the serial controller driver can override the default setting by calling the [WdfDeviceInitAssignSDDLString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignsddlstring) method with the desired security descriptor. The driver must call **WdfDeviceInitAssignSDDLString** after calling **SerCx2InitializeDeviceInit** but before calling **WdfDeviceCreate**. For more information about SDDL strings, see [SDDL for Device Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/sddl-for-device-objects).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[WdfDeviceInitAssignSDDLString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignsddlstring)