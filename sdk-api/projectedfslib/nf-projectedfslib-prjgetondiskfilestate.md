# PrjGetOnDiskFileState function

## Description

Gets the on-disk file state for a file or directory.

## Parameters

### `destinationFileName` [in]

A null-terminated Unicode string specifying the full path to the file whose state is to be queried.

### `fileState` [out]

This is a combination of one or more PRJ_FILE_STATE values describing the file state.

## Return value

HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) indicates destinationFileName does not exist. HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND) indicates that an intermediate component of the path to destinationFileName does not exist.

## Remarks

This routine tells the caller what the ProjFS caching state is of the specified file or directory. For example, the caller can use this routine to determine whether the given item is a placeholder or full file.

A running provider should be cautious if using this routine on files or directories within one of its virtualization instances, as it may cause callbacks to be invoked in the provider. Depending on the design of the provider this may lead to deadlocks.