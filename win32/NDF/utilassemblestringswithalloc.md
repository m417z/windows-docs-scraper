# UtilAssembleStringsWithAlloc function

The **UtilAssembleStringsWithAlloc** function allocates a string and formats it using strings provided by the string table. This function uses [**StringCchPrintf**](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa) to create the formatted string.

## Parameters

*Buffer* \[out\]

Type: **LPWSTR\***

The location where the newly allocated string will be placed. When the string is no longer needed, it must be released with [**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

*BufferMax* \[in\]

Type: **UINT**

The maximum number of characters allowed in the string allocated by *Buffer*. If the resulting formatted string is longer than the number of characters specified, it is truncated and null-terminated.

> [!Note]
> This parameter may not be set to zero.

*InputFormat* \[in\]

Type: **LPCWSTR**

String resource out of the string table representing a format parameter passed to [**StringCchPrintf**](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa). It is constructed using [**MAKEINTRESOURCE**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea).

The resource string format must specify either a format parameter taking a wide string, or a format parameter taking an unsigned long and a wide string.

*InputString* \[in\]

Type: **LPCWSTR**

String resource out of the string table representing an argument passed to [**StringCchPrintf**](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa) in place of the wide string in the format parameter. It is constructed using [**MAKEINTRESOURCE**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea).

*AdditionalArgument* \[in\]

Type: **BOOLEAN**

True if *AdditionalValue* should be passed in as the first formatting argument to [**StringCchPrintf**](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa); otherwise, false (and only the resource string identified by *InputString* will be passed).

*AdditionalValue* \[in\]

Type: **ULONG**

The value to pass as the first formatting argument to [**StringCchPrintf**](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa) if *AdditionalArgument* is true.

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

[**UtilLoadStringWithAlloc**](https://learn.microsoft.com/windows/win32/ndf/utilloadstringwithalloc)

[**StringCchPrintf**](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa)

[**MAKEINTRESOURCE**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

[**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

