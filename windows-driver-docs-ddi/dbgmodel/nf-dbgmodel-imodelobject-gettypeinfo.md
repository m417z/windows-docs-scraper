# IModelObject::GetTypeInfo

## Description

The GetTypeInfo method will return the native type of the given object. If the object does not have native type information associated with it (e.g.: it is an intrinsic, etc...), the call will still succeed but will return null.

## Parameters

### `type`

The native type of the object represented by the this pointer will be returned here as an [IDebugHostType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype) interface.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

In this sample the [IDebugHostType interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype) is used.

```cpp
ComPtr<IModelObject> spObject; /* get an object */

ComPtr<IDebugHostType> spType;
if (SUCCEEDED(spObject->GetTypeInfo(&spType)) && spType != nullptr)
{
    // The object has a native type.  spType is such type.
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)