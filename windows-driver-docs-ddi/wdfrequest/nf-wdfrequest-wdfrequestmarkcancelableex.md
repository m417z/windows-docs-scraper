# WdfRequestMarkCancelableEx function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestMarkCancelableEx** method enables cancellation of a specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `EvtRequestCancel` [in]

A pointer to a driver-defined [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function, which the framework calls if it cancels the I/O request.

## Return value

**WdfRequestMarkCancelableEx** returns STATUS_SUCCESS if it successfully enables cancellation of the specified I/O request. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_CANCELLED** | The I/O request has been canceled. See Remarks for more info. |
| **STATUS_INVALID_DEVICE_REQUEST** | * The driver does not own the I/O request.<br>* The I/O request is already cancelable. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

After your driver has [received an I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/receiving-i-o-requests) from the framework, the driver can call [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable) or, starting with KMDF version 1.9, **WdfRequestMarkCancelableEx** to make the request cancelable. For info on choosing between the two methods, see [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable).

When calling **WdfRequestMarkCancelableEx**, your driver must specify an [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function. The framework calls the callback function if the I/O manager or another driver is attempting to cancel the I/O request.

If **WdfRequestMarkCancelableEx** returns failure, the driver must perform the same cancellation activities that the [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function performs. For example:

1. Finish or stop processing the request, along with subrequests that it might have created.
2. Call [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete), specifying a status value of STATUS_CANCELLED.

See the code examples below for implementation.

Because **WdfRequestMarkCancelableEx** never calls [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel), this method is safe from the deadlock risk described in the Remarks of [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable).

### Processing a request after enabling cancellation

After a driver calls **WdfRequestMarkCancelableEx** to enable canceling, the request remains cancelable while the driver [owns](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) the request object, unless the driver calls [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable).

If a driver has called **WdfRequestMarkCancelableEx**, and if the driver's [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function has not executed and called [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete), the driver must call [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable) before it calls **WdfRequestComplete** outside of the *EvtRequestCancel* callback function.

If the driver calls [WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue) to forward the request to a different queue, the following rules apply:

* I/O requests cannot be cancelable when your driver forwards them to a different queue.

  Generally, your driver should not call **WdfRequestMarkCancelableEx** to enable canceling the request before calling [WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue). If the driver does make the request cancelable, it must call [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable) to disable cancellation before calling **WdfRequestForwardToIoQueue**.
* While the request is in the second queue, the framework owns it and can cancel it without notifying the driver.

  If the driver requires cancellation notification (so that it can deallocate any resources that it might have allocated before calling [WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue)), the driver should register an [EvtIoCanceledOnQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_canceled_on_queue) callback function, and it should use request-specific context memory to store information about the request's resources.
* After the framework has dequeued the request from the second queue and delivered it to the driver, the driver can call **WdfRequestMarkCancelableEx** to enable canceling.

For more information about **WdfRequestMarkCancelableEx**, see [Canceling I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests).

#### Examples

The following code examples show parts of two callback functions:

* An [EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read) callback function that performs request-specific work (such as creating subrequests to send to an I/O target), then enables cancellation of the received I/O request.
* An [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function that cancels an I/O request.

In the first example, the driver is using the framework's [automatic synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization). In the second example, the driver is providing its own synchronization by using spinlocks.

**Example 1: A driver that uses automatic synchronization.**

```cpp
VOID
MyEvtIoRead(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  Length
    )
{
...
    NTSTATUS status;
...
    // Perform request-specific work here
    // (such as creating subrequests
    // to send to an I/O target).
...
    status = WdfRequestMarkCancelableEx(
                                        Request,
                                        MyEvtRequestCancel
                                        );

    if (!NT_SUCCESS(status)) {
       // Remove request-specific work here, because
       // we don't want the work to be done if the
       // request was canceled or an error occurred.

        WdfRequestComplete (Request, status);
    }
...
}

VOID
MyEvtRequestCancel(
    IN WDFREQUEST  Request
 )
{
    // Remove request-specific work here, because
    // we don't want the work to be done if the
    // request was canceled.

    WdfRequestComplete(
                       Request,
                       STATUS_CANCELLED
                       );
}
```
**Example 2: A driver that uses its own synchronization.**

```cpp
VOID
MyEvtIoRead(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  Length
    )
{
...
    NTSTATUS status;
...
    WdfSpinlockAcquire(MyCancelSpinLock);
    // Perform request-specific work here
    // (such as creating subrequests
    // to send to an I/O target).
...
    status = WdfRequestMarkCancelableEx(
                                        Request,
                                        MyEvtRequestCancel
                                        );

    if (!NT_SUCCESS(status)) {
        // Remove request-specific work here, because
        // we don't want the work to be done if the
        // request was canceled or an error occurred.
     }
    WdfSpinlockRelease(MyCancelSpinLock);
    if (!NT_SUCCESS(status)) {
        WdfRequestComplete (
                            Request,
                            Status
                            );
    }
...
}
VOID
MyEvtRequestCancel(
    IN WDFREQUEST  Request
 )
{
    WdfSpinlockAcquire(MyCancelSpinLock);
    // Remove request-specific work here, because
    // we don't want the work to be done if the
    // request was canceled.
    WdfSpinlockRelease(MyCancelSpinLock);
    WdfRequestComplete (Request, STATUS_CANCELLED);
}
```

## See also

[EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)

[WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue)

[WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable)

[WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable)