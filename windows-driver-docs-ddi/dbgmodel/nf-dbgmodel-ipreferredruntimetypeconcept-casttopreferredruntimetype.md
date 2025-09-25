# IPreferredRuntimeTypeConcept::CastToPreferredRuntimeType

## Description

The CastToPreferredRuntimeType method is called whenever a client wishes to attempt to convert from a static type instance to the runtime type of that instance. If the object in question supports (through one of its attached parent models) the preferred runtime type concept, this method will be called to perform the conversion. This method may either return the original object (there is no conversion or it could not be analyzed), return a new instance of the runtime type, fail for non-semantic reasons (e.g.: out of memory), or return E_NOT_SET. The E_NOT_SET error code is a very special error code which indicates to the data model that the implementation does not want to override the default behavior and that the data model should fall back to whatever analysis is performed by the debug host (e.g.: RTTI analysis, examination of the shape of the virtual function tables, etc...)

## Parameters

### `contextObject`

The statically typed instance object (this pointer) for which to perform analysis and attempt to downcast to the runtime type.

### `object`

If a conversion to a runtime type occurred, this is a new instance typed according to the runtime type. If the analysis could not be performed or there was no change in type, this may be the original object.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Example Implementation:**

```cpp
IFACEMETHOD(CastToPreferredRuntimeType)(_In_ IModelObject *pContextObject,
                                        _COM_Outptr_ IModelObject **ppRuntimeObject)
{
    HRESULT hr = S_OK;
    *ppRuntimeObject = nullptr;

    ComPtr<IModelObject> spRuntimeObject;

    // Imagine this was on a class for a data model registered against some
    // IFoo type where IFoo was always backed by CFoo (the type of which is
    // stored in m_spType) and the offset between IFoo and CFoo was m_runtimeOffset.
    Location loc;
    hr = pContextObject->GetLocation(&loc);
    if (SUCCEEDED(hr))
    {
        loc.Offset -= m_runtimeOffset;

        // By passing 'nullptr' as the context, it will inherit its context
        // from the passed type.  Sufficient for *THIS* purpose in *MOST* cases.
        hr = GetManager()->CreateTypedObject(nullptr,
                                             loc,
                                             m_spType.Get(),
                                             &spRuntimeObject);
    }

    if (SUCCEEDED(hr))
    {
        *ppRuntimeObject = spRuntimeObject.Detach();
    }

    return hr;
}
```

## See also

[IPreferredRuntimeTypeConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ipreferredruntimetypeconcept)