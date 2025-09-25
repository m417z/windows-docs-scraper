# IKeyStore::SetKeyValue

## Description

The SetKeyValue method is analogous to the SetKeyValue method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). This method is not capable of creating a new key within the metadata store. If there is an existing key as indicated by the key argument, its value will be set as indicated. If the key is a property accessor, the SetValue method will be called on the property accessor in order to set the underlying value. Note that metadata is typically static once created. Use of this method on a metadata key store should be infrequent.

## Parameters

### `key`

The name of the key to set a value for.

### `object`

The value to assign to the key. If the current key's value is a property accessor, the SetValue method will be called on the property accessor to set the underlying value.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IKeyStore> spMetadata; /* get a metadata store */
ComPtr<IModelObject> spValue; /* get a value to set */

// This never creates a key.  Most callers should prefer SetKey
if (SUCCEEDED(spMetadata->SetKeyValue(L"KnownExistingKey", spValue.Get()))
{
    // The key's value was successfully set.
}
```

## See also

[IKeyStore interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeystore)