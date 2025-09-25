# IModelObject::GetParentModel

## Description

The GetParentModel method returns the i-th parent model in the parent model chain of the given object. Parent models are searched for a property or concept in the linear order they are added or enumerated. The parent model with index i of zero is searched (hierarchically) before the parent model with index i + 1.

## Parameters

### `i`

A linear zero based index indicating which parent model in the chain to retrieve.

### `model`

An [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) representing the i-th parent model will be returned here.

### `contextObject`

If the parent model has an associated context adjustor, the adjusted context will be returned here. See the documentation for AddParentModel for more information about this value.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get an object */

ULONG64 numModels;
if (SUCCEEDED(spObject->GetNumberOfParentModels(&numModels)))
{
    // Enumerate the set of parents in linear resolution order:
    for (ULONG64 i = 0; i < numModels; ++i)
    {
        ComPtr<IModelObject> spParent;
        ComPtr<IModelObject> spContextAdjustor;
        if (SUCCEEDED(spObject->GetParentModel(i, &spParent, &spContextAdjustor)))
        {
            // spParent contains the i-th parent model
            // spContext optionally contains a context adjustor.  Properties above
            //     this in the tree will use this context instead of spObject.
            //     Conceptually, this is a *this* pointer thunk/adjustor.  The
            //     adjustor can be a property which must be fetched instead of a static value.
        }
    }
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)