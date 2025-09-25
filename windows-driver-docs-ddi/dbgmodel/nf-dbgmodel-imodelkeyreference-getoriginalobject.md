# IModelKeyReference::GetOriginalObject

## Description

The GetOriginalObject method returns the instance object from which the key reference was created. Note that the key may itself be on a parent model of the instance object.

## Parameters

### `originalObject`

The instance object from which the key reference was created will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get an object */

ComPtr<IModelKeyReference> spKeyRef;
if (SUCCEEDED(spObject->GetKeyReference(L"Id", &spKeyRef, nullptr)))
{
    ComPtr<IModelObject> spOriginalObject;
    if (SUCCEEDED(spKeyRef->GetOriginalObject(&spOriginalObject)))
    {
        // spObject and spOriginalObject should be the same.
        // This is true even if someone calls
        // IModelKeyReference2::OverrideContextObject with some other object.
    }
}
```

## See also

[IModelKeyReference interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelkeyreference)