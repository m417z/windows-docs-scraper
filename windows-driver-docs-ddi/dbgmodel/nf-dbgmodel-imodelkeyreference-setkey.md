# IModelKeyReference::SetKey

## Description

The SetKey method on a key reference behaves as the SetKey method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) would. It will assign the value of the key. If the original key was a property accessor, this will replace the property accessor. It will not call the SetValue method on the property accessor.

## Parameters

### `object`

The value to assign to the key.

### `metadata`

Optional metadata to be associated with the key.

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
        if (SUCCEEDED(spKeyRef->SetKey(sp42.Get(), nullptr)))
        {
            // The "Id" key has been overwritten with the value 42.
            // If the "Id" key originally was a property accessor, it isn't anymore.
            // This would not have called SetValue() on the property accessor.
            // It replaced the property accessor with a static "42".
        }
    }
}
```

## See also

[IModelKeyReference interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelkeyreference)