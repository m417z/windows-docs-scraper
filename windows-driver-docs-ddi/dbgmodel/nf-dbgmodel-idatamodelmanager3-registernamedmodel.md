## Description

The RegisterNamedModel method registers a given data model under a well known name so that it can be found by clients wishing to extend it. This is the primary purpose of the API -- to publish a data model as something which can be extended by retrieving the model registered under this well known name and adding a parent model to it.
While the string passed in the modelName argument can be anything (it is just a name), there is a convention that it look like a dot separated namespace of the following form:

```text
• Debugger.Models.* - Data models which pertain to the debug target.
• DataModel.Models.* - Data models which pertain to the core data model itself.
   o DataModel.Models.Concepts.* - Data models which pertain to concepts in the data model.
```

An example of such a name is Debugger.Models.Process. This is the name under which the debugger's notion of a process is registered. A client which extends process and itself is extensible might register its extensibility point as Debugger.Models.Process.NamedExtensionPoint where NamedExtensionPoint refers to the semantics being added to process.

Note that if a given data model is registered under a name, the implementation of [IDataModelConcept](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelconcept) for that data model must have a GetName method which returns the name registered via calling this RegisterNamedModel method.

## Parameters

### `modelName`

The root namespace of the data model is returned here.

### `modeObject`

The data model being registered.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager3> spManager;    /* get the data model manager */
ComPtr<IModelObject> spDataModelObject; /* get your data model object (see
                                           CreateDataModelObject) */

// If the model is registered under a name (e.g.:
// Debugger.Models.Process.PrivateProcessExtension as below), the
// IDataModelConcept::GetName method must return one of the registration
// names (the one the extension considers "canonical").  It is legal for an
// object to be registered under multiple names.
if (SUCCEEDED(spManager->RegisterNamedModel(
    L"Debugger.Models.Process.PrivateProcessExtension",
    spDataModelObject.Get()))
    )
{
    // The model object spDataModelObject is now registered and can be looked up
    // under the name "Debugger.Models.Process.PrivateProcessExtension".
    // This means others can extend it by fetching that name.
    //
    // Fetch it back as example:
    ComPtr<IModelObject> spFetchedModel;
    if (SUCCEEDED(spManager->AcquireNamedModel(
        L"Debugger.Models.Process.PrivateProcessExtension",
        &spFetchedModel))
        )
    {
        // spFetchedModel should be the same as spDataModelObject
    }
}
```

## See also

[IDataModelManager3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager3)