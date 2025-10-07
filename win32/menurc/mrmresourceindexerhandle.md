# MrmResourceIndexerHandle structure

Represents a handle to a resource indexer object. Most MRM functions require an indexer handle, which can
be obtained via one of the **MrmCreateResourceIndexer...** functions.

## Members

**handle**

Type: **PVOID**

An opaque handle to a resource indexer object. Do not use this value directly.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |

## See also

[**MrmCreateResourceIndexer**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexer)

[**MrmCreateResourceIndexerFromPreviousPriData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviouspridata-)

[**MrmCreateResourceIndexerFromPreviousPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousprifile)

[**MrmCreateResourceIndexerFromPreviousSchemaData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemadata)

[**MrmCreateResourceIndexerFromPreviousSchemaFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemafile)

[**MrmDestroyIndexerAndMessages**](https://learn.microsoft.com/windows/win32/menurc/mrmresourceindexermessage)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)