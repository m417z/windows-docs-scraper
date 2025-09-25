# IModelKeyReference2::GetKeyValue

## Description

The GetKeyValue method on a key reference behaves as the GetKeyValue method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) would. It returns the value of the underlying key and any metadata associated with the key. If the value of the key happens to be a property accessor, this will call the underlying GetValue method on the property accessor automatically.

## Parameters

### `object`

The value of the key will be returned here. Note that extended error information may be returned here on failure.

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
    ComPtr<IModelObject> spId;
    if (SUCCEEDED(spKeyRef->GetKeyValue(&spId, nullptr)))
    {
        // spId contains the value of the "Id" key
    }
}
```

## See also

[IModelKeyReference2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelkeyreference2)