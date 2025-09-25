# IModelObject::GetKey

## Description

The GetKey method will get the value of (and the metadata associated with) a given key by name. Most clients should utilize the GetKeyValue method instead. If the key is a property accessor, calling this method will return the property accessor (an [IModelPropertyAccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor) interface) boxed into an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). Unlike, GetKeyValue, this method will not automatically resolve the underlying value of the key by calling the GetValue method. That responsibility is the caller's.

## Parameters

### `key`

The name of the key to get a value for.

### `object`

The value of the key will be returned in this argument. In some error cases, extended error information may be passed out in this argument even though the method returns a failing HRESULT.

### `metadata`

The metadata store associated with this key will be optionally returned in this argument.

## Return value

This method returns HRESULT that indicates success or failure. The return values E_BOUNDS (or E_NOT_SET in some cases) indicates the key could not be found.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spProcess; /* get a process object */

ComPtr<IModelObject> spIdKey;
if (SUCCEEDED(spProcess->GetKey(L"Id", &spIdKey, nullptr)))
{
    // Unlike GetKeyValue(), spIdKey may contain a value or it may be a
    // *property* that needs to be fetched.  Check!
    ModelObjectKind kind;
    if (SUCCEEDED(spIdKey->GetKind(&kind)))
    {
        if (kind == ObjectPropertyAccessor)
        {
            VARIANT vtProp;
            if (SUCCEEDED(spIdKey->GetIntrinsicValue(&vtProp)))
            {
                // There is an *in-process* guarantee because of
                // ObjectPropertyAccessor that the IUnknown is an IModelPropertyAccessor
                IModelPropertyAccessor *pPropertyAccessor =
                    static_cast<IModelPropertyAccessor *>(vtProp.punkVal);

                // Fetch the value underneath the property accessor.  GetKeyValue
                // would have done this for us.
                ComPtr<IModelObject> spId;
                if (SUCCEEDED(pPropertyAccessor->GetValue(L"Id", spProcess.Get(), &spId)))
                {
                    // spId now contains the value of the id.  Unbox with GetIntrinsicValueAs.
                }

                VariantClear(&vtProp);
            }
        }
        else
        {
            // spIdKey contains the value.  Unbox with GetIntrinsicValueAs.
        }
    }
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)