## Description

The CreateDataModelObject method is a simple helper wrapper to create objects which are data models -- that is objects which are going to be attached as parent models to other objects. All such objects must support the data model concept via [IDataModelConcept](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelconcept). This method creates a new blank synthetic object with no explicit context and adds the inpassed [IDataModelConcept](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelconcept) as the newly created object's implementation of the data model concept. This can similarly be accomplished with calls to CreateSyntheticObject and SetConcept.

## Parameters

### `dataModel`

The implementation of [IDataModelConcept](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelconcept) which will be automatically added to the newly created object as its implementation of the data model concept.

### `object`

The newly created synthetic object (with the data model concept set) will be returned here.

## Return value

This method returns HRESULT.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager3> spManager; /* get the data model manager */

// We need some IDataModelConcept implementation.  Provide a
// minimal one for example purposes.
class MyDataModel :
    public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<
            Microsoft::WRL::RuntimeClassType::ClassicCom
            >,
        IDataModelConcept
        >
{
public:

    IFACEMETHOD(InitializeObject)(
        _In_ IModelObject * /*pContextObject*/,
        _In_opt_ IDebugHostTypeSignature * /*pMatchingSignature*/,
        _In_opt_ IDebugHostSymbolEnumerator * /*pWildcardMatches*/
        )
    {
        return S_OK;
    }

    IFACEMETHOD(GetName)(_Out_ BSTR *pModelName)
    {
        *pModelName = nullptr;
        return E_NOTIMPL;
    }
};

ComPtr<MyDataModel> spMyModel = Microsoft::WRL::Make<MyDataModel>();
if (spMyModel != nullptr)
{
    ComPtr<IModelObject> spDataModelObject;
    if (SUCCEEDED(spManager->CreateDataModelObject(spMyModel.Get(),
                                                   &spDataModelObject)))
    {
        // spDataModelObject is now a data model object and can be attached
        // as a parent to any other object via AddParentModel().
    }
}
```

## See also

[IDataModelManager3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager3)