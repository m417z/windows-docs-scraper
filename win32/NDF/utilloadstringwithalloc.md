# UtilLoadStringWithAlloc function

The **UtilLoadStringWithAlloc** function allocates and loads a string out of the resource table.

## Parameters

*uID* \[in\]

Type: **UINT**

Identifier of the string to be loaded.

*ppwzBuffer* \[out\]

Type: **LPWSTR\***

The location where the newly allocated string will be placed. The string must be freed using [**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when it is no longer needed.

*cchBufferMax* \[in\]

Type: **UINT**

The maximum number of characters to load from the resource table. If the resource string is longer than the number of characters specified, it is truncated and null-terminated.

> [!Note]
> This parameter may not be set to zero.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
|----------------------------------------------------------------------------------------------|--------------------------------------------------------------------|
| **S\_OK** | The operation succeeded.<br> |
| **E\_INVALIDARG** | One or more parameters has not been provided correctly.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Ndattributils.h |

## See also

[**UtilStringCopyWithAlloc**](https://learn.microsoft.com/windows/win32/ndf/utilstringcopywithalloc)

[**UtilAssembleStringsWithAlloc**](https://learn.microsoft.com/windows/win32/ndf/utilassemblestringswithalloc)

[**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

