# IFileOperationProgressSink::UpdateProgress

## Description

Provides an estimate of the total amount of work currently done in relation to the total amount of work.

## Parameters

### `iWorkTotal` [in]

Type: **UINT**

An estimate of the amount of work to be completed.

### `iWorkSoFar` [in]

Type: **UINT**

The portion of *iWorkTotal* that has been completed so far.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *iWorkTotal* and *iWorkSoFar* values are "points" or estimates of the amount of work to be done, and how much is completed. They are not specified in any particular units, but should be roughly proportional to how much time the total process takes. For example, to copy one small file might be considered two points, and a large file might be considered ten points. If a process is performing an operation that copies five small files and one large file, and the process has completed four of the small files, *iWorkSoFar* would be eight points (4 x 2 = 8) and *iWorkTotal* would be twenty points (5 x 2 + 10 = 20), so the estimate would be 8 of 20 points (or 40%) complete.