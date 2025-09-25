# GdiFlush function

## Description

The **GdiFlush** function flushes the calling thread's current batch.

## Return value

If all functions in the current batch succeed, the return value is nonzero.

If not all functions in the current batch succeed, the return value is zero, indicating that at least one function returned an error.

## Remarks

Batching enhances drawing performance by minimizing the amount of time needed to call GDI drawing functions that return Boolean values. The system accumulates the parameters for calls to these functions in the current batch and then calls the functions when the batch is flushed by any of the following means:

* Calling the **GdiFlush** function.
* Reaching or exceeding the batch limit set by the [GdiSetBatchLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdisetbatchlimit) function.
* Filling the batching buffers.
* Calling any GDI function that does not return a Boolean value.

The return value for **GdiFlush** applies only to the functions in the batch at the time **GdiFlush** is called. Errors that occur when the batch is flushed by any other means are never reported.

The [GdiGetBatchLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdigetbatchlimit) function returns the batch limit.

**Note** The batch limit is maintained for each thread separately. In order to completely disable batching, call [GdiSetBatchLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdisetbatchlimit) (1) during the initialization of each thread.

An application should call **GdiFlush** before a thread goes away if there is a possibility that there are pending function calls in the graphics batch queue. The system does not execute such batched functions when a thread goes away.

A multithreaded application that serializes access to GDI objects with a mutex must ensure flushing the GDI batch queue by calling **GdiFlush** as each thread releases ownership of the GDI object. This prevents collisions of the GDI objects (device contexts, metafiles, and so on).

## See also

[GdiGetBatchLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdigetbatchlimit)

[GdiSetBatchLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdisetbatchlimit)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)