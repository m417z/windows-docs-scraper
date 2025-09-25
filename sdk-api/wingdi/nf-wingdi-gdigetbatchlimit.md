# GdiGetBatchLimit function

## Description

The **GdiGetBatchLimit** function returns the maximum number of function calls that can be accumulated in the calling thread's current batch. The system flushes the current batch whenever this limit is exceeded.

## Return value

If the function succeeds, the return value is the batch limit.

If the function fails, the return value is zero.

## Remarks

The batch limit is set by using the [GdiSetBatchLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdisetbatchlimit) function. Setting the limit to 1 effectively disables batching.

Only GDI drawing functions that return Boolean values can be batched; calls to any other GDI functions immediately flush the current batch. Exceeding the batch limit or calling the [GdiFlush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdiflush) function also flushes the current batch.

When the system batches a function call, the function returns **TRUE**. The actual return value for the function is reported only if [GdiFlush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdiflush) is used to flush the batch.

**Note** The batch limit is maintained for each thread separately. In order to completely disable batching, call [GdiSetBatchLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdisetbatchlimit) (1) during the initialization of each thread.

## See also

[GdiFlush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdiflush)

[GdiSetBatchLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdisetbatchlimit)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)