## Description

The Close method is called on the data model manager by an application (e.g.: debugger) hosting the data model in order to start the shutdown process of the data model manager. A host of the data model which does not the Close method prior to releasing its final reference on the data model manager may cause undefined behavior including, but not limited to, significant leaks of the management infrastructure for the data model.

## Return value

This method returns HRESULT.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager3> spManager; /* get the data model manager */

if (SUCCEEDED(spManager->Close()))
{
    // We can now shut down the debug host which is hosting the data model.
}

```

## See also

[IDataModelManager3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager3)