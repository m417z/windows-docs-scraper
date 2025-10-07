# FreeRootCauseInfos function

The **FreeRootCauseInfos** function deallocates the memory allocated internally to an array of [**RootCauseInfo**](https://learn.microsoft.com/windows/win32/api/ndattrib/ns-ndattrib-rootcauseinfo) structures. This function calls [**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to deallocate memory.

## Parameters

*pInfo* \[in\]

Type: **[**RootCauseInfo**](https://learn.microsoft.com/windows/win32/api/ndattrib/ns-ndattrib-rootcauseinfo)\***

The array of structures. The allocated memory pointed to by these structures will be freed.

*RootCauseCount*

Type: **ULONG**

The number of structures in the array pointed to by *pInfo*.

*bFreePointer*

Type: **BOOL**

True if the array of structures should also be deleted; otherwise, false.

## Return value

This function does not return a value.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Ndattributils.h |

## See also

[**RootCauseInfo**](https://learn.microsoft.com/windows/win32/api/ndattrib/ns-ndattrib-rootcauseinfo)

[**CoTaskMemFree**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

