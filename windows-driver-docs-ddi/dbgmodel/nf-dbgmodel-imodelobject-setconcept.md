# IModelObject::SetConcept

## Description

The SetConcept method will place a specified concept on the object instance specified by the this pointer. If a parent model attached to the object instance specified by this also supports the concept, the implementation in the instance will override that in the parent model.

For the set of concepts (interfaces) that are supported by the data model, see [Debugger Data Model C++ Concepts](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-concepts).

For information on the [IKeyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeystore) interface, see [IKeyStore interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeystore).

## Parameters

### `conceptId`

The unique identifier of the concept being assigned. This is also the IID of the core interface of the concept.

### `conceptInterface`

The concept interface being assigned (defined by conceptId).

### `conceptMetadata`

Optional metadata to be associated with this concept.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get an object: say a new one from CreateSyntheticObject */

// Implement IStringDisplayableConcept for the object.  Return a static "Hello World" string.
class MyStringConversion :
    public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::ClassicCom>,
        IStringDisplayableConcept
        >
{
public:

    IFACEMETHOD(ToDisplayString)(_In_ IModelObject * /*pContextObject*/,
                                 _In_opt_ IKeyStore * /*pMetadata*/,
                                 _Out_ BSTR *pDisplayString)
    {
        *pDisplayString = SysAllocString(L"Hello World");
        return *pDisplayString == nullptr ? E_OUTOFMEMORY : S_OK;
    }
};

// Add the implementation as a concept
ComPtr<MyStringConversion> spStringConverter = Microsoft::WRL::Make<MyStringConversion>();
if (spStringConverter != nullptr)
{
    if (SUCCEEDED(spObject->SetConcept(__uuidof(IStringDisplayableConcept),
                                       static_cast<IStringDisplayableConcept *>
                                           (spStringConverter.Get()), nullptr)))
    {
        // The new object can be converted to a string!
    }
}
```

## See also

[Debugger Data Model C++ Concepts](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-concepts)

[IKeyStore interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeystore)

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)