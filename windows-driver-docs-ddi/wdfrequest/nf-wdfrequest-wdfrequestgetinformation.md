# WdfRequestGetInformation function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestGetInformation** method returns completion status information for a specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestGetInformation** returns the information that a lower-level driver set by calling [WdfRequestSetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetinformation) or [WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A driver can call [WdfRequestSetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetinformation) or [WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation) to set completion status information for an I/O request. Your driver can call **WdfRequestGetInformation** after a lower-level driver completes a request, to obtain completion status information that the lower-level driver set.

If your driver calls **WdfRequestGetInformation** after it calls [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) to complete the request, **WdfRequestGetInformation** returns **NULL**.

For more information about **WdfRequestGetInformation**, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

#### Examples

The following code example sends an I/O request to an I/O target and then obtains status information that the I/O target provided.

```cpp
ULONG_PTR  informationRetrieved = NULL;

status = WdfIoTargetSendWriteSynchronously(
                                           ioTarget,
                                           request,
                                           &outputMemoryDescriptor,
                                           NULL,
                                           NULL,
                                           &bytesWritten
                                           );
if (NT_SUCCESS(status)) {
    informationRetrieved = WdfRequestGetInformation(request);
}
```

## See also

[WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation)

[WdfRequestSetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetinformation)