# PrjDeleteFile function

## Description

Enables a provider to delete an item that has been cached on the local file system.

## Parameters

### `namespaceVirtualizationContext` [in]

An opaque handle for the virtualization instance.

### `destinationFileName` [in]

A null-terminated Unicode string specifying the path, relative to the virtualization root, to the file or directory to be deleted.

### `updateFlags` [in, optional]

Flags to control the delete operation should be allowed given the state of the file.

### `failureReason` [out, optional]

Optional pointer to receive a code describing the reason a delete failed.

## Return value

If an HRESULT_FROM_WIN32(ERROR_FILE_SYSTEM_VIRTUALIZATION_INVALID_OPERATION) error is returned, the update failed due to the item's state and the value of updateFlags. failureReason, if specified, will describe the reason for the failure.

## Remarks

If the item is still in the provider's backing store, deleting it from the local file system changes it to a virtual item.

This routine cannot be called on a virtual file/directory.

If the file/directory to be deleted is in any state other than "placeholder", the provider must specify an appropriate combination of [PRJ_UPDATE_TYPES](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ne-projectedfslib-prj_update_types) values in the updateFlags parameter. This helps guard against accidental loss of data.