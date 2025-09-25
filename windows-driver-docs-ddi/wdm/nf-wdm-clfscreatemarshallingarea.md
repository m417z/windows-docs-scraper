## Description

The **ClfsCreateMarshallingArea** routine creates a marshalling area for a CLFS stream and returns a pointer to an opaque context that represents the new marshalling area.

## Parameters

### `plfoLog` [in]

A pointer to a [**LOG_FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents a CLFS stream. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

### `ePoolType` [in]

A [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type) value that specifies the type of memory (paged, non-paged, for example) that the new marshalling area will use for its log I/O blocks.

### `pfnAllocBuffer` [in, optional]

Either **NULL** or a pointer to a caller-supplied function that allocates a log I/O block for the marshalling area. The allocation function has the following prototype:

```cpp
PVOID
(*PALLOCATE_FUNCTION) (
    IN POOL_TYPE PoolType,
    IN SIZE_T NumberOfBytes,
    IN ULONG Tag
    );
```

The return value of the allocation function is a pointer to the newly allocated log I/O block.

### `pfnFreeBuffer` [in, optional]

Either **NULL** or a pointer to a caller-supplied function that frees a log I/O block that was previously allocated by *pfnAllocBuffer*. The function has the following prototype:

```cpp
VOID
(*PFREE_FUNCTION) (
    IN PVOID Buffer
    );
```

### `cbMarshallingBuffer` [in]

The size, in bytes, of the individual log I/O blocks that the new marshalling area uses. This must be a multiple of the sector size on the stable storage medium. The sector size is the *lpBytesPerSector* value returned from **GetDiskFreeSpace**.

### `cMaxWriteBuffers` [in]

The maximum number of I/O blocks that can be allocated at one time for write operations. This parameter affects the frequency of data flushes. If you do not need to control the frequency of data flushes, set this parameter to INFINITE.

### `cMaxReadBuffers` [in]

The maximum number of log I/O blocks that can be allocated at one time for read operations.

### `ppvMarshalContext` [out]

A pointer to a variable that receives a pointer to an opaque context that represents the new marshalling area.

## Return value

**ClfsCreateMarshallingArea** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

The *pfnAllocBuffer* and *pfnFreeBuffer* parameters must both point to caller-allocated functions, or they must both be **NULL**. If they are both **NULL**, CLFS provides default functions for allocating and freeing log I/O blocks.

Before calling **ClfsCreateMarshallingArea**, you must add at least two containers to the underlying log by calling [ClfsAddLogContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsaddlogcontainer) or [ClfsAddLogContainerSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsaddlogcontainerset).

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsAddLogContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsaddlogcontainer)

[ClfsAddLogContainerSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsaddlogcontainerset)

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)

[ClfsDeleteMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsdeletemarshallingarea)

[**LOG_FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)