# WdfRequestWdmGetIrp function

## Description

[Applies to KMDF only]

The **WdfRequestWdmGetIrp** method returns the WDM [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure that is associated with a specified framework request object.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestWdmGetIrp** returns a pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The driver must not access a request's IRP structure after [completing the I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about **WdfRequestWdmGetIrp**, see [Obtaining Information About an I/O Request](https://learn.microsoft.com/windows-hardware/drivers/wdf/obtaining-information-about-an-i-o-request).

#### Examples

The following code example is part of an [EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control) callback function that obtains the WDM IRP that is associated with an I/O request and then calls [IoGetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetnextirpstacklocation) to obtain the next-lower driver's I/O stack location.

```cpp
VOID
MyEvtIoDeviceControl(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  OutputBufferLength,
    IN size_t  InputBufferLength,
    IN ULONG  IoControlCode
    )
{
    PIRP  irp = NULL;
    PIO_STACK_LOCATION  nextStack;
...
    irp = WdfRequestWdmGetIrp(Request);
    nextStack = IoGetNextIrpStackLocation(irp);
...
}
```

## See also

[WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters)