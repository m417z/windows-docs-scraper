# CcGetDirtyPages function

## Description

The **CcGetDirtyPages** routine searches for dirty pages in all files that match a given log handle.

## Parameters

### `LogHandle` [in]

Log handle stored by a previous call to **CcSetLogHandleForFile**.

### `DirtyPageRoutine` [in]

Pointer to a callback routine that builds up a dirty page table from the pages found. This routine, which is called for each dirty page found, is declared as follows:

```
typedef
VOID (*PDIRTY_PAGE_ROUTINE) (
            IN PFILE_OBJECT FileObject,
            IN PLARGE_INTEGER FileOffset,
            IN ULONG Length,
            IN PLARGE_INTEGER OldestLsn,
            IN PLARGE_INTEGER NewestLsn,
            IN PVOID Context1,
            IN PVOID Context2
            );
```

#### FileObject

Pointer to the file object for the file containing the dirty page.

#### FileOffset

Pointer to a variable that specifies the starting byte offset of the dirty page within the cached file.

#### Length

Length, in bytes, of the dirty page.

#### OldestLsn

Oldest logical sequence number (LSN) found in the dirty page.

#### NewestLsn

Newest LSN found in the dirty page.

#### Context1

First context parameter.

#### Context2

Second context parameter.

### `Context1` [in]

First context parameter to be passed to the *DirtyPageRoutine*.

### `Context2` [in]

Second context parameter to be passed to the *DirtyPageRoutine*.

## Return value

**CcGetDirtyPages** returns the oldest LSN found in the set of dirty pages. If there are no dirty pages, **CcGetDirtyPages** returns zero.

## Remarks

File systems call **CcGetDirtyPages** to return dirty pages in all files that match a given log handle. **CcGetDirtyPages** searches for dirty pages in all files that match the given *LogHandle* and calls the *DirtyPageRoutine* for each page.

To set a log handle for a file, use [CcSetLogHandleForFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetloghandleforfile).

## See also

[CcSetDirtyPinnedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetdirtypinneddata)

[CcSetLogHandleForFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetloghandleforfile)