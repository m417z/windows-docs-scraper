# IKeyStore::ClearKeys

## Description

The ClearKeys method is analogous to the ClearKeys method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). It will remove every key from the given metadata store. This method has no effect on any parent store.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IKeyStore> spMetadata; /* get a metadata store */

if (SUCCEEDED(spMetadata->ClearKeys()))
{
    // The metadata store is now empty.  A parent store may still have keys
    // and GetKey[Value] may find those keys and values.
}
```

## See also

[IKeyStore interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeystore)