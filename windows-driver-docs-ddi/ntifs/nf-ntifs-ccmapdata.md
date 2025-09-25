# CcMapData function

## Description

The **CcMapData** routine maps a specified byte range of a cached file to a buffer in memory.

## Parameters

### `FileObject` [in]

Pointer to a file object for the file whose data is to be mapped for read access.

### `FileOffset` [in]

Pointer to a variable that specifies the starting byte offset within the cached file where the desired data resides.

### `Length` [in]

Length of desired data in bytes.

### `Flags` [in]

Bitmask of flags specifying how the mapping operation is to be performed. This is a bitwise OR combination of one or more of the following values:

| Value | Meaning |
| --- | --- |
| MAP_WAIT | The caller can be put into a wait state until the data has been mapped. |
| MAP_NO_READ | Only pages that are already resident in memory are to be mapped. |

**Note** In Windows 2000and earlier, this parameter was a BOOLEAN value named *Wait*:

#### Wait

Set to **TRUE** if the caller can be put into a wait state until the data has been mapped, **FALSE** otherwise.

### `Bcb` [out]

On the first call this returns a pointer to a buffer control block (BCB) structure. This pointer must be supplied as input on all subsequent calls, for this buffer.

### `Buffer` [out]

Pointer to a buffer containing the mapped data.

## Return value

**CcMapData** returns **TRUE** if the data for the cached file was mapped successfully, **FALSE** otherwise.

## Remarks

**CcMapData** maps data in a cached file for read access. Note that after **CcMapData** is called, the data is mapped; but it is not pinned. This distinction is important. Data that is mapped but not pinned cannot safely be modified. To pin the data, use [CcPinMappedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinmappeddata), [CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread), or [CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite).

Every successful call to **CcMapData** must be matched by a subsequent call to [CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata).

**CcMapData** cannot map data across view boundaries in the cache manager. The cache manager manages files in the system in 256 KB-aligned views. (The cache manager's view size is specified by the system-defined constant **VACB_MAPPING_GRANULARITY**, which is set to 256 KB in *ntifs.h*.) Mapped regions cannot span more than one 256 KB view. Therefore, the largest region that can be mapped is 256 KB, beginning at a 256 KB-aligned offset in the file.

Mapping a byte range in a cached file does not ensure that the pages remain resident in memory. As long as the pages are mapped, the byte range is guaranteed to stay mapped into the system cache virtual address space, but the memory manager can page out the physical pages as the system's memory demand requires.

If the **MAP_WAIT** flag is set (or *Wait* is **TRUE**), **CcMapData** is guaranteed to complete the mapping request and return **TRUE**. If the required pages of the cached file are already resident in memory, the data is mapped immediately and no blocking will occur. If any needed pages are not resident, the caller is put in a wait state until all required pages have been made resident and the data can be mapped. If the **MAP_WAIT** flag is not set (or *Wait* is **FALSE**) and the data cannot be mapped immediately, **CcMapData** returns **FALSE**.

The pointer returned in *Buffer* is valid until [CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata) is called. If [CcPinMappedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinmappeddata) is called while this pointer is still valid, the pointer remains valid after the call to **CcPinMappedData** (but only until **CcUnpinData** is called).

If any failure occurs, **CcMapData** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcMapData** raises a **STATUS_INSUFFICIENT_RESOURCES** exception; if an I/O error occurs, **CcMapData** raises the status exception of the I/O error. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcMapData** in a **try-except** or **try-finally** statement.

To cache a file, use [CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

## See also

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[CcPinMappedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinmappeddata)

[CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread)

[CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite)

[CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata)