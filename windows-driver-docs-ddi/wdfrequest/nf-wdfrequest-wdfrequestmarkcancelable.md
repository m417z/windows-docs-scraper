# WdfRequestMarkCancelable function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestMarkCancelable** method enables cancellation of a specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `EvtRequestCancel` [in]

A pointer to a driver-defined [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function, which the framework calls if it cancels the I/O request.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After your driver has [received an I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/receiving-i-o-requests) from the framework, the driver can call **WdfRequestMarkCancelable** or, starting with KMDF version 1.9, [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex) to make the request cancelable.

When calling **WdfRequestMarkCancelable**, your driver must specify an [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function. The framework calls the callback function if the I/O manager or another driver is attempting to cancel the I/O request.

### Choosing between WdfRequestMarkCancelable and WdfRequestMarkCancelableEx

If your driver uses the framework's [automatic synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization), the driver can call either **WdfRequestMarkCancelable** or [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex).

If the driver does not use automatic synchronization, it must call [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex) instead of **WdfRequestMarkCancelable** for the following reasons:

* If the specified request has already been canceled, **WdfRequestMarkCancelable** calls the driver's [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function before returning. If the driver acquires a spinlock before calling **WdfRequestMarkCancelable** and attempts to acquire the same spinlock inside *EvtRequestCancel*, the same thread attempts to acquire the same spinlock twice, causing a deadlock.
* However, because [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex) never calls [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel), this scenario does not occur. If the request has already been canceled, **WdfRequestMarkCancelableEx** returns **STATUS_CANCELLED**. If your driver acquires a spinlock (which sets the IRQL to DISPATCH_LEVEL) before calling **WdfRequestMarkCancelableEx** and releases the spinlock (which sets the IRQL to PASSIVE_LEVEL) after **WdfRequestMarkCancelableEx** returns, the *EvtRequestCancel* callback function will not be called before the spinlock is released. Therefore, a deadlock does not occur even if the *EvtRequestCancel* callback function uses the same spinlock.

### Processing a request after enabling cancellation

After a driver calls **WdfRequestMarkCancelable** to enable canceling, the request remains cancelable while the driver [owns](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) the request object, unless the driver calls [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable).

If a driver has called **WdfRequestMarkCancelable**, and if the driver's [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function has not executed and called [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete), the driver must call [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable) before it calls **WdfRequestComplete** outside of the *EvtRequestCancel* callback function.

If the driver calls [WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue) to forward the request to a different queue, the following rules apply:

* I/O requests cannot be cancelable when your driver forwards them to a different queue.

  Generally, your driver should not call **WdfRequestMarkCancelable** to enable canceling the request before calling [WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue). If the driver does make the request cancelable, it must call [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable) to disable cancellation before calling **WdfRequestForwardToIoQueue**.
* While the request is in the second queue, the framework owns it and can cancel it without notifying the driver.

  If the driver requires cancellation notification (so that it can deallocate any resources that it might have allocated before calling [WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue)), the driver should register an [EvtIoCanceledOnQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_canceled_on_queue) callback function, and it should use request-specific context memory to store information about the request's resources.
* After the framework has dequeued the request from the second queue and delivered it to the driver, the driver can call **WdfRequestMarkCancelable** to enable canceling.

For more information about **WdfRequestMarkCancelable**, see [Canceling I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests).

#### Examples

The following code example shows parts of two callback functions:

* An [EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read) callback function that performs request-specific work (such as creating subrequests to send to an I/O target), then enables cancellation of the received I/O request.
* An [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function that cancels an I/O request.

The driver must use the framework's [automatic synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization).

```cpp
VOID
MyEvtIoRead(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  Length
    )
{
...
    // Perform request-specific work here
    // (such as creating subrequests
    // to send to an I/O target).
...
    WdfRequestMarkCancelable(
                             Request,
                             MyEvtRequestCancel
                             );
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

## See also

[EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)

[WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue)

[WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex)

[WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable)