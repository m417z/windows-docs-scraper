# SysAddRefString function

## Description

**Note** You should only call **SysAddRefString** if you are implementing a scripting engine that needs to guard against running potentially malicious scripts.

Increases the pinning reference count for the specified string by one.

## Parameters

### `bstrString` [in]

The string for which the pinning reference count should increase. While that count remains greater than 0, the memory for the string is prevented from being freed by calls to the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Strings with the **BSTR** data type have not traditionally had a reference count. All existing usage of these strings will continue to work with no changes. The **SysAddRefString** and [SysReleaseString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysreleasestring) functions add the ability to use reference counting to pin the string into memory before calling from an untrusted script into an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) method that may not expect the script to free that memory before the method returns, so that the script cannot force the code for that method into accessing memory that has been freed. After such a method safely returns, the pinning references should be released by calling **SysReleaseString**.

## See also

[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)

[SysReleaseString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysreleasestring)