# CcZeroData function

## Description

The **CcZeroData** routine zeros the specified range of bytes in a cached or noncached file.

> [!NOTE]
> This routine should only be called to zero portions of a file beyond the file's valid data length. **CcZeroData** will not modify any previously written data of the file. To zero previously written data that is portion of the file up to the file’s valid data length, call [**CcCopyWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite), or one of the other cached write interfaces.

## Parameters

### `FileObject` [in]

A pointer to a [**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) for the file in which a range of bytes is to be zeroed.

### `StartOffset` [in]

A pointer to a variable that specifies the byte offset within the file to the first byte that is to be zeroed.

### `EndOffset` [in]

A pointer to a variable that specifies the byte offset within the file to the last byte that is to be zeroed.

### `Wait` [in]

Set to **TRUE** if the caller should be put into a wait state until the entire byte range has been zeroed. Otherwise, this parameter is set to **FALSE**.

## Return value

**CcZeroData** returns **TRUE** if the data is zeroed successfully; otherwise, returns **FALSE**.

## Remarks

The file to be zeroed can be cached or noncached. However, if the file is noncached, the values of *StartOffset* and *EndOffset* must both be multiples of the volume's sector size.

If a pool allocation failure occurs and *Wait* was specified as **TRUE**, **CcZeroData** raises a STATUS_INSUFFICIENT_RESOURCES exception. If a pool allocation failure occurs and *Wait* was specified as **FALSE**, **CcZeroData** returns **FALSE**, but does not raise an exception.

If the *FileObject* supplied does not have caching enabled, but caching exists on the stream (that is, another file object for the same file has caching enabled), then zeroing will be treated as though write-through caching is enabled.

If *Wait* is set to **TRUE**, **CcZeroData** is guaranteed to complete the zero data request and return **TRUE**. If the required pages of the cached file are already resident in memory, the data will be zeroed immediately and no blocking will occur. If any needed pages are not resident, the caller will be put in a wait state until all required pages have been made resident and the data can be zeroed.

If *Wait* is **FALSE** and if the required pages of the cached file are not already resident in memory, **CcZeroData** will refuse to block and will return **FALSE**.

If a pool allocation failure occurs, **CcZeroData** raises a STATUS_INSUFFICIENT_RESOURCES exception. If **CcZeroData** encounters any other errors, including IO errors, the errors will be raised to the caller.

For Windows Vista and later Windows operating systems, the behavior of **CcZeroData** is as follows:

- If the stream is cached and write_through, *StartOffset* does not have to be sector aligned.
- If *EndOffset* is not aligned, it will be rounded up to the next sector size.

## See also

[**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[**CcIsFileCached**](https://learn.microsoft.com/previous-versions/ff539143(v=vs.85))

[**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)