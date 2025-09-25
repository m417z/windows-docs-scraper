# WdfDeviceInitAssignWdmIrpPreprocessCallback function

## Description

[Applies to KMDF only]

The **WdfDeviceInitAssignWdmIrpPreprocessCallback** method registers a callback function to handle an IRP major function code and, optionally, one or more minor function codes that are associated with the major function code.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `EvtDeviceWdmIrpPreprocess` [in]

A pointer to the driver's [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function.

### `MajorFunction` [in]

One of the IRP major function codes that are defined in *wdm.h*.

### `MinorFunctions` [in, optional]

A pointer to an array of one or more IRP minor function codes that are associated with the specified major function code. This parameter is optional and can be **NULL**. For more information, see the following Remarks section.

### `NumMinorFunctions` [in]

The number of minor function codes that are contained in the *MinorFunctions* array.

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *MajorFunction* value is invalid. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory. |
| **STATUS_INVALID_DEVICE_REQUEST** | The driver previously registered a *MinorFunctions* array for this major function and is attempting to specify minor functions again for the specified *MajorFunction* code. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Drivers can call the **WdfDeviceInitAssignWdmIrpPreprocessCallback** method for either of two reasons:

* To handle an IRP major or minor function code that the framework does not support.

  For example, the framework does not support [IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers). If your driver must support this IRP, it must register an [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function that handles the IRP. The driver must follow WDM rules for processing IRPs.
* To preprocess an IRP before the framework handles it.

  In rare cases, it might be necessary for a driver to process an IRP before the framework processes it. In such cases, the driver's [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function can process the IRP and then call [WdfDeviceWdmDispatchPreprocessedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchpreprocessedirp) to return the IRP to the framework. Depending on the IRP's function code, the framework might process the IRP itself or it might deliver the IRP to the driver again in a framework request object.

The framework calls the [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function whenever it receives an I/O request packet (IRP) that contains an IRP major function code that matches the *MajorFunction* parameter and a minor function code that matches one of the minor function codes that are in the *MinorFunctions* array.

If the *MinorFunctions* array pointer is **NULL**, the framework calls the callback function for all minor function codes that are associated with the specified major function code. If the *MinorFunctions* array pointer is not **NULL**, the framework makes a copy of the array so that the driver does not have to permanently keep its array.

If the driver received *DeviceInit* pointer from [WdfPdoInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitallocate) or an [EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device) event callback function, the driver's [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function cannot set a completion routine for IRPs that contain a major function code of IRP_MJ_PNP. Otherwise, [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development) will report an error.

If your driver calls **WdfDeviceInitAssignWdmIrpPreprocessCallback** one or more times, the framework increments the **StackSize** member of the driver's WDM [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure one time. As a result, the I/O manager adds an additional [I/O stack location](https://learn.microsoft.com/windows-hardware/drivers/kernel/i-o-stack-locations) to all IRPs so that the [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function can set an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine. Note that this extra I/O stack location is added to all IRPs, not just the ones that contain an IRP major function code that you specify in a call to **WdfDeviceInitAssignWdmIrpPreprocessCallback**. Therefore, to avoid unnecessarily increasing your driver's use of the nonpaged memory pool, you should avoid using **WdfDeviceInitAssignWdmIrpPreprocessCallback** unless there is no alternative.

If your driver calls **WdfDeviceInitAssignWdmIrpPreprocessCallback** more than once for the same major code, the framework retains only the most recently set [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) callback function for this major code. (Your driver can’t register multiple preprocess callbacks for a single major code.)

For more information about the **WdfDeviceInitAssignWdmIrpPreprocessCallback** method, see [Handling WDM IRPs Outside of the Framework](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-wdm-irps-outside-of-the-framework).

#### Examples

The following code example defines an [EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess) event callback function, and then registers the callback function to handle [IRP_MJ_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-information) IRPs.

```cpp
NTSTATUS
SerialQueryInformationFile(
    IN WDFDEVICE Device,
    IN PIRP Irp
    )

/*++

Routine Description:

    This routine is used to query the end of file information on
    the opened serial port.  Any other file information request
    is returned with an invalid parameter.

    This routine always returns an end of file of 0.

Arguments:

    DeviceObject - Pointer to the device object for this device

    Irp - Pointer to the IRP for the current request

Return Value:

    The function value is the final status of the call

--*/

{
    NTSTATUS Status;
    PIO_STACK_LOCATION IrpSp;

    SerialDbgPrintEx(TRACE_LEVEL_INFORMATION, DBG_PNP, ">SerialQueryInformationFile(%p, %p)\n", Device, Irp);

    PAGED_CODE();

    IrpSp = IoGetCurrentIrpStackLocation(Irp);
    Irp->IoStatus.Information = 0L;
    Status = STATUS_SUCCESS;

    if (IrpSp->Parameters.QueryFile.FileInformationClass ==
        FileStandardInformation) {

        if (IrpSp->Parameters.DeviceIoControl.OutputBufferLength <
                sizeof(FILE_STANDARD_INFORMATION))
        {
                Status = STATUS_BUFFER_TOO_SMALL;
        }
        else
        {
            PFILE_STANDARD_INFORMATION Buf = Irp->AssociatedIrp.SystemBuffer;

            Buf->AllocationSize.QuadPart = 0;
            Buf->EndOfFile = Buf->AllocationSize;
            Buf->NumberOfLinks = 0;
            Buf->DeletePending = FALSE;
            Buf->Directory = FALSE;
            Irp->IoStatus.Information = sizeof(FILE_STANDARD_INFORMATION);
        }

    } else if (IrpSp->Parameters.QueryFile.FileInformationClass ==
               FilePositionInformation) {

        if (IrpSp->Parameters.DeviceIoControl.OutputBufferLength <
                sizeof(FILE_POSITION_INFORMATION))
        {
                Status = STATUS_BUFFER_TOO_SMALL;
        }
        else
        {

            ((PFILE_POSITION_INFORMATION)Irp->AssociatedIrp.SystemBuffer)->
                CurrentByteOffset.QuadPart = 0;
            Irp->IoStatus.Information = sizeof(FILE_POSITION_INFORMATION);
        }

    } else {
        Status = STATUS_INVALID_PARAMETER;
    }

    Irp->IoStatus.Status = Status;

    IoCompleteRequest(Irp, IO_NO_INCREMENT);

    return Status;

}

NTSTATUS
SerialEvtDeviceAdd(
    IN WDFDRIVER Driver,
    IN PWDFDEVICE_INIT DeviceInit
    )
{
...
    status = WdfDeviceInitAssignWdmIrpPreprocessCallback(
                                                 DeviceInit,
                                                 SerialQueryInformationFile,
                                                 IRP_MJ_QUERY_INFORMATION,
                                                 NULL, // Pointer to the minor function table
                                                 0 // Number of entries in the table
                                                 );
    if (!NT_SUCCESS(status)) {
        return status;
    }
...
}
```

## See also

[WdfDeviceWdmDispatchPreprocessedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmdispatchpreprocessedirp)