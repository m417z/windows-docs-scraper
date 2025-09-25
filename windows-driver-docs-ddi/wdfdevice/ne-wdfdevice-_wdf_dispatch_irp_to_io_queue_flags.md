# _WDF_DISPATCH_IRP_TO_IO_QUEUE_FLAGS enumeration

## Description

[Applies to KMDF only]

The **WDF_DISPATCH_IRP_TO_IO_QUEUE_FLAGS** enumeration type defines flags that the driver can specify when it calls [WdfDeviceWdmDispatchIrpToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirptoioqueue).

## Constants

### `WDF_DISPATCH_IRP_TO_IO_QUEUE_NO_FLAGS:0x00000000`

No flags are set.

### `WDF_DISPATCH_IRP_TO_IO_QUEUE_INVOKE_INCALLERCTX_CALLBACK:0x00000001`

Specifies that the framework should call the [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) callback function before inserting the request into the queue.

### `WDF_DISPATCH_IRP_TO_IO_QUEUE_PREPROCESSED_IRP:0x00000002`

Specifies that the IRP was preprocessed by the driver's [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function. Accordingly, the framework adjusts the IRP's stack location to the next entry before inserting it into the queue.

## Remarks

 For more information about specifying queues for IRPs as they arrive, see [Dispatching IRPs to I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-irps-to-i-o-queues).

## See also

[EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess)

[WdfDeviceWdmDispatchIrpToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchirptoioqueue)