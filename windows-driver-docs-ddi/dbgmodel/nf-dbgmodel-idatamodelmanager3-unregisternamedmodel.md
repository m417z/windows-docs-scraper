## Description

The UnregisterNamedModel method undoes a prior call to RegisterNamedModel. It removes the association between a data model and a name under which it can be looked up.

## Parameters

### `modelName`

The name which will be unregistered. Any data model registered under this name will no longer be registered.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager3> spManager;    /* get the data model manager */

if (SUCCEEDED(spManager->UnregisterNamedModel(
    L"Debugger.Models.Process.PrivateProcessExtension")))
{
    // Whatever data model was registered under
    // Debugger.Models.Process.PrivateProcessExtension is no longer registered.
}
```

## See also

[IDataModelManager3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager3)