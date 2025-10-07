# srpInheritOriginClaim function

\[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.\]

This function takes the origin attribute if present from the origin token and sets them on a duplicate of the inheriting token, and returns the duplicate token. The caller can then impersonate the returned token. This function has no associated import library. You must use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to srpapi.dll.

## Parameters

*OriginToken* \[in\]

Handle to the token which is duplicated and receives the inherited origin attribute. This handle must be opened with the TOKEN\_DUPLICATE access right.

*InheritingToken* \[in\]

Handle to the token which is duplicated and receives the inherited origin attribute. This handle must be opened with the TOKEN\_DUPLICATE access right.

*ResultToken*

On success, receives the duplicated token. The caller can impersonate it to perform operations with the inherited origin attribute. The caller takes ownership of this handle and must close it.

## Return value

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| DLL<br> | Srpapi.dll |

