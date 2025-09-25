# IModelKeyReference2::SetKeyValue

## Description

The SetKeyValue method on a key reference behaves as the SetKeyValue method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) would. It will assign the value of the key. If the original key was a property accessor, this will call the underlying SetValue method on the property accessor rather than replacing the property accessor itself.

## Parameters

### `object`

The value to assign to the key.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IDataModelManager> spManager; /* get the data model manager */
ComPtr<IModelObject> spObject;       /* get an object */

ComPtr<IModelKeyReference> spKeyRef;
if (SUCCEEDED(spObject->GetKeyReference(L"Id", &spKeyRef, nullptr)))
{
    VARIANT vtValue;
    vtValue.vt = VT_UI8;
    vtValue.ullVal = 42;

    ComPtr<IModelObject> sp42;
    if (SUCCEEDED(spManager->CreateIntrinsicObject(ObjectIntrinsic, &vtValue, &sp42)))
    {
        if (SUCCEEDED(spKeyRef->SetKeyValue(sp42.Get())))
        {
            // The value of the "Id" key is now 42.  If the "Id" key originally
            // was a property accessor, this successfully called
            // the SetValue() method on the property accessor.  In such a case,
            // the property accessor was not replaced with the static 42,
            // it was called to set the value 42.
        }
    }
}
```

## See also

[IModelKeyReference2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelkeyreference2)