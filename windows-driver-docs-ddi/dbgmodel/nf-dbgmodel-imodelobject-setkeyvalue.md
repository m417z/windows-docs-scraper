# IModelObject::SetKeyValue

## Description

The SetKeyValue method is the first method a client will turn to in order to set the value of a key. This method cannot be used to create a new key on an object. It will only set the value of an existing key. Note that many keys are read-only (e.g.: they are implemented by a property accessor which returns E_NOT_IMPL from it's SetValue method). This method will fail when called on a read only key.

## Parameters

### `key`

The name of the key to set a value for.

### `object`

The value of the key will be set to the object contained in this argument.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IDataModelManager> spManager; /* get the data model manager */
ComPtr<IModelObject> spObject;       /* get an object with a key named SomeKey */

// Box (int)42:
VARIANT vtVal;
vtVal.vt = VT_I4;
vtVal.lVal = 42;

ComPtr<IModelObject> spNewObject;
if (SUCCEEDED(spManager->CreateIntrinsicObject(ObjectIntrinsic, &vtVal, &spNewObject)))
{
    // Set the value of "SomeKey" to our newly boxed 42:
    if (SUCCEEDED(spObject->SetKeyValue(L"SomeKey", spNewObject.Get()))
    {
        // The key value has been set!
    }
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)