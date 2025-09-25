# ISimilarityReportProgress::ReportProgress

## Description

Reports the current completion percentage of a similarity operation in progress.

## Parameters

### `percentCompleted` [in]

The current completion percentage of the task. The valid range is from 0 through 100.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [ISimilarity::CopyAndSwap](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilarity-copyandswap) method calls the **ReportProgress** method to report the progress of the copy-and-swap operation. To receive the progress information, RDC applications must implement this method.

No guarantee is made as to how frequently this method is called, nor that it will be called with any specific values for the *percentCompleted* parameter. For example, the *percentCompleted* parameter may not start at zero and may never reach 100, and it may receive the same value more than once. However, each value is guaranteed to be greater than or equal to the previous value.

If the application returns an error code such as **E_FAIL**, the similarity operation is stopped, and the error code is propagated.

## See also

[ISimilarityReportProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarityreportprogress)