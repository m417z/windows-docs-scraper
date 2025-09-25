# IModelKeyReference::GetKeyName

## Description

The GetKeyName method returns the name of the key to which this key reference is a handle. The returned string is a standard BSTR and must be freed via a call to SysFreeString.

## Parameters

### `keyName`

The name of the key to which this key reference is a handle will be returned here as an allocated string.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get an object */

ComPtr<IModelKeyReference> spKeyRef;
if (SUCCEEDED(spObject->GetKeyReference(L"Id", &spKeyRef, nullptr)))
{
    // The key reference is a reference to the Id key.  The name returned
    // should be "Id"
    BSTR returnedKeyName;
    if (SUCCEEDED(spKeyRef->Getname(&returnedKeyName)))
    {
        // returnedKeyName is "Id"
        SysFreeString(returnedKeyName);
    }
}
```

## See also

[IModelKeyReference interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelkeyreference)