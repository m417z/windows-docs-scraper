# MrmDestroyIndexerAndMessages function

Releases resources associated with a resource indexer. Destroys the handle, frees the indexer, and deletes any messages
retrieved via **MrmPeekResourceIndexerMessages**.

Note this *does not* free memory allocated via functions such as **MrmCreateConfigInMemory** or
**MrmCreateResourceFileInMemory** that produce outputs; that memory must be freed by using **MrmFreeMemory**,
as outlined in the specific API topics.

## Parameters

*indexer* \[in\]

Type: **[**MrmResourceIndexerHandle**](https://learn.microsoft.com/windows/win32/menurc/mrmresourceindexerhandle)**

A handle identifying the resource indexer to destroy.

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

[**MrmFreeMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmfreememory)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)

