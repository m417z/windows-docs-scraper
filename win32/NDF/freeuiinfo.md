# FreeUiInfo function

The **FreeUiInfo** function deallocates the memory allocated internally to a [**UiInfo**](https://learn.microsoft.com/windows/win32/api/ndattrib/ns-ndattrib-uiinfo) structure. This function calls [**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to deallocate memory.

## Parameters

*pInfo* \[in\]

Type: **[**UiInfo**](https://learn.microsoft.com/windows/win32/api/ndattrib/ns-ndattrib-uiinfo)\***

The structure. The allocated memory pointed to by this structure will be freed.

## Return value

This function does not return a value.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Ndattributils.h |

## See also

[**UiInfo**](https://learn.microsoft.com/windows/win32/api/ndattrib/ns-ndattrib-uiinfo)

[**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

