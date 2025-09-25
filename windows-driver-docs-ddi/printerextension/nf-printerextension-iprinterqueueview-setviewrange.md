## Description

Sets the range of print jobs being monitored.

## Parameters

### `ulViewOffset` [in]

The start of the range of jobs being monitored. Note that the offset value uses a zero-based index.

### `ulViewSize` [in]

The size of the range of jobs being monitored.

## Return value

This method returns the appropriate **HRESULT** value.

## Remarks

Invoking this method causes the events for status change to the jobs to be fired. The [IPrinterQueueViewEvent::OnChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterqueueviewevent-onchanged) event method returns the live queue in response, using the specified maximum range size.

*ulViewSize* must be specified as a value less than or equal to 25. If the caller specifies a size which exceeds 25, this method will return E_INVALIDARG.

## See also

[IPrinterQueue2::GetPrinterQueueView](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterqueue2-getprinterqueueview)

[IPrinterQueueView](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueueview)

[IPrinterQueueViewEvent::OnChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterqueueviewevent-onchanged)