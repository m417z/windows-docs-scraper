## Description

Provides an [IPrintJobCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintjobcollection) object that provides a snapshot of a range of print jobs in the queue.

## Parameters

### `pCollection` [in]

An [IPrintJobCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintjobcollection) object.

### `ulViewOffset` [in]

The start of the range of jobs being monitored.

### `ulViewSize` [in]

The range of jobs being monitored.

### `ulCountJobsInPrintQueue` [in]

The current number of jobs in the print queue.

## Return value

This method returns the appropriate **HRESULT** value.

## Remarks

The job range is controlled by the [IPrinterQueueView](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueueview) interface. Additionally, this method provides the current number of jobs in the print queue, and the indices of the job range being monitored. Information about the number of jobs, and the indices of the jobs is provided in response to the [IPrinterQueueView::SetViewRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterqueueview-setviewrange) method being invoked.

## See also

[IPrintJobCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintjobcollection)

[IPrinterQueueView](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueueview)

[IPrinterQueueView::SetViewRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterqueueview-setviewrange)

[IPrinterQueueViewEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueueviewevent)