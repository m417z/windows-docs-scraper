# CcCanIWrite function

## Description

The **CcCanIWrite** routine determines whether the caller can write to a cached file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file.

### `BytesToWrite` [in]

Number of bytes to be written.

### `Wait` [in]

Set to TRUE if the caller can be put into a wait state until it can write to the cached file, FALSE otherwise.

### `Retrying` [in]

Set to FALSE if this is the first time **CcCanIWrite** is being called for this write request, TRUE otherwise.

## Return value

**CcCanIWrite** returns TRUE if the cache manager can accept the write request, FALSE otherwise.

## Remarks

**CcCanIWrite** should be called before calling [**CcCopyWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite) or [**CcFastCopyWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccfastcopywrite).

If **CcCanIWrite** returns TRUE, the caller can immediately call [**CcCopyWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite) or [**CcFastCopyWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccfastcopywrite).

If **CcCanIWrite** returns FALSE, the caller must instead call [**CcDeferWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccdeferwrite) to defer the write request.

Generally speaking, the cache manager can accept a write request if the following conditions are true:

* The amount of data to be written is not too large.

* There is enough memory to perform the write operation.

* The number of dirty pages in the system cache does not exceed the dirty page threshold (CcDirtyPageThreshold).

* If a per-file dirty page threshold exists for this file, it is not exceeded by the number of dirty pages for this file in the system cache.

To cache a file, use [**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

## See also

[**CcCopyWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite)

[**CcDeferWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccdeferwrite)

[**CcFastCopyWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccfastcopywrite)

[**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[**CcSetDirtyPageThreshold**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetdirtypagethreshold)