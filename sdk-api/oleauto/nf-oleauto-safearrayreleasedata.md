# SafeArrayReleaseData function

## Description

**Note** You should only call **SafeArrayReleaseData** if you are implementing a scripting engine that needs to guard against running potentially malicious scripts.

Decreases the pinning reference count for the specified safe array data by one. When that count reaches 0, the memory for that data is no longer prevented from being freed.

## Parameters

### `pData` [in]

The safe array data for which the pinning reference count should decrease.

## Remarks

A call to the **SafeArrayReleaseData** function should match every previous call to the [SafeArrayAddRef](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayaddref) function that returned a non-null value in the *ppDataToRelease* parameter.

## See also

[SafeArrayAddRef](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayaddref)

[SafeArrayReleaseDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayreleasedescriptor)