# WdfDeviceWdmDispatchPreprocessedIrp function

## Description

[Applies to KMDF only]

The **WdfDeviceWdmDispatchPreprocessedIrp** method returns a preprocessed IRP to the framework.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Irp` [in]

A pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure.

## Return value

**WdfDeviceWdmDispatchPreprocessedIrp** returns an NTSTATUS value that the framework or the driver provides as the result of processing the IRP. The driver must use this return value as the return value for the [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A framework-based driver that preprocesses or postprocesses WDM IRPs must call **WdfDeviceWdmDispatchPreprocessedIrp**, typically from within the driver's [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function. For more information about how to call **WdfDeviceWdmDispatchPreprocessedIrp**, see [Preprocessing and Postprocessing IRPs](https://learn.microsoft.com/windows-hardware/drivers/wdf/preprocessing-and-postprocessing-irps).

#### Examples

For a code example that uses **WdfDeviceWdmDispatchPreprocessedIrp**, see [Preprocessing and Postprocessing IRPs](https://learn.microsoft.com/windows-hardware/drivers/wdf/preprocessing-and-postprocessing-irps).