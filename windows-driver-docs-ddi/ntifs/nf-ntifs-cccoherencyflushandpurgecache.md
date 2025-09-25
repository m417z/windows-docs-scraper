# CcCoherencyFlushAndPurgeCache function

## Description

The **CcCoherencyFlushAndPurgeCache** routine flushes, or flushes and purges, the cache to ensure cache coherency.

## Parameters

### `SectionObjectPointer` [in]

A pointer to a [**SECTION_OBJECT_POINTERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_section_object_pointers) structure that contains the section object pointers of the file object.

### `FileOffset` [in, optional]

A pointer to a variable that specifies the starting byte offset to flush, or to flush and purge.

### `Length` [in]

The length in bytes of the data to flush, or to flush and purge, starting at **FileOffset**. This parameter is ignored if a **NULL** pointer is passed to **FileOffset**.

### `IoStatus` [out]

A pointer to a caller-allocated [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the operation.

### `Flags` [in, optional]

A bitmask of the following flags that specify how the operation is to be performed:

| Value | Meaning |
| ----- | ------- |
| CC_FLUSH_AND_PURGE_NO_PURGE | Flush, but do not purge the cache. This is useful for read coherency flushes. |
| CC_FLUSH_AND_PURGE_GATHER_DIRTY_BITS | Reserved for system use; do not use. |
| CC_FLUSH_AND_PURGE_WRITEABLE_VIEWS_NOTSEEN | The caller can set this flag when there are no mappings to the file outside of the cache manager, in order to skip the expensive operation of trimming [process working sets](https://learn.microsoft.com/windows/win32/memory/working-set). |

## Remarks

 Use **CcCoherencyFlushAndPurgeCache** when possible instead of an explicit flush and purge call sequence as it will invalidate user mapped views to prevent data corruption. **CcCoherencyFlushAndPurgeCache** ensures cache coherency; as such, there is no option to do a purge only via this function.

The file must be acquired exclusively before you call **CcCoherencyFlushAndPurgeCache**.

You can flush, or flush and purge, any byte range within a file by using the **FileOffset** and **Length** parameters. Or you can flush, or flush and purge, an entire file if you pass a **NULL** pointer to the **FileOffset** parameter.

A call to **CcCoherencyFlushAndPurgeCache** is a synchronous (blocking) operation, not an asynchronous (non-blocking) operation.

An **IoStatus->Status** value of STATUS_CACHE_PAGE_LOCKED indicates that page invalidation failed. Be aware that page invalidation can fail even if you pass CC_FLUSH_AND_PURGE_NO_PURGE in the **Flags** parameter. Note that STATUS_CACHE_PAGE_LOCKED is a *success* status (that is, testing it with the **NT_SUCCESS** macro would return TRUE).

## See also

[**CcFlushCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccflushcache)

[**CcPurgeCacheSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)