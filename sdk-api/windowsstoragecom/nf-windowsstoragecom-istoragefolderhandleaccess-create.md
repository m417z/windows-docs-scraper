# IStorageFolderHandleAccess::Create

## Description

Creates a handle to a file that is in a storage folder.

## Parameters

### `fileName` [in]

The name of the file that you want to get a handle to.

### `creationOptions` [in]

The action to take on a file that exists or doesn't exist.

### `accessOptions` [in]

The level of access that a handle has on the file.

### `sharingOptions` [in]

The requested sharing mode of the handle.

### `options` [in]

The flags of the file handle.

### `oplockBreakingHandler` [in, optional]

Not currently implemented.

### `interopHandle` [out, retval]

The handle to the file.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IStorageFolderHandleAccess](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nn-windowsstoragecom-istoragefolderhandleaccess)