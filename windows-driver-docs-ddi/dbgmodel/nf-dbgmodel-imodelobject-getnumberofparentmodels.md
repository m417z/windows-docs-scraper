# IModelObject::GetNumberOfParentModels

## Description

The GetNumberOfParentModels method returns the number of parent models which are attached to the given object instance. Parent models are searched for properties depth-first in the linear ordering of the parent model chain.

## Parameters

### `numModels`

The number of parent models of the given object is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get an object */

ULONG64 numModels;
if (SUCCEEDED(spObject->GetNumberOfParentModels(&numModels)))
{
    // numModels contains the number of immediate parent models (does not include
    // grand-parents and further generations up).  If a key is queried on spObject and
    // that instance does not have it, the query will be passed in turn to each of the
    // 'numModels' models which are attached to spObject.
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)