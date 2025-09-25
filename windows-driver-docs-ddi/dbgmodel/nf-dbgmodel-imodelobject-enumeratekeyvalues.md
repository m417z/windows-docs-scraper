# IModelObject::EnumerateKeyValues

## Description

The EnumerateKeyValues method is the first method a client will turn to in order to enumerate all of the keys on an object (this includes all keys implemented anywhere in the tree of parent models). It is important to note that EnumerateKeyValues will enumerate any keys defined by duplicate names in the object tree; however -- methods like GetKeyValue and SetKeyValue will only manipulate the first instance of a key with the given name as discovered by the depth-first-traversal.

## Parameters

### `enumerator`

An enumerator for all keys on the object (and all of its parent models) and their values and metadata is returned in this argument as an [IKeyEnumerator](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeyenumerator).

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get the object you want to enumerate */

ComPtr<IKeyEnumerator> spEnum;
if (SUCCEEDED(spObject->EnumerateKeyValues(&spEnum)))
{
    HRESULT hr = S_OK;
    while (SUCCEEDED(hr))
    {
        BSTR keyName;
        ComPtr<IModelObject> spKeyValue;
        hr = spEnum->GetNext(&keyName, &spKeyValue, nullptr);
        if (SUCCEEDED(hr))
        {
            // keyName contains the name of the key
            // spKeyValue contains the value of the key

            SysFreeString(keyName);
        }
    }

    // hr == E_BOUNDS  : We hit the end of the enumerator
    // hr == E_ABORT   : User is requesting interruption of the
    // operation / stop immediately and flow the error
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)