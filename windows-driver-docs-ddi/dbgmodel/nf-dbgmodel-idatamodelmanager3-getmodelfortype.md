## Description

The GetModelForType method returns the data model which is the canonical visualizer for a given type instance. In effect, this method finds the best matching type signature which was registered with a prior call to the RegisterModelForTypeSignature method and returns the associated data model.

## Parameters

### `type`

The concrete type instance for which to find the best matching canonical visualizer registered via a prior call to the RegisterModelForTypeSignature method.

### `dataModel`

The data model which is the canonical visualizer for the given type instance as determined by the best matching type signature registered via a prior call to RegisterModelForTypeSignature will be returned here. This data model will automatically be attached to any native/language object created with the type specified by the type argument.

### `typeSignature`

The type signature whose match against type caused us to return the data model registered from a prior call to RegisterModelForTypeSignature with the returned type signature.

### `wildcardMatches`

If there are wildcards in the signature returned in the typeSignature argument, an enumerator of all matches between the wildcards and the concrete type instance given in the type argument is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager3> spManager; /* get the data model manager */
ComPtr<IDebugHostModule> spModule;   /* get a module */

// Find the type of "MyType<int>" within the module
ComPtr<IDebugHostType> spType;
if (SUCCEEDED(spModule->FindTypeByName(L"MyType<int>", &spType)))
{
    // Find the canonical visualizer which would be applied to MyType<int>
    ComPtr<IModelObject> spDataModel;
    ComPtr<IDebugHostTypeSignature> spSignature;
    ComPtr<IDebugHostSymbolEnumerator> spWildcardMatches;

    if (SUCCEEDED(spManager->GetModelForType(spType.Get(),
                                             &spDataModel,
                                             &spSignature,
                                             &spWildcardMatches)))
    {
        // There is a visualizer which matched.
        // spDataModel is the data model object which was registered as
        //     the canonical visualizer (RegisterModelForTypeSignature)
        // spSignature is the signature which that data model was registered
        //     against (e.g.: created for MyType<*> via
        //     CreateTypeSignature/RegisterModelForTypeSignature)
        // spWildcardMatches is an enumerator of the wildcard matches between
        //     the specific type spType and the signature spSignature (here
        //     int matched *, so there will be one item -- the type 'int' in
        //     the enumerator)
    }
```

## See also

[IDataModelManager3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager3)