# CcPinMappedData function

## Description

The **CcPinMappedData** routine pins the specified byte range of a cached file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file in which a range of data is to be pinned.

### `FileOffset` [in]

Pointer to a variable that specifies the starting byte offset within the cached file where the desired data resides.

### `Length` [in]

Length in bytes of the data to be pinned.

### `Flags` [in]

Bitmask of flags specifying how the pinning operation is to be performed. ORed combination of one or more of the following values:

| Flag | Meaning |
| --- | --- |
| PIN_WAIT | The caller can be put into a wait state until the data has been pinned. |
| PIN_EXCLUSIVE | The buffer control block (BCB) is to be acquired exclusively. If this flag is set, PIN_WAIT must also be set. |
| PIN_NO_READ | Only pages that are already resident in memory are to be pinned. If this flag is set, PIN_WAIT must also be set. |
| PIN_IF_BCB | The data is to be pinned only if a BCB already exists. Otherwise, the pin fails and *Bcb* is set to **NULL**. |

### `Bcb` [in, out]

On the first call this returns a pointer to a buffer control block (BCB). This pointer must be supplied as input on all subsequent calls for this buffer.

## Return value

**CcPinMappedData** returns **TRUE** if the data for the cached file was pinned successfully, **FALSE** otherwise.

## Remarks

A successful return from **CcPinMappedData** guarantees that the data previously mapped in a call to [CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata) is pinned in the cache and data in the specified range can be safely modified. If the caller subsequently modifies the data pinned by **CcPinMappedData**, it must also call [CcSetDirtyPinnedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetdirtypinneddata) so that the modified data will eventually be written to disk.

**CcPinMappedData** cannot pin data across view boundaries in the cache manager. The cache manager manages files in the system in 256 KB-aligned views. (The cache manager's view size is specified by the system-defined constant **VACB_MAPPING_GRANULARITY**, which is set to 256 KB in *ntifs.h*.) Pinned regions cannot span more than one 256 KB view. Therefore, the largest region that can be pinned is 256 KB, beginning at a 256 KB-aligned offset in the file.

Pinning a byte range in a cached file does not ensure that the pages remain resident in memory. As long as the pages are pinned, the byte range is guaranteed to stay mapped into the system cache virtual address space, but the memory manager can page out the physical pages as the system's memory demand requires.

If any failure occurs, **CcPinMappedData** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcPinMappedData** raises a **STATUS_INSUFFICIENT_RESOURCES** exception; if an I/O error occurs, **CcPinMappedData** raises the status exception of the I/O error. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcPinMappedData** in a **try-except** or **try-finally** statement.

To map data for a cached file, use the [CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata) routine. To cache a file, use [CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

It is not necessary to call [CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata) after calling **CcPinMappedData** since the pin reference is matched to [CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata).

## See also

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata)

[CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread)

[CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite)

[CcSetDirtyPinnedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetdirtypinneddata)

[CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata)