# IFileBasedLogInit::InitNew

## Description

Create a new log instance on the specified file. If a file with that name already exists, it is overwritten.

## Parameters

### `filename` [in]

The absolute path of the file to be created.

### `cbCapacityHint` [in]

A hint to the implementation about the total capacity that will be needed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFileBasedLogInit](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ifilebasedloginit)