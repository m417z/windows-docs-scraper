# MrmIndexFile function

Adds a file resource to a Resource Indexer. Note that it is the resource name that is indexed, not the file.
In other words, this function does not search the filename (or file contents) looking for things to index.

See [File resources in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmfiles) for more info.

## Parameters

*indexer* \[in\]

Type: **[**MrmResourceIndexerHandle**](https://learn.microsoft.com/windows/win32/menurc/mrmresourceindexerhandle)**

A handle identifying the resource indexer to add the resource to. This handle is returned via a call to
[**MrmCreateResourceIndexer**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexer) or one of the related **MrmCreateResourceIndexer...*** functions.

*resourceUri* \[in\]

Type: **PCWSTR**

The URI (name) to assign to the resource. By convention, file resources are added to the `files/` path (for example,
`ms-resource:///files/logo.png`). See [Resource names in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmresourcenames) for more info.

*filePath* \[in\]

Type: **PCWSTR**

The file path to be added to the index. Typically, this should be a relative path to a file as it will exist
after your app is intalled.

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

The provided *filePath* is added directly to the indexer without any parsing. The file does not need to exist,
and no checks are performed to see if it contains illegal path characters. The *resourceUri* is entirely unrelated
to the file path, for example a file may have a *resourceUri* of `/files/logo.png` but a *filePath* of
"Assets\\Logos\\2x\\logo.png". Since the *filePath* is just a string, it can also contain absolute paths or
parent-paths (those including "..\") although such files may not exist at runtime.

Note that files added with **MrmIndexFile** do not get qualifiers automatically added based on the filename - any
qualifiers must be explicitly added with the *qualifers* parameter. To automatically deduce qualifiers based
on the filename (as is performed by Visual Studio and the **MakePri** tool), use
[**MrmIndexFileAutoQualifiers**](https://learn.microsoft.com/windows/win32/menurc/mrmindexfileautoqualifiers).

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |
| Library<br> | Mrmsupport.lib |
| DLL<br> | Mrmsupport.dll |

## See also

[**MrmIndexEmbeddedData**](https://learn.microsoft.com/windows/win32/menurc/mrmindexembeddeddata) [**MrmIndexFileAutoQualifiers**](https://learn.microsoft.com/windows/win32/menurc/mrmindexfileautoqualifiers) [**MrmIndexResourceContainerAutoQualifiers**](https://learn.microsoft.com/windows/win32/menurc/mrmindexresourcecontainerautoqualifiers) [**MrmIndexString**](https://learn.microsoft.com/windows/win32/menurc/mrmindexstring) [File resources in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmfiles) [Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)