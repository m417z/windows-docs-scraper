## Description

The GetModelForTypeSignature method returns the data model that was registered against a particular type signature via a prior call to the RegisterModelForTypeSignature method. The data model returned from this method is considered the canonical visualizer for any type which matches the passed type signature. As a canonical visualizer, that data model takes over the display of the type. Display engines will, by default, hide native/language constructs of the object in favor of the view of the object presented by the data model.

## Parameters

### `typeSignature`

A type signature for which dataModel will be registered as the canonical visualizer. Any object created with a native/language type which matches the signature (and for which there is no better matching type signature) will automatically have the returned data model attached as a parent.

### `dataModel`

The data model which is registered as the canonical visualizer for all type instances which match the given type signature (and for which there is no better matching type signature.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager4> spManager; /* get the data model manager */
ComPtr<IDebugHost> spHost;           /* get the debug host */

ComPtr<IModelObject> spDataModel;    /* create a data model (see
                                        CreateDataModelObject) */

ComPtr<IDebugHostSymbols> spSym;
if (SUCCEEDED(spHost.As(&spSym)))
{
    // Create a signature to match MyType<*>
    ComPtr<IDebugHostTypeSignature> spTypeSignature;
    if (SUCCEEDED(spSym->CreateTypeSignature(L"MyType<*>", nullptr, &spTypeSignature)))
    {
        // Register the model for std::vector<*>
        if (SUCCEEDED(spManager->RegisterModelForTypeSignature(spTypeSignature.Get(),
                                                               spDataModel.Get()))
        {
            // Every instance matching MyType<*> will now have spDataModel
            // attached as the parent.  Further, such parent is considered
            // the canonical visualizer for all types matching MyType<*> since it
            // was registered via RegisterModelForTypeSignature instead of
            // RegisterExtensionForTypeSignature.
            //
            // Demonstrate that we can find the canonical visualizer under
            // this registration.
            ComPtr<IModelObject> spCanonicalVisualizerModel;
            if (SUCCEEDED(spManager->GetModelForTypeSignature(
                spTypeSignature.Get(),
                &spCanonicalVisualizerModel)))
            {
                // spCanonicalVisualizerModel is the same as spDataModel since
                // it was registered as such.
            }
        }
    }
}
```

## See also

[IDataModelManager4 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager4)