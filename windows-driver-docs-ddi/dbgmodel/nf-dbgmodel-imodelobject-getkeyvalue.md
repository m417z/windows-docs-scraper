# IModelObject::GetKeyValue

## Description

The GetKeyValue method is the first method a client will turn to in order to get the value of (and the metadata associated with) a given key by name. If the key is a property accessor -- that is it's value as an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) which is a boxed [IModelPropertyAccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor), the GetKeyValue method will automatically call the property accessor's GetValue method in order to retrieve the actual value.

## Parameters

### `key`

The name of the key to get a value for.

### `object`

The value of the key will be returned in this argument. In some error cases, extended error information may be passed out in this argument even though the method returns a failing HRESULT.

### `metadata`

The metadata store associated with this key will be optionally returned in this argument.

## Return value

This method returns HRESULT that indicates success or failure. The return values E_BOUNDS (or E_NOT_SET in some cases) indicates the key could not be found.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spProcess; /* get a process object */

ComPtr<IModelObject> spProcId;
if (SUCCEEDED(spProcess->GetKeyValue(L"Id", &spProcId, nullptr)))
{
    // spProcId has a boxed process id.  Use GetIntrinsicValueAs to unbox it.
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)