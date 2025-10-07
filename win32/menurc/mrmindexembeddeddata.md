# MrmIndexEmbeddedData function

Adds an embeded data resource (BLOB) to a Resource Indexer. Note that it is the resource name that is
indexed, not the data. In other words, this function does not search the data looking for things to index.

Embedded data resources are more efficient than file resources, but are less useful during app development.
See [Files resources in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmfiles) for more info.

## Parameters

*indexer* \[in\]

Type: **[**MrmResourceIndexerHandle**](https://learn.microsoft.com/windows/win32/menurc/mrmresourceindexerhandle)**

A handle identifying the resource indexer to add the resource to. This handle is returned via a call to
[**MrmCreateResourceIndexer**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexer) or one of the related **MrmCreateResourceIndexer...*** functions.

*resourceUri* \[in\]

Type: **PCWSTR**

The URI (name) to assign to the resource. See [Resource names in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmresourcenames) for more info.

*embeddedData* \[in\]

Type: **const BYTE\***

A pointer to the data you want to add to the indexer.

*embeddedDataSize* \[in\]

Type: **ULONG**

The size of the data pointed to by *embeddedData*.

*qualifiers* \[in, optional\]

Type: **PCWSTR**

An optional list of resource qualifiers for the resource, for example "language-en-US". Passing an empty
string or **NULL** indicates a neutral resource that is applicable in any resource context. See
[Qualifiers in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmqualifiers) for more info.

## Return value

Type: **HRESULT**

S\_OK if the function succeeded, otherwise some other value. Use the **SUCCEEDED** or **FAILED** macros
(defined in winerror.h) to determine success or failure.

## Remarks

This function adds binary data (such as an image or audio file) directly to the indexer, so that it will
be embedded in the output PRI file. This is in contrast to file-based resources, which only adds the
filename to the PRI file and requires the file to be installed alongside the app.

See [Files in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmfiles) for more info on the pros and cons of using embedded data vs. file resources.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |
| Library<br> | Mrmsupport.lib |
| DLL<br> | Mrmsupport.dll |

## See also

[**MrmIndexFile**](https://learn.microsoft.com/windows/win32/menurc/mrmindexfile) [**MrmIndexFileAutoQualifiers**](https://learn.microsoft.com/windows/win32/menurc/mrmindexfileautoqualifiers) [**MrmIndexResourceContainerAutoQualifiers**](https://learn.microsoft.com/windows/win32/menurc/mrmindexresourcecontainerautoqualifiers) [**MrmIndexString**](https://learn.microsoft.com/windows/win32/menurc/mrmindexstring) [File resources in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmfiles) [Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)