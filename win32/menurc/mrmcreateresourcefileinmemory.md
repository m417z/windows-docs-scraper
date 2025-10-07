# MrmCreateResourceFileInMemory function

Creates PRI file in memory, not as a file on disk. This is the last stage of creating a PRI file, after creating the indexer and adding resources.

This function can only create a single PRI file; if you want to create split PRI files
you must use the [**MrmCreateResourceFile** function](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefile).

## Parameters

*indexer* \[in\]

Type: **[**MrmResourceIndexerHandle**](https://learn.microsoft.com/windows/win32/menurc/mrmresourceindexerhandle)**

A handle identifying the resource indexer from which to create the PRI file. This handle is returned via a call to
[**MrmCreateResourceIndexer**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexer) or one of the related **MrmCreateResourceIndexer...*** functions.

*packagingMode* \[in\]

Type: **[**MrmPackagingMode**](https://learn.microsoft.com/windows/win32/menurc/mrmpackagingmode)**

Specifies what kind of PRI file the function should create. You cannot use **MrmPackagingModeAutoSplit** with this
function. See the documentation for [**MrmPackagingMode**](https://learn.microsoft.com/windows/win32/menurc/mrmpackagingmode) and the **Remarks** section of
[**MrmCreateResourceFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefile) for more info.

*packagingOptions* \[in\]

Type: **[**MrmPackagingOptions**](https://learn.microsoft.com/windows/win32/menurc/mrmpackagingoptions)**

Specifies additional options about the PRI file. Most callers should specify **MrmPackagingOptionsNone**. See the documentation for
[**MrmPackagingOptions**](https://learn.microsoft.com/windows/win32/menurc/mrmpackagingoptions) for more info.

*outputPriData* \[out\]

Type: **BYTE\*\***

The address of a **BYTE** pointer. On successful return, contains a pointer to the buffer allocated by
the function that contains the generated PRI file.
You must free the memory by calling [**MrmFreeMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmfreememory) when you are done with it.

*outputPriSize* \[out\]

Type: **ULONG\***

The address of a **ULONG**. On successful return, contains the size of the allocated memory buffer pointed to by
*outputPriData*.

## Return value

Type: **HRESULT**

S\_OK if the function succeeded, otherwise some other value. Use the **SUCCEEDED** or **FAILED** macros
(defined in winerror.h) to determine success or failure.

## Remarks

If you intend to pass *outputPriData* to [**MrmCreateResourceIndexerFromPreviousPriData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviouspridata-), don't free the memory until after you've finished using the
resource indexer.

For more information about the **packagingMode** parameter, see the **Remarks** section of
[**MrmCreateResourceFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefile). In particular, if you intend to save the data to a file
yourself, be sure to follow the correct naming conventions.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |
| Library<br> | Mrmsupport.lib |
| DLL<br> | Mrmsupport.dll |

## See also

[**MrmCreateResourceFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefile)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)

