# CcPreparePinWrite function

## Description

The **CcPreparePinWrite** routine pins the specified byte range of a cached file for write access.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file to which the data is to be written.

### `FileOffset` [in]

Pointer to a variable that specifies the starting byte offset within the file where the data is to be written.

### `Length` [in]

Length of desired data in bytes.

### `Zero` [in]

Set to **TRUE** if the buffer is to be zeroed on return. This parameter is ignored if the PIN_CALLER_TRACKS_DIRTY_DATA flag is set in the *Flags* parameter.

### `Flags` [in]

Bitmask of flags specifying how the pinning operation is to be performed. ORed combination of one or more of the following values:

| Value | Meaning |
| --- | --- |
| PIN_WAIT | The caller can be put into a wait state until the data has been pinned. |
| PIN_EXCLUSIVE | The buffer control block (BCB) is to be acquired exclusively. |
| PIN_NO_READ | Only pages that are already resident in memory are to be pinned. If this flag is set, PIN_WAIT must also be set. |
| PIN_IF_BCB | The data is to be pinned only if a BCB already exists. Otherwise, the pin fails and no BCB is returned. |
| PIN_CALLER_TRACKS_DIRTY_DATA | The caller is responsible for keeping track of dirty pages. If this flag is set, all other flags are ignored. This flag is available on Microsoft Windows Server 2003 SP1 and later. |

### `Bcb` [out]

Opaque pointer to a pinned buffer control block (BCB). This pointer must be supplied as input on any subsequent calls to **CcPreparePinWrite** or [CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata) for this buffer.

### `Buffer` [out]

Returns pointer to desired data, valid until the buffer is unpinned or freed.

## Return value

**CcPreparePinWrite** returns **TRUE** if the cached file was pinned successfully, **FALSE** otherwise.

## Remarks

**CcPreparePinWrite** pins the specified file pages in the system cache. Pages to be completely overwritten may be satisfied with pages of zeros.

If the PIN_WAIT flag is set, **CcPreparePinWrite** is guaranteed to complete the preparation request and return **TRUE**. If all of the pages can be prepared immediately, no blocking occurs. If any needed pages are not resident, the caller is put in a wait state until all required pages have been made resident and the pages can be prepared. If the PIN_WAIT flag is not set, but not all of the pages can be prepared immediately, **CcPreparePinWrite** returns **FALSE**, and its output parameter values are meaningless.

**Microsoft Windows Server 2003 SP1 and later:** The PIN_CALLER_TRACKS_DIRTY_DATA flag is commonly used in cases where a file system is managing a log file that is written to but not read from. Because the existing file data will be overwritten and not read, the cache manager may return pages of zeros instead of faulting in the actual pages of file data from disk. If this flag is set, the cache manager does not keep track of dirty pages. The caller is responsible for keeping track of any dirty pages. Note that **CcPreparePinWrite** should only be used to pin data in this manner if the buffer will eventually be flushed to disk. Before calling [CcFlushCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccflushcache) to flush the buffer to disk, the caller must first call [MmSetAddressRangeModified](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-mmsetaddressrangemodified) to notify the memory manager that the specified pages in the system cache buffer are dirty and should be written.

Every successful call to **CcPreparePinWrite** must be matched by a subsequent call to [CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata). If **CcPreparePinWrite** is called multiple times for the same data, **CcUnpinData** must be called the same number of times.

The pointer returned in *Buffer* is valid until [CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata) is called. If [CcPinMappedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinmappeddata) is called while this pointer is still valid, the pointer remains valid after the call to **CcPinMappedData** (but only until **CcUnpinData** is called).

**CcPreparePinWrite** cannot pin data across view boundaries in the cache manager. The cache manager manages files in the system in 256 KB-aligned views. (The cache manager's view size is specified by the system-defined constant VACB_MAPPING_GRANULARITY, which is set to 256 KB in ntifs.h.) Pinned regions cannot span more than one 256 KB view. Therefore, the largest region that can be pinned is 256 KB, beginning at a 256 KB-aligned offset in the file.

Pinning a byte range in a cached file does not ensure that the pages remain resident in memory. As long as the pages are pinned, the byte range is guaranteed to stay mapped into the system cache virtual address space, but the memory manager can page out the physical pages as the system's memory demand requires.

It is not necessary to call [CcSetDirtyPinnedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetdirtypinneddata) after calling **CcPreparePinWrite**. If **CcPreparePinWrite** returns **TRUE**, the BCB is already marked as dirty.

If any failure occurs, **CcPreparePinWrite** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcPreparePinWrite** raises a STATUS_INSUFFICIENT_RESOURCES exception; if an I/O error occurs, **CcPreparePinWrite** raises the status exception of the I/O error. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcPreparePinWrite** in a **try-except** or **try-finally** statement.

## See also

[CcFlushCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccflushcache)

[CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata)

[CcPinMappedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinmappeddata)

[CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread)

[CcSetDirtyPinnedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetdirtypinneddata)

[CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata)

[MmSetAddressRangeModified](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-mmsetaddressrangemodified)