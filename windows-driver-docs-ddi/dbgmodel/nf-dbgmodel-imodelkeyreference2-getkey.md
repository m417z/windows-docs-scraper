# IModelKeyReference2::GetKey

## Description

The GetKey method on a key reference behaves as the GetKey method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) would. It returns the value of the underlying key and any metadata associated with the key. If the value of the key happens to be a property accessor, this will return the property accessor ([IModelPropertyAccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor)) boxed into an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). This method will not call the underlying GetValue or SetValue methods on the property accessor.

## Parameters

### `object`

The value of the key will be returned here.

### `metadata`

Optional metadata which is associated with the key will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get an object */

ComPtr<IModelKeyReference> spKeyRef;
if (SUCCEEDED(spObject->GetKeyReference(L"Id", &spKeyRef, nullptr)))
{
    ComPtr<IModelObject> spKey;
    if (SUCCEEDED(spKeyRef->GetKey(&spKey, nullptr)))
    {
        // spKey contains the equivalent of spObject->GetKey(L"Id", &spKey, nullptr)
        // This may be a property accessor since this was not a GetKeyValue.
        // Check and fetch.  Note that GetKeyValue would do this for you.
        ModelObjectKind kind;
        if (SUCCEEDED(spKey->GetKind(&kind)))
        {
            if (kind == ObjectPropertyAccessor)
            {
                VARIANT vtProp;
                if (SUCCEEDED(spKey->GetIntrinsicValue(&vtProp)))
                {
                    // We are guaranteed *in-process* that the IUnknown is
                    // an IModelPropertyAccessor via the ObjectPropertyAccessor
                    IModelPropertyAccessor *pProperty =
                        static_cast<IModelPropertyAccessor *>(vtProp.punkVal);

                    // In order to fetch, we need to know the context object and
                    // the key name.  Fetch it from the key reference.
                    ComPtr<IModelObject> spContextObject;
                    if (SUCCEEDED(spKeyRef->GetContextObject(&spContextObject)))
                    {
                        BSTR keyName;
                        if (SUCCEEDED(spKeyRef->GetName(&keyName)))
                        {
                            ComPtr<IModelObject> spKeyValue;
                            if (SUCCEEDED(pProperty->GetValue(keyName,
                                                              spContextObject.Get(),
                                                              &spKeyValue)))
                            {
                                // spKeyValue contains the value of the "Id" key.
                            }

                            SysFreeString(keyName);
                        }
                    }

                    VariantFree(&vtProp);
                }
            }
            else
            {
                // spKey contains the value of the "Id" key.
            }
        }
    }
}
```

## See also

[IModelKeyReference2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelkeyreference2)