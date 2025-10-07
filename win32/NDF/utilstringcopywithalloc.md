# UtilStringCopyWithAlloc function

The **UtilStringCopyWithAlloc** function allocates and copies a source string.

## Parameters

*Buffer* \[out\]

Type: **LPWSTR\***

The location where the pointer to the allocated memory is stored. When no longer needed, it must be released with [**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). This buffer is always null-terminated.

*BufferMax* \[in\]

Type: **UINT**

The maximum number of characters to read from *Source*.

*Source* \[in\]

Type: **LPCWSTR**

The string to be copied.

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

[**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

[**UtilAssembleStringsWithAlloc**](https://learn.microsoft.com/windows/win32/ndf/utilassemblestringswithalloc)

[**UtilLoadStringWithAlloc**](https://learn.microsoft.com/windows/win32/ndf/utilloadstringwithalloc)

