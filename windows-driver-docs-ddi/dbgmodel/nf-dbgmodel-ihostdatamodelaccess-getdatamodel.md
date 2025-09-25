# IHostDataModelAccess::GetDataModel

## Description

The GetDataModel method is the method on the bridge interface which provides access to both sides of the data model:

• The debug host (the lower edge of the debugger) is expressed by the returned [IDebugHost](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughost) interface

• The data model's main component -- the data model manager is expressed by the returned [IDataModelManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager) interface

## Parameters

### `manager`

An interface to the data model manager is returned here.

### `host`

The core interface of the debug host is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IDebugClient> spClient; /* get an IDebugClient* from DbgEng */

ComPtr<IHostDataModelAccess> spDataModelAccess;
if (SUCCEEDED(spClient.As(&spDataModelAccess)))
{
    ComPtr<IDataModelManager> spManager;
    ComPtr<IDebugHost> spHost;
    if (SUCCEEDED(spDataModelAccess->GetDataModel(&spManager, &spHost)))
    {
        // The data model manager and debug host have been fetched from the engine interface.
    }
}
```

## See also

[IDataHostModelAccess interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ihostdatamodelaccess)