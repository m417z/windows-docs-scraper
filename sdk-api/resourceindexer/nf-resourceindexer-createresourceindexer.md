# CreateResourceIndexer function

## Description

Creates a new resource indexer for the specified paths of the root of the project files and the extension DLL.

## Parameters

### `projectRoot` [in]

The path of the root folder to use for the project for the files to be produced, in string form. This path is used to determine file paths relative to the package that contains them. This path must be an absolute path with the drive letter specified. Long file paths are not supported.

### `extensionDllPath` [in, optional]

 The full path to an extension dynamic-link library (DLL) that is Microsoft-signed and implements the ext-ms-win-mrmcorer-environment-l1 API set. This path determines the file path from where the extension DLL for the modern resource technology (MRT) environment is loaded. This path must be an absolute path with the drive letter specified. Long file paths are not supported.

### `ppResourceIndexer` [out]

The newly created resource indexer.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DestroyResourceIndexer](https://learn.microsoft.com/windows/desktop/api/resourceindexer/nf-resourceindexer-destroyresourceindexer)