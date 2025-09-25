# IModelObject::AddParentModel

## Description

The AddParentModel method adds a new parent model to the given object. Such a model may be added at the end of the search chain (the override argument is specified as false) or at the front of the search chain (the override argument is specified as true). In addition, each parent model may optionally adjust the context (the semantic this pointer) for any property or concept on the given parent (or anyone in its parent hierarchy). Context adjustment is seldom used but allows for some powerful concepts like object embedding, constructing namespaces, etc...

When a parent model has a context adjustment, the core data model will perform this adjustment automatically on behalf of the caller. In effect, for an object instance with a parent model parent having a context adjustor to newContext, a call of

```cpp
instance->GetKeyValue("someKey", &pValue, nullptr);
```

will end up changing the context/this pointer from instance to newContext before calling someKey's GetValue method since the access to someKey passed through the context adjustor.

Any [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) which is added as a parent model to another object must individually support the [IDataModelConcept](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelconcept) concept. Failure to implement this concept may result in the AddParentModel method call failing.

## Parameters

### `model`

An [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) which will be added to the parent model chain of the given object. This [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) must individually support the [IDataModelConcept](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelconcept) concept.

### `contextObject`

If the data model has a context adjustment associated with it, the adjusted context (or a property accessor which returns the adjusted context) may be passed here.

### `override`

An indication of whether the parent model specified by the model argument is placed at the front or the end of the linear chain of parent models. A value of false (normally supplied) indicates the end of the chain. A value of true indicates the front of the chain.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

** Code Sample**

```cpp

ComPtr<IDataModelManager> spManager; /* get the data model manager */
ComPtr<IModelObject> spObject;       /* get an object */

// A data model *MUST* implement IDataModelConcept.  Create an implementation of this and a string conversion.
class MyDataModel :
    public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::ClassicCom>,
        IDataModelConcept,
        IStringDisplayableConcept
        >
{
public:

    IFACEMETHOD(InitializeObject)(_In_ IModelObject * /*pModelObject*/,
                                  _In_opt_ IDebugHostTypeSignature * /*pMatchingSignature*/,
                                  _In_opt_ IDebugHostSymbolEnumerator * /*pWildcardMatches*/)
    {
        return S_OK;
    }

    IFACEMETHOD(GetName)(_Out_ BSTR *pModelName)
    {
        return E_NOTIMPL;
    }

    IFACEMETHOD(ToDisplayString)(_In_ IModelObject * /*pContextObject*/,
                                 _In_opt_ IKeyStore * /*pMetadata */,
                                 _Out_ BSTR *pDisplayString)
    {
        *pDisplayString = SysAllocString(L"Hello World");
        return *pDisplayString == nullptr ? E_OUTOFMEMORY : S_OK;
    }
};

// Create the data model, an object for it, set concepts, and add it as a parent to spObject.
ComPtr<MyDataModel> spDataModel = Microsoft::WRL::Make<MyDataModel>();
ComPtr<IModelObject> spDataModelObject;
if (spDataModel != nullptr &&
    SUCCEEDED(spManager->CreateDataModelObject(spDataModel.Get(), &spDataModelObject)) &&
    SUCCEEDED(spDataModelObject->SetConcept(__uuidof(IStringDisplayableConcept),
                                            static_cast<IStringDisplayableConcept *>
                                                (spDataModel.Get()),
                                            nullptr)))
{
    if (SUCCEEDED(spObject->AddParentModel(spDataModelObject.Get(), nullptr, false)))
    {
        // spObject has been *EXTENDED* to have a display string.  It has a parent model
        // which has that concept.  That extension (and whatever else was added
        // on spDataModelObject) can be removed with a single RemoveParentModel call.
    }
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)