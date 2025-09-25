# SysReleaseString function

## Description

**Note** You should only call **SysReleaseString** if you are implementing a scripting engine that needs to guard against running potentially malicious scripts.

Decreases the pinning reference count for the specified string by one. When that count reaches 0, the memory for that string is no longer prevented from being freed.

## Parameters

### `bstrString` [in]

The string for which the pinning reference count should decrease.

## Remarks

A call to the **SysReleaseString** function should match every previous call to the [SysAddRefString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysaddrefstring) function.

## See also

[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)

[SysAddRefString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysaddrefstring)