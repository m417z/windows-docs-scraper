# IModelObject::GetTargetInfo

## Description

The GetTargetInfo method is effectively a combination of the GetLocation and GetTypeInfo methods returning both the abstract location as well as native type of the given object.

## Parameters

### `location`

The abstract location of the native object represented by the this pointer will be returned here.

### `type`

The native type of the object represented by the this pointer will be returned here as an [IDebugHostType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype) interface.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get an object */

Location loc;
ComPtr<IDebugHostType> spType;
if (SUCCEEDED(spObject->GetTargetInfo(&loc, &spType)))
{
    // loc has a valid location
    // spType has a valid type -- the type of the object
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)