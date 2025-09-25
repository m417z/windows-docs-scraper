# WdfRequestIsCanceled function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestIsCanceled** method determines whether the I/O manager has attempted to cancel a specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestIsCanceled** returns **TRUE** if the I/O manager has attempted to cancel the specified I/O request. This method may return **TRUE** even if the calling driver does not own the request. If the driver does not own the request, it should not call **WdfRequestIsCanceled**. See additional information in Remarks.

**WdfRequestIsCanceled** returns **FALSE** for one of the following reasons:

* The I/O manager has not attempted to cancel the request.
* The calling driver does not own the request.
* The calling driver has called the [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable) or [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex) method.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If your driver has not called [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable) or [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex) to register an [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function, but if you want your driver to determine if the I/O manager has attempted to cancel an I/O request, the driver can call **WdfRequestIsCanceled**.

If the driver has called [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable) or [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex), it must call [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable) before calling **WdfRequestIsCanceled**.

A driver can call **WdfRequestIsCanceled** for a request only if the driver [owns](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) the I/O request.

If **WdfRequestIsCanceled** returns **TRUE**, your driver should cancel the request by calling [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) with a *Status* parameter of STATUS_CANCELLED. If the driver attempts to complete a request that it does not own, the driver can cause the system to crash.

For more information about **WdfRequestIsCanceled**, see [Canceling I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests)

#### Examples

The following code example calls [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) if **WdfRequestIsCanceled** returns **TRUE**.

```cpp
if (WdfRequestIsCanceled(request)) {
    WdfRequestComplete(
                       request,
                       STATUS_CANCELLED
                       );
}
```

## See also

[EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)

[WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable)

[WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex)

[WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable)