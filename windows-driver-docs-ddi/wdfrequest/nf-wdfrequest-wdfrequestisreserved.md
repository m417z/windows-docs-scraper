# WdfRequestIsReserved function

## Description

[Applies to KMDF only]

The **WdfRequestIsReserved** method determines whether a specified request object is one that the framework reserved to support [guaranteed forward progress](https://learn.microsoft.com/windows-hardware/drivers/wdf/guaranteeing-forward-progress-of-i-o-operations) during low-memory situations.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestIsReserved** returns **TRUE** if the specified request object is one that the framework pre-allocated for low-memory situations. Otherwise the method returns **FALSE**.

## Remarks

For more information about the **WdfRequestIsReserved** method, see [Guaranteeing Forward Progress of I/O Operations](https://learn.microsoft.com/windows-hardware/drivers/wdf/guaranteeing-forward-progress-of-i-o-operations).

#### Examples

The following code example determines whether a request object that a driver's [EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read) callback function has received is one that the driver created for low-memory situations.

```cpp
VOID
  MyIoRead (
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  Length
    )
  {...
  if (WdfRequestIsReserved(Request)) {
  // Low memory situation exists.
  ...
  }
  else {
  // Low memory situation does not exist.
  ...
  }

  ...}
```

## See also

[WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy)