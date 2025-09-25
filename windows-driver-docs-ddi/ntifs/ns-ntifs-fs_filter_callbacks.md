## Description

The FS_FILTER_CALLBACKS structure contains the entry points of caller-supplied notification callback routines.

## Members

### `SizeOfFsFilterCallbacks`

Size of this structure, in bytes. Set to ```sizeof(FS_FILTER_CALLBACKS)```. **SizeOfFsFilterCallbacks** must not be set to zero.

### `Reserved`

Reserved. Do not use.

### `PreAcquireForSectionSynchronization`

Pointer to a FS_FILTER_CALLBACK *PreAcquireForSectionSynchronization* routine.

### `PostAcquireForSectionSynchronization`

Pointer to a FS_FILTER_CALLBACK *PostAcquireForSectionSynchronization* routine.

### `PreReleaseForSectionSynchronization`

Pointer to a FS_FILTER_CALLBACK *PreReleaseForSectionSynchronization* routine.

### `PostReleaseForSectionSynchronization`

Pointer to a FS_FILTER_CALLBACK *PostReleaseForSectionSynchronization* routine.

### `PreAcquireForCcFlush`

Pointer to a FS_FILTER_CALLBACK *PreAcquireForCcFlush* routine.

### `PostAcquireForCcFlush`

Pointer to a FS_FILTER_CALLBACK *PostAcquireForCcFlush* routine.

### `PreReleaseForCcFlush`

Pointer to a FS_FILTER_CALLBACK *PreReleaseForCcFlush* routine.

### `PostReleaseForCcFlush`

Pointer to a FS_FILTER_CALLBACK *PostReleaseForCcFlush* routine.

### `PreAcquireForModifiedPageWriter`

Pointer to a FS_FILTER_CALLBACK *PreAcquireForModifiedPageWriter* routine.

### `PostAcquireForModifiedPageWriter`

Pointer to a FS_FILTER_CALLBACK *PostAcquireForModifiedPageWriter* routine.

### `PreReleaseForModifiedPageWriter`

Pointer to a FS_FILTER_CALLBACK *PreReleaseForModifiedPageWriter* routine.

### `PostReleaseForModifiedPageWriter`

Pointer to a FS_FILTER_CALLBACK *PostReleaseForModifiedPageWriter* routine.

### `PreQueryOpen`

Pointer to a FS_FILTER_CALLBACK *PreQueryOpen* routine.

### `PostQueryOpen`

Pointer to a FS_FILTER_CALLBACK *PostQueryOpen* routine.

## Remarks

File system filter drivers and file systems call the [**FsRtlRegisterFileSystemFilterCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlregisterfilesystemfiltercallbacks) routine to register notification callback routines to be invoked when the underlying file system performs certain operations.

All of the callback entry points are optional and can be **NULL**.

The FS_FILTER_CALLBACK filter callback routine and its parameters are defined as follows:

```cpp

typedef
NTSTATUS (*PFS_FILTER_CALLBACK) (
    IN PFS_FILTER_CALLBACK_DATA Data,
    OUT PVOID *CompletionContext
);

```

| Parameter | Meaning |
| --------- | ------- |
| *Data* | Pointer to the [**FS_FILTER_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_filter_callback_data) structure for this operation. |
| *CompletionContext* | Context information to be passed to the filter completion callback routine. Set to **NULL** if no context information is to be passed or if there is no corresponding filter completion callback routine. |

The FS_FILTER_COMPLETION_CALLBACK filter completion callback routine and its parameters are defined as follows:

```cpp

typedef
VOID (*PFS_FILTER_COMPLETION_CALLBACK) (
    IN PFS_FILTER_CALLBACK_DATA Data,
    IN NTSTATUS OperationStatus,
    IN PVOID CompletionContext
);

```

| Parameter | Meaning |
| --------- | ------- |
| *Data* | Pointer to the [**FS_FILTER_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_filter_callback_data) structure for this operation. |
| *OperationStatus* | Status of the operation. If the file system successfully performed the operation, this parameter is set to STATUS_SUCCESS. Otherwise, it is set to an appropriate error status value. |
| *CompletionContext* | Context information that was set in the filter callback routine. This is set to **NULL** if no information is passed or if there is no corresponding filter callback routine. |

Callback routines are defined for the following operations:

| Operation | Notification callback routines |
| ---- | ---- |
| The memory manager acquires a file exclusively before creating a memory-mapped section for a portion of the file. For this operation, **SyncType** is set to **SyncTypeCreateSection**. | PreAcquireForSectionSynchronization, PostAcquireForSectionSynchronization |
| The memory manager releases a file after creating a memory-mapped section for a portion of the file. | PreReleaseForSectionSynchronization, PostReleaseForSectionSynchronization |
| A kernel component (such as the cache manager) acquires a file exclusively before temporarily disabling section creation for a portion of the file. For this operation, **SyncType** is set to SyncTypeOther. | PreAcquireForSectionSynchronization, PostAcquireForSectionSynchronization. PreAcquireForSectionSynchronization should always return a success status code (such as STATUS_SUCCESS) for this operation. |
| A kernel component (such as the cache manager) releases a file after temporarily disabling section creation for a portion of the file. | PreReleaseForSectionSynchronization, PostReleaseForSectionSynchronization |
| The cache manager acquires a file exclusively before flushing a portion of the file from the cache. | PreAcquireForCcFlush, PostAcquireForCcFlush |
| The cache manager releases a file after flushing a portion of the file from the cache. | PreReleaseForCcFlush, PostReleaseForCcFlush |
| The modified page writer acquires a file exclusively before writing a portion of the file to disk. | PreAcquireForModifiedPageWriter, PostAcquireForModifiedPageWriter |
| The modified page writer releases a file after writing a portion of the file to disk. | PreReleaseForModifiedPageWriter, PostReleaseForModifiedPageWriter |
| A component queries for file information by name without opening the file. Redirectors will never be called with this query, and thus do not need to implement PreQueryOpen or PostQueryOpen callbacks. | PreQueryOpen, PostQueryOpen |

The filter notification callback routine is invoked before the operation request is passed to lower-level filter drivers and the underlying file system. In the callback routine, the filter driver should perform any needed processing and immediately return STATUS_SUCCESS. If a filter driver's callback routine returns a status value other than STATUS_SUCCESS, this causes the operation request to fail. Repeated failure of certain requests, such as locking requests, can halt system progress. Thus, filter drivers should fail such a request only when absolutely necessary. When failing these requests, the filter driver should return an error status value that describes the error as completely and accurately as possible.

> [!NOTE]
>
> A filter driver's notification callback routine cannot fail a request to release a file system resource. If a filter driver returns a status value other than STATUS_SUCCESS from any of the following notification callback routines, the status value is ignored.
>
> * PreReleaseForSectionSynchronization
> * PreReleaseForCcFlush
> * PreReleaseForModifiedPageWriter

The filter completion callback routine is invoked after the operation request is passed to lower-level filter drivers and the underlying file system. In the completion callback routine, the filter driver must perform any needed processing and immediately return.

## See also

[**FS_FILTER_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_filter_callback_data)

[**FsRtlRegisterFileSystemFilterCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlregisterfilesystemfiltercallbacks)