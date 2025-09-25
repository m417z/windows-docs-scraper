# DestroyIndexedResults function

## Description

Frees the parameters that the [IndexFilePath](https://learn.microsoft.com/windows/desktop/api/resourceindexer/nf-resourceindexer-indexfilepath) method returned.

## Parameters

### `resourceUri` [in, optional]

A uniform resource indicator (URI) that uses the ms-resource URI scheme and represents the named resource for the candidate, where the authority of the URI or the resource map is empty. For example, ms-resource:///Resources/String1 or ms-resource:///Files/images/logo.png.

### `qualifierCount` [in]

The number of indexed resource qualifiers that the list in the *ppQualifiers* parameter contains.

### `qualifiers` [in, optional]

A list of indexed resource qualifiers that declare the context under which the resources are appropriate.

## See also

[IndexFilePath](https://learn.microsoft.com/windows/desktop/api/resourceindexer/nf-resourceindexer-indexfilepath)

[IndexedResourceQualifier](https://learn.microsoft.com/windows/desktop/api/resourceindexer/ns-resourceindexer-indexedresourcequalifier)