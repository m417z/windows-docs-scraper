# IModelObject::RemoveParentModel

## Description

The RemoveParentModel will remove a specified parent model from the parent search chain of the given object.

## Parameters

### `model`

The parent model to remove from this object.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject;          /* get an object */
ComPtr<IModelObject> spDataModelObject; /* get an attached data model (from earlier add or from GetParentModel) */

if (SUCCEEDED(spObject->RemoveParentModel(spDataModelObject.Get())))
{
    // spObject no longer has the properties or concepts exposed by spDataModelObject
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)