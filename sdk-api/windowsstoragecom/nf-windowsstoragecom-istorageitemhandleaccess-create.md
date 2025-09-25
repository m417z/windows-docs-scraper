# IStorageItemHandleAccess::Create

## Description

Creates a handle to a file.

## Parameters

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

[IStorageItemHandleAccess](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nn-windowsstoragecom-istorageitemhandleaccess)