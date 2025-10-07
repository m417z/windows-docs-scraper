# MrmIndexString function

Adds a string resource to a Resource Indexer. Note that it is the resource name that is indexed, not the string.
In other words, this function does not search the string looking for things to index.

## Parameters

*indexer* \[in\]

Type: **[**MrmResourceIndexerHandle**](https://learn.microsoft.com/windows/win32/menurc/mrmresourceindexerhandle)**

A handle identifying the resource indexer to add the resource to. This handle is returned via a call to
[**MrmCreateResourceIndexer**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexer) or one of the related **MrmCreateResourceIndexer...*** functions.

*resourceUri* \[in\]

Type: **PCWSTR**

The URI (name) to assign to the resource. By convention, string resources are added to the `strings/` path (for example,
`ms-resource:///strings/appName`). See [Resource names in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmresourcenames) for more info.

*resourceString* \[in\]

Type: **PCWSTR**

The string to add to the index.

*qualifiers* \[in, optional\]

Type: **PCWSTR**

An optional list of resource qualifiers for the resource, for example "language-en-US". Passing an empty
string or **NULL** indicates a neutral resource that is applicable in any resource context. See
[Qualifiers in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmqualifiers) for more info.

## Return value

Type: **HRESULT**

S\_OK if the function succeeded, otherwise some other value. Use the **SUCCEEDED** or **FAILED** macros (defined in winerror.h)
to determine success or failure.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |
| Library<br> | Mrmsupport.lib |
| DLL<br> | Mrmsupport.dll |

## See also

[**MrmIndexEmbeddedData**](https://learn.microsoft.com/windows/win32/menurc/mrmindexembeddeddata) [**MrmIndexFile**](https://learn.microsoft.com/windows/win32/menurc/mrmindexfile) [**MrmIndexFileAutoQualifiers**](https://learn.microsoft.com/windows/win32/menurc/mrmindexfileautoqualifiers) [**MrmIndexResourceContainerAutoQualifiers**](https://learn.microsoft.com/windows/win32/menurc/mrmindexresourcecontainerautoqualifiers) [File resources in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmfiles) [Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)