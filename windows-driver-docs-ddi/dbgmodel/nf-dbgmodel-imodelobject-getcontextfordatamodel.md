# IModelObject::GetContextForDataModel

## Description

The GetContextForDataModel method is used to retrieve context information which was set up with a prior call to SetContextForDataModel. This retrieves state information which was set on an instance object by a data model further up in the instance object's parent model hierarchy.

For more details about this context/state and its meaning, see the documentation for [SetContextForDataModel](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-imodelobject-setcontextfordatamodel).

## Parameters

### `dataModelObject`

The [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) representing the data model for which state is being retrieved from an instance object. This is, in effect, a hash key to the associated state object.

### `context`

The state which was associated with the instance is returned here. The exact meaning of this (and any other interfaces, etc... it supports) is up to the data model that made the call to set the state.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject;          /* get an object */
ComPtr<IModelObject> spDataModelObject; /* get a data model object (from an earlier AddParentModel or from GetParentModel, etc...) */

ComPtr<IUnknown> spContext;
if (SUCCEEDED(spObject->GetContextForDataModel(spDataModelObject.Get(), &spContext)))
{
    // Whatever context was associated with spObject for spDataModelObject through a
    // prior call to SetContextForDataModel has been fetched.  You can static_cast
    // (in process) or query spContext for the information you need since it is
    // private implementation.
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)