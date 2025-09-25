# IDedupReadFileCallback::OrderContainersRestore

## Description

This method provides the application with the ability to influence the order of the pending reads that
are required to retrieve the target file.

Given a list of container files that hold data for the
restore target file, generates a list of container file extents in a sorted order that results in an efficient
cross-container read plan from the backup store.

Implementation of this method by the application is
optional.

## Parameters

### `NumberOfContainers` [in]

Number of container paths in the *ContainerPaths* array.

### `ContainerPaths` [in]

Array of paths to container files that must be read in order to restore the file specified in the
[IDedupBackupSupport::RestoreFiles](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nf-ddpbackup-idedupbackupsupport-restorefiles)
call. Each element is a full path from the root directory of the volume to a container file.

### `ReadPlanEntries` [out]

Pointer to a ULONG variable that receives the number of
[DEDUP_CONTAINER_EXTENT](https://learn.microsoft.com/windows/desktop/api/ddpbackup/ns-ddpbackup-dedup_container_extent) structures in the array
that the *ReadPlan* parameter points to.

### `ReadPlan` [out]

Pointer to a buffer that receives an array of
[DEDUP_CONTAINER_EXTENT](https://learn.microsoft.com/windows/desktop/api/ddpbackup/ns-ddpbackup-dedup_container_extent) structures.

## Return value

This method can return standard **HRESULT** values, such as
**S_OK**. It can also return converted
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the
[HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Possible return values
include the following.

## Remarks

Given a list of container files that hold data for the restore target file, the application optionally
generates a list of container store file extents in a sorted order that results in an efficient cross-container
read plan. For a backup store located on tape, this would normally be in tape order.

In the case where a container is stored in multiple extents in the backup store—for
example, as a result of an incremental backup sequence—the application may also return
multiple container extents for each logical container file.

The application may return
**S_OK** and **NULL** output parameters to skip the read plan
optimizations. In this case, container read order will be chosen by Data Deduplication.

## See also

[DEDUP_CONTAINER_EXTENT](https://learn.microsoft.com/windows/desktop/api/ddpbackup/ns-ddpbackup-dedup_container_extent)

[IDedupReadFileCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nn-ddpbackup-idedupreadfilecallback)