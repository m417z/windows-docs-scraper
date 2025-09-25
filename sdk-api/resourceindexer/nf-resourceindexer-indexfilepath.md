# IndexFilePath function

## Description

Indexes a file path for file and folder naming conventions.

## Parameters

### `resourceIndexer` [in]

The resource indexer object that you created by calling the [CreateResourceIndexer](https://learn.microsoft.com/windows/desktop/api/resourceindexer/nf-resourceindexer-createresourceindexer) function.

### `filePath` [in]

The path for the folder that you want to index. The path must be an absolute path with the drive letter specified. Long file paths are not supported.

### `ppResourceUri` [out]

A uniform resource indicator (URI) that uses the ms-resource URI scheme and represents the named resource for the candidate, where the authority of the URI or the resource map is empty. For example, ms-resource:///Resources/String1 or ms-resource:///Files/images/logo.png.

### `pQualifierCount` [out]

The number of indexed resource qualifiers that the list in the *ppQualifiers* parameter contains.

### `ppQualifiers` [out]

A list of indexed resource qualifiers that declare the context under which the resources are appropriate.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CreateResourceIndexer](https://learn.microsoft.com/windows/desktop/api/resourceindexer/nf-resourceindexer-createresourceindexer)

[IndexedResourceQualifier](https://learn.microsoft.com/windows/desktop/api/resourceindexer/ns-resourceindexer-indexedresourcequalifier)