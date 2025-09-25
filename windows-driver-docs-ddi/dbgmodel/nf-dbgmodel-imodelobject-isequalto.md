# IModelObject::IsEqualTo

## Description

The IsEqualTo method compares a host context to another host context. If the two contexts are equivalent, an indication of this is returned. Note that this comparison is not interface equivalence. This compares the underlying opaque contents of the context itself.

It is also important to note that this method checks for equivalence and not that one of the contexts is a subset or superset of the other.

## Parameters

### `other`

The host context to compare against.

### `equal`

An indication of whether the two contexts are equivalent is passed back here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IDebugHostContext> spContext1; /* get a context (e.g.:
                                         IDebugHost::GetCurrentContext) */
ComPtr<IDebugHostContext> spContext2; /* get another context (e.g.:
                                         IModelObject::GetContext) */

bool isEqual;
if (SUCCEEDED(spContext1->IsEqualTo(spContext2.Get(), &isEqual)) && isEqual)
{
    // The contexts are *IDENTICAL*
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)