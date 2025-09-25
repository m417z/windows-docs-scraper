# IDedupReadFileCallback::PreviewContainerRead

## Description

Provides the application with a preview of the sequence of reads that are pending for a given container file extent.

## Parameters

### `FileFullPath` [in]

The full path from the root directory of the volume to the container file.

### `NumberOfReads` [in]

Number of [DDP_FILE_EXTENT](https://learn.microsoft.com/windows/desktop/api/ddpbackup/ns-ddpbackup-ddp_file_extent) structures in the array that the *ReadOffsets* parameter points to.

### `ReadOffsets` [in]

Pointer to an array of [DDP_FILE_EXTENT](https://learn.microsoft.com/windows/desktop/api/ddpbackup/ns-ddpbackup-ddp_file_extent) structures.

## Return value

This method can return standard **HRESULT** values, such as **S_OK**. It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Possible return values include the following.

## Remarks

**PreviewContainerRead** is called for each container file extent reported by [IDedupReadFileCallback::OrderContainersRestore](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nf-ddpbackup-idedupreadfilecallback-ordercontainersrestore). The application may use this preview as a per-container extent read plan to increase the efficiency of the pending reads. For example, the application may choose to perform read-ahead to improve throughput or to cache read buffers to improve overall performance across parallel file restore operations.

## See also

[DDP_FILE_EXTENT](https://learn.microsoft.com/windows/desktop/api/ddpbackup/ns-ddpbackup-ddp_file_extent)

[IDedupReadFileCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nn-ddpbackup-idedupreadfilecallback)