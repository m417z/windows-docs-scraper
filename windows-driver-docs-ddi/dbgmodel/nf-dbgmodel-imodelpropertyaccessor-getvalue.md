# IModelPropertyAccessor::GetValue

## Description

The GetValue method is the getter for the property accessor. It is called whenever a client wishes to fetch the underlying value of the property. Note that any caller which directly gets a property accessor is responsible for passing the key name and accurate instance object (this pointer) to the property accessor's GetValue method.

## Parameters

### `key`

The name of the key to get a value for. A caller which fetches a property accessor directly is responsible for passing this accurately.

### `contextObject`

The context object (instance this pointer) from which the property accessor was fetched.

### `value`

The underlying value of the property is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
// The full implementation class is shown for clarity.
class MyReadOnlyProperty :
    public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<
            Microsoft::WRL::RuntimeClassType::ClassicCom
            >,
        IModelPropertyAccessor
        >
{
public:

    IFACEMETHOD(GetValue)(_In_ PCWSTR /*pwszKey*/,
                          _In_ IModelObject * /*pContextObject*/,
                          _COM_Errorptr_ IModelObject **ppValue)
    {
        HRESULT hr = S_OK;
        *ppValue = nullptr;

        VARIANT vtValue;
        vtValue.vt = VT_I4;
        vtValue.lVal = m_value;

        ComPtr<IModelObject> spValue;
        hr = GetManager()->CreateIntrinsicObject(ObjectIntrinsic, &vtValue, &spValue);
        if (SUCCEEDED(hr))
        {
            *ppValue = spValue.Detach();
        }

        return hr;
    }

    IFACEMETHOD(SetValue)(_In_ PCWSTR /*pwszKey*/,
                          _In_ IModelObject * /*pContextObject*/,
                          _In_ IModelObject * /*pValue*/)
    {
        // We are a read only property.
        return E_NOTIMPL;
    }

    HRESULT RuntimeClassInitialize(_In_ int value)
    {
        m_value = value;
        return S_OK;
    }

private:

    int m_value;
};
```

## See also

[IModelPropertyAcessor interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor)