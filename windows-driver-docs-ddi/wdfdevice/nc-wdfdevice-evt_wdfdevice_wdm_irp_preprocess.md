# EVT_WDFDEVICE_WDM_IRP_PREPROCESS callback function

## Description

[Applies to KMDF only]

A driver's *EvtDeviceWdmIrpPreprocess* event callback function receives an IRP before the framework processes the IRP.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Irp` [in, out]

A pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure.

## Return value

The *EvtDeviceWdmIrpPreprocess* callback function must:

* Set the **IoStatus.Status** member of the IRP to STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(status) equals **TRUE**, and return the same value (after calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)), if the callback function successfully completes the received IRP.
* Set the **IoStatus.Status** member of the IRP to a status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(status) equals **FALSE**, and return the same value (after calling IoCompleteRequest), if the callback function detects an error.
* Return STATUS_PENDING, if the callback function calls [IoMarkIrpPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending).
* Return the value that the [WdfDeviceWdmDispatchPreprocessedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchpreprocessedirp) method returns, if the callback function calls that method.

## Remarks

To register an *EvtDeviceWdmIrpPreprocess* callback function, your driver must call [WdfDeviceInitAssignWdmIrpPreprocessCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignwdmirppreprocesscallback).

Your driver can use an *EvtDeviceWdmIrpPreprocess* callback function to do any, or all, of the following:

* Handle an IRP that the framework does not support, by following the [WDM rules for handling IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-irps).
* Preprocess an IRP before the framework handles it.
* Set a completion routine so that the driver can postprocess an IRP after the framework handles it.

For more information about how to implement an *EvtDeviceWdmIrpPreprocess* callback function, see [Handling WDM IRPs Outside of the Framework](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-wdm-irps-outside-of-the-framework).

If you want the framework to subsequently handle the IRP as it would if the *EvtDeviceWdmIrpPreprocess* callback function had not been called, the callback function must call [WdfDeviceWdmDispatchPreprocessedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchpreprocessedirp) to return the IRP to the framework.

If your driver registers an *EvtDeviceWdmIrpPreprocess* callback function, the framework adds an additional [I/O stack location](https://learn.microsoft.com/windows-hardware/drivers/kernel/i-o-stack-locations) to IRPs that the callback function receives. The additional I/O stack location allows the callback function to set an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine before it calls [WdfDeviceWdmDispatchPreprocessedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchpreprocessedirp).

The *EvtDeviceWdmIrpPreprocess* callback function is called at the IRQL of the calling thread. The IRQL is determined by the type of IRP that the framework is passing to *EvtDeviceWdmIrpPreprocess*. For example, if the PnP manager sends [IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) at IRQL = PASSIVE_LEVEL, the framework calls *EvtDeviceWdmIrpPreprocess* at IRQL = PASSIVE_LEVEL.

## See also

[WdfDeviceInitAssignWdmIrpPreprocessCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignwdmirppreprocesscallback)

[WdfDeviceWdmDispatchPreprocessedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchpreprocessedirp)