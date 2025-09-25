# CcInitializeCacheMap function

## Description

File systems call the **CcInitializeCacheMap** routine to cache a file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the file.

### `FileSizes` [in]

Pointer to a CC_FILE_SIZES structure containing **AllocationSize**, **FileSize**, and **ValidDataLength** for the file. This structure is defined as follows:

```
typedef struct _CC_FILE_SIZES {
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER FileSize;
    LARGE_INTEGER ValidDataLength;
} CC_FILE_SIZES, *PCC_FILE_SIZES;
```

| Member | Meaning |
| --- | --- |
| **AllocationSize** | New section object size for the file. Ignored if less than or equal to the current section size. |
| **FileSize** | New file size for the file. |
| **ValidDataLength** | New valid data length for the file. |

### `PinAccess` [in]

Set to **TRUE** if **CcPin***Xxx* routines will be used on the file.

### `Callbacks` [in]

Pointer to a structure allocated from nonpaged pool, containing entry points of caller-supplied read-ahead and write-behind callback routines.This structure and its members are defined as follows:

```
typedef struct _CACHE_MANAGER_CALLBACKS {
    PACQUIRE_FOR_LAZY_WRITE AcquireForLazyWrite;
    PRELEASE_FROM_LAZY_WRITE ReleaseFromLazyWrite;
    PACQUIRE_FOR_READ_AHEAD AcquireForReadAhead;
    PRELEASE_FROM_READ_AHEAD ReleaseFromReadAhead;
} CACHE_MANAGER_CALLBACKS, *PCACHE_MANAGER_CALLBACKS;
typedef
BOOLEAN (*PACQUIRE_FOR_LAZY_WRITE) (
             IN PVOID Context,
             IN BOOLEAN Wait
             );
typedef
VOID (*PRELEASE_FROM_LAZY_WRITE) (
             IN PVOID Context
             );
typedef
BOOLEAN (*PACQUIRE_FOR_READ_AHEAD) (
             IN PVOID Context,
             IN BOOLEAN Wait
             );
typedef
VOID (*PRELEASE_FROM_READ_AHEAD) (
             IN PVOID Context
             );
```

### `LazyWriteContext` [in]

Pointer to context information to be passed to the callback routines specified in *Callbacks*.

## Remarks

**CcInitializeCacheMap** creates the data structures required for file data caching.

If any failure occurs, **CcInitializeCacheMap** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcInitializeCacheMap** raises a STATUS_INSUFFICIENT_RESOURCES exception. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcInitializeCacheMap** in a **try-except** or **try-finally** statement.

File systems must call **CcInitializeCacheMap** to cache a file before using any other cache manager routines on the file, unless the file was created with data caching disabled. In most file systems, file caching is enabled by default, but can be disabled by setting the FILE_NO_INTERMEDIATE_BUFFERING flag to **TRUE** in the file create options.

After calling **CcInitializeCacheMap**, the file system can call [CcSetAdditionalCacheAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetadditionalcacheattributes) to disable read-ahead or write-behind, if desired.

When closing a file, every file system that supports file caching must call [CcUninitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccuninitializecachemap) on that file, whether the file is cached or not. Even if the file was created with caching disabled, the file system still must call **CcUninitializeCacheMap**.

The **CcIsFileCached** macro determines whether a file is cached or not.

```cpp
BOOLEAN CcIsFileCached(
  [in] PFILE_OBJECT FileObject
);

```

Parameters

*FileObject[in]* [in]

Pointer to a file object for the file.

Return value

Returns **TRUE** if the file is cached, **FALSE** otherwise.

**Note** Because multiple file objects can refer to the same file (that is, data stream), it is possible for the **CcIsFileCached** macro to return **TRUE** given a non-cached file object if another cached file object refers to the same data stream. In other words, if there is a set of file objects that refer to the same data stream and if at least one of the file objects in the set is cached, **CcIsFileCached** will return **TRUE** for all file objects in the set.

## See also

[CcSetAdditionalCacheAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetadditionalcacheattributes)

[CcUninitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccuninitializecachemap)