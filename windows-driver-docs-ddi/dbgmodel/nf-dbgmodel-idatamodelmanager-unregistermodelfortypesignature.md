# IDataModelManager::UnregisterModelForTypeSignature

## Description

The UnregisterModelForTypeSignature method undoes a prior call to the RegisterModelForTypeSignature method. This method can either remove a given data model as the canonical visualizer for types matching a particular type signature or it can remove a given data model as the canonical visualizer for every type signature under which that data model is registered.

## Parameters

### `dataModel`

The data model to be unregistered as the canonical visualizer for one or more type signatures. If the typeSignature argument is nullptr, this data model will be unregistered from all type signatures it was registered against; otherwise, it will only be unregistered against the particular type signature indicated.

### `typeSignature`

The type signature against which the data model given by the dataModel argument will be unregistered. This argument is optional and hence, nullptr can be passed. If nullptr is passed, the data model given by the dataModel argument will be unregistered from all type signatures it was registered against.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager> spManager;             /* get the data model manager */
ComPtr<IDebugHostTypeSignature> spTypeSignature; /* get a type signature (see
                                                    RegisterModelForTypeSignature) */
ComPtr<IModelObject> spDataModelObject;          /* get a data model object (see
                                                    CreateDataModelObject) */

if (SUCCEEDED(spManager->UnregisterModelForTypeSignature(spDataModelObject.Get(),
                                                         spTypeSignature.Get())))
{
    // spDataModelObject is no longer registered as the canonical visualizer
    // for types matching the signature.  Note that if the second argument were
    // passed as 'nullptr', spDataModelObject would no longer be registered
    // as the canonical visualizer for *ANY* types.
}
```

## See also

[IDataModelManager interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager)