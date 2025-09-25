## Description

Retrieves an [IPrinterQueueView](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueueview) object, and initializes the object with the range of jobs to be monitored.

This method allows the user to perform job management tasks from within a UWP device app for printers.

## Parameters

### `ulViewOffset` [in]

Indicates the start of the range of jobs to be monitored.

### `ulViewSize` [in]

Indicates the size or the range of jobs to be monitored.

### `ppJobView` [out, retval]

IPrinterQueueView object that shows the range of jobs to be monitored.

## Return value

If the method call is successful, **GetPrinterQueueView** returns S_OK.

Otherwise, if a call to **GetPrinterQueueView** results in an error condition, then one of the following **HRESULT** values can be returned.

| HRESULT value | Description |
|--|--|
| E_ILLEGAL_METHOD_CALL | Indicates an attempt to retrieve more than one printer queue view object. |
| E_INVALIDARG | Indicates an attempt to create a view size larger than the maximum size. |

## Remarks

Only one [IPrinterQueueView](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueueview) object can be retrieved per [IPrinterQueue2](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueue2) object.
However it is possible to move around the single view that you retrieve. In other words, it is possible to change the positions of the monitored jobs by invoking [IPrinterQueueView::SetViewRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterqueueview-setviewrange).

## See also

[IPrinterQueue2](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueue2)

[IPrinterQueueView](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueueview)