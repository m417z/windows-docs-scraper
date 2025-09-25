## Description

The UnregisterExtensionForTypeSignature method undoes a prior call to RegisterExtensionForTypeSignature. It unregisters a particular data model as an extension for either a particular type signature or as an extension for all type signatures against which the data model was registered.

## Parameters

### `dataModel`

The data model to unregister as an extension from one or more type signatures. If a specific type signature is passed in the typeSignature argument, this data model will be unregistered as an extension from that particular type signature. Newly created native/language objects with concrete types which match the signature will no longer have this data model automatically attached. If typeSignature is passed as nullptr, this data model will be unregistered from every type signature that it was registered against.

### `typeSignature`

The type signature from which dataModel should be unregistered as an extension. If this argument is nullptr, the data model given by the dataModel argument will be unregistered as an extension from every type signature it was registered against.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager3> spManager;             /* get the data model manager */
ComPtr<IDebugHostTypeSignature> spTypeSignature; /* get a type signature (see
                                                  RegisterExtensionForTypeSignature) */
ComPtr<IModelObject> spDataModelObject;          /* get a data model object (see
                                                    CreateDataModelObject) */

if (SUCCEEDED(spManager->UnregisterExtensionForTypeSignature(spDataModelObject.Get(),
                                                             spTypeSignature.Get())))
{
    // spDataModelObject is no longer registered as an extension for types
    // matching the signature.  Note that if the second argument were passed
    // as 'nullptr', spDataModelObject would no longer be registered as an
    // extension for *ANY* types.
}
```

## See also

[IDataModelManager3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager3)