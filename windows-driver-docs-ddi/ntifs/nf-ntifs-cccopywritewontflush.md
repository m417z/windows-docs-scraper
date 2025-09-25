# CcCopyWriteWontFlush function

## Description

The **CcCopyWriteWontFlush** macro determines whether the amount of data to be copied in a call to [CcCopyWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite) is small enough not to require immediate flushing to disk if **CcCopyWrite** is called with *Wait* set to **FALSE**.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file to which the data is to be written.

### `FileOffset` [in]

Pointer to a variable that specifies the starting byte offset within the cached file where the data is to be written.

### `Length` [in]

Length in bytes of the data to be copied.

## Return value

**CcCopyWriteWontFlush** returns **TRUE** if the amount of data to be copied in a call to [CcCopyWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite) is small enough not to require immediate flushing to disk, **FALSE** otherwise.

## See also

[CcCanIWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccaniwrite)

[CcCopyWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite)

[CcDeferWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccdeferwrite)