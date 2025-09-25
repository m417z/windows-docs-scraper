# WdfDeviceConfigureWdmIrpDispatchCallback function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceConfigureWdmIrpDispatchCallback** method registers a driver's [EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch) callback function.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Driver` [in, optional]

A handle to the driver's framework driver object that the driver obtained from a previous call to [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) or [WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver). This parameter is optional.

### `MajorFunction` [in]

One of the following IRP major function codes: IRP_MJ_DEVICE_CONTROL, IRP_MJ_INTERNAL_DEVICE_CONTROL, IRP_MJ_READ, IRP_MJ_WRITE.

### `EvtDeviceWdmIrpDispatch`

A pointer to the driver's [*EvtDeviceWdmIrpDispatch*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch) callback function.

### `DriverContext` [in, optional]

An untyped pointer to driver-defined context information that the framework passes to the driver's [EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch) callback function. This parameter is optional and can be NULL.

## Return value

If the **WdfDeviceConfigureWdmIrpDispatchCallback** method encounters no errors, it returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid *MajorFunction* value was supplied. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |

## Remarks

A driver calls the **WdfDeviceConfigureWdmIrpDispatchCallback** method to register an [EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch) callback function. The framework then calls *EvtDeviceWdmIrpDispatch* whenever it receives an I/O request packet (IRP) containing an IRP major function code that matches the *MajorFunction* parameter of this method.

A driver typically calls **WdfDeviceConfigureWdmIrpDispatchCallback** from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

You must call **WdfDeviceConfigureWdmIrpDispatchCallback** once for each MJ function for which the driver wants to register a callback function. In other words, multiple calls are required for intercepting multiple MJ functions.

A driver might call the **WdfDeviceConfigureWdmIrpDispatchCallback** method for these reasons:

* To examine an IRP and assign it to a specific queue based on domain-specific criteria, for example, direct all I/O associated with a file object to a particular queue.
* To select on an individual request basis the need to call the [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) callback function.

 For more information about specifying queues for IRPs as they arrive, see [Dispatching IRPs to I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-irps-to-i-o-queues).

## See also

[EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch)

[WdfDeviceWdmDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirp)

[WdfDeviceWdmDispatchIrpToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirptoioqueue)