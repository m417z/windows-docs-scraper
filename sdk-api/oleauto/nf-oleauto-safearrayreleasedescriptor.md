# SafeArrayReleaseDescriptor function

## Description

**Note** You should only call **SafeArrayReleaseDescriptor** if you are implementing a scripting engine that needs to guard against running potentially malicious scripts.

Decreases the pinning reference count for the descriptor of the specified safe array by one. When that count reaches 0, the memory for that descriptor is no longer prevented from being freed.

## Parameters

### `psa` [in]

The safe array for which the pinning reference count of the descriptor should decrease.

## Remarks

A call to the **SafeArrayReleaseDescriptor** function should match every previous call to the [SafeArrayAddRef](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayaddref) function.

## See also

[SafeArrayAddRef](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayaddref)

[SafeArrayReleaseData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayreleasedata)