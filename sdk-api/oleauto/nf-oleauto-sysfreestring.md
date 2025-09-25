# SysFreeString function

## Description

Deallocates a string allocated previously by [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring), [SysAllocStringByteLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstringbytelen), [SysReAllocString](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-sysreallocstring), [SysAllocStringLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstringlen), or [SysReAllocStringLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysreallocstringlen).

## Parameters

### `bstrString` [in, optional]

The previously allocated string. If this parameter is **NULL**, the function simply returns.