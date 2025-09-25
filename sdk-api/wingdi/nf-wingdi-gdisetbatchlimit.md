# GdiSetBatchLimit function

## Description

The **GdiSetBatchLimit** function sets the maximum number of function calls that can be accumulated in the calling thread's current batch. The system flushes the current batch whenever this limit is exceeded.

## Parameters

### `dw` [in]

Specifies the batch limit to be set. A value of 0 sets the default limit. A value of 1 disables batching.

## Return value

If the function succeeds, the return value is the previous batch limit.

If the function fails, the return value is zero.

## Remarks

Only GDI drawing functions that return Boolean values can be accumulated in the current batch; calls to any other GDI functions immediately flush the current batch. Exceeding the batch limit or calling the [GdiFlush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdiflush) function also flushes the current batch.

When the system accumulates a function call, the function returns **TRUE** to indicate it is in the batch. When the system flushes the current batch and executes the function for the second time, the return value is either **TRUE** or **FALSE**, depending on whether the function succeeds. This second return value is reported only if [GdiFlush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdiflush) is used to flush the batch.

**Note** The batch limit is maintained for each thread separately. In order to completely disable batching, call **GdiSetBatchLimit** (1) during the initialization of each thread.

## See also

[GdiFlush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdiflush)

[GdiGetBatchLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdigetbatchlimit)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)