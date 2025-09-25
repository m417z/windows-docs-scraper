# WdfDeviceWdmDispatchIrp function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceWdmDispatchIrp** method returns a dispatched IRP to the framework from [EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch).

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Irp` [in]

A pointer to an IRP structure.

### `DispatchContext` [in]

The dispatch context parameter the driver received in [EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch) callback.

## Return value

The **WdfDeviceWdmDispatchIrp** method returns an NTSTATUS value that the framework or the driver provides as a result of processing the IRP. The driver must use this return value as the return value for the [EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch) callback function that called **WdfDeviceWdmDispatchIrp**.

A bug check occurs if a KMDF driver supplies an invalid object handle. If a UMDF driver supplies an invalid handle, the driver host process terminates.

## Remarks

If your driver provides an [EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch) callback function, you can call **WdfDeviceWdmDispatchIrp** from within the callback function to return the IRP to the framework for default processing instead of dispatching it to a specific queue.

 For more information about specifying queues for IRPs as they arrive, see [Dispatching IRPs to I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-irps-to-i-o-queues).

## See also

[EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch)

[WdfDeviceWdmDispatchIrpToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirptoioqueue)