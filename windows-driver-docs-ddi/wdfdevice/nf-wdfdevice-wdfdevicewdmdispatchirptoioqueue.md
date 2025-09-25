# WdfDeviceWdmDispatchIrpToIoQueue function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceWdmDispatchIrpToIoQueue** method forwards the IRP to a specified I/O queue.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Irp` [in]

A pointer to an IRP structure.

### `Queue` [in]

A handle to a framework queue object.

### `Flags` [in]

A bitwise **OR** of [WDF_DISPATCH_IRP_TO_IO_QUEUE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_dispatch_irp_to_io_queue_flags)-typed flags.

## Return value

The **WdfDeviceWdmDispatchIrpToIoQueue** method returns an NTSTATUS value that the framework or the driver provides as a result of processing the IRP. The driver must use this return value as the return value for the [EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch) or the [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function that called **WdfDeviceWdmDispatchIrpToIoQueue**.

A bug check occurs if a KMDF driver supplies an invalid object handle. If a UMDF driver supplies an invalid handle, the driver host process terminates.

## Remarks

A driver calls **WdfDeviceWdmDispatchIrpToIoQueue** to specify a target queue for an incoming IRP.

The driver can call this method from its [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback routine or from its [EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch) callback.

If the driver calls **WdfDeviceWdmDispatchIrpToIoQueue** from within a [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function, the driver must call either [IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation) or [IoCopyCurrentIrpStackLocationToNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocopycurrentirpstacklocationtonext) prior to calling **WdfDeviceWdmDispatchIrpToIoQueue**.

 For more information about specifying queues for IRPs as they arrive, see [Dispatching IRPs to I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-irps-to-i-o-queues).

## See also

[EvtDeviceWdmIrpDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_dispatch)

[EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess)