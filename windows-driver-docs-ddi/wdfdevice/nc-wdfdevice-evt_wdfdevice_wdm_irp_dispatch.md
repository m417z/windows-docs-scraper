# EVT_WDFDEVICE_WDM_IRP_DISPATCH callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceWdmIrpDispatch* event callback function receives an IRP before the framework processes the IRP.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `MajorFunction` [in]

One of the IRP major function codes that are defined in wdm.h.

### `MinorFunction` [in]

One of the I/O IRP minor function codes that are defined in wdm.h for the *MajorFunction* code.

### `Code` [in]

Specifies an I/O control code value. This parameter is valid only if *MajorFunction* is set to IRP_MJ_DEVICE_CONTROL.

### `DriverContext` [in]

An untyped pointer to driver-defined context information that the driver provided when it called [WdfDeviceConfigureWdmIrpDispatchCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurewdmirpdispatchcallback).

### `Irp` [in, out]

A pointer to an IRP structure.

### `DispatchContext` [in]

An untyped pointer to the framework's dispatch context information. The driver must provide this parameter when it calls [WdfDeviceWdmDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirp).

## Return value

The *EvtDeviceWdmIrpDispatch* callback function must:

* Return the value that the [WdfDeviceWdmDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirp) method returns, if the callback function calls that method.
* Return the value that the [WdfDeviceWdmDispatchIrpToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirptoioqueue) method returns, if the callback function calls that method.
* **KMDF only** Set the **IoStatus.Status** member of the IRP to STATUS_SUCCESS or another status value for which NT_SUCCESS(status) equals TRUE, and return the same value (after calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)) if the callback function successfully completes the received IRP.
* **KMDF only**Set the **IoStatus.Status** member of the IRP to a status value for which NT_SUCCESS(status) equals FALSE, and return the same value (after calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)) if the callback function detects an error.
* **KMDF only**Return STATUS_PENDING if the callback function calls [IoMarkIrpPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending).

## Remarks

The *EvtDeviceWdmIrpDispatch* callback function should only be used to select a specific queue for an IRP. To do so, the driver calls the [WdfDeviceWdmDispatchIrpToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirptoioqueue) method from within the callback function.

If, after examining an IRP in this callback function, the driver does not know how to dispatch the IRP, the driver can call [WdfDeviceWdmDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirp) to return the IRP to the framework for default handling.

A UMDF driver must call either [WdfDeviceWdmDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirp) or [WdfDeviceWdmDispatchIrpToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirptoioqueue) from this callback function. A KMDF driver has the additional option of calling neither, and instead completing the IRP or marking it pending.

To register an *EvtDeviceWdmIrpDispatch* callback function, your driver must call [WdfDeviceConfigureWdmIrpDispatchCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurewdmirpdispatchcallback).

In its *EvtDeviceWdmIrpDispatch* callback function, a driver should not set a completion routine. If a completion routine is needed, a KMDF driver can provide a [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function instead of *EvtDeviceWdmIrpDispatch*.

 For more information about specifying queues for IRPs as they arrive, see [Dispatching IRPs to I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-irps-to-i-o-queues).

## See also

[WdfDeviceConfigureWdmIrpDispatchCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurewdmirpdispatchcallback)

[WdfDeviceWdmDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirp)

[WdfDeviceWdmDispatchIrpToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirptoioqueue)