# IModelObject::ClearKeys

## Description

The ClearKeys method removes all keys and their associated values and metadata from the instance of the object specified by this. This method has no effect on parent models attached to the particular object instance.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get an object */

if (SUCCEEDED(spObject->ClearKeys()))
{
    // The *instance* spObject has no keys.  Parent models may still have keys.
    // EnumerateKeyValues / EnumerateKeys / etc... may still return those parent keys.
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)