# MrmFreeMemory function

Frees memory allocated by [**MrmCreateConfigInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateconfiginmemory), [**MrmCreateResourceFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefileinmemory),
[**MrmDumpPriFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifileinmemory), and [**MrmDumpPriDataInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmdumppridatainmemory).

To free the indexer handle, use [**MrmDestroyIndexerAndMessages**](https://learn.microsoft.com/windows/win32/menurc/mrmdestroyindexerandmessages).

## Parameters

*data* \[in\]

Type: **BYTE\***

A pointer to memory allocated and returned by [**MrmCreateConfigInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateconfiginmemory), [**MrmCreateResourceFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefileinmemory), [**MrmDumpPriFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifileinmemory), or [**MrmDumpPriDataInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmdumppridatainmemory).

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

[**MrmDestroyIndexerAndMessages**](https://learn.microsoft.com/windows/win32/menurc/mrmdestroyindexerandmessages)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)