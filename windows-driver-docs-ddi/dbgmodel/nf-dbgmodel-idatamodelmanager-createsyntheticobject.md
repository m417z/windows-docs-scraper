# IDataModelManager::CreateSyntheticObject

## Description

The CreateSyntheticObject method creates an empty data model object -- a dictionary of key/value/metadata tuples and concepts. At the time of creation, there are no keys nor concepts on the object. It is a clean slate for the caller to utilize.

## Parameters

### `context`

The debug host context which will be associated with the newly created synthetic object. Not every object requires a context. If the object refers to things such as processes, threads, or memory in the address space of the host, it may need one (unless it encapsulates other objects which contain such).

### `object`

The newly created object will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager> spManager; /* get the data model manager */

ComPtr<IModelObject> spNewObject;
if (SUCCEEDED(spManager->CreateSyntheticObject(nullptr, &spNewObject)))
{
     // spNewObject is an empty object (a dictionary of key/value/metadata tuples)
}

```

## See also

[IDataModelManager interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager)