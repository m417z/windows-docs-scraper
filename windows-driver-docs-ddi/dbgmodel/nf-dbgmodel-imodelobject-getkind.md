# IModelObject::GetKind

## Description

The GetKind method returns what kind of object is boxed inside the [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). Such kind is defined by the [ModelObjectKind enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ne-dbgmodel-modelobjectkind).

## Parameters

### `kind`

The kind of object as indicated above will be returned in this argument.

## Return value

This method returns HRESULT that indicates success or failure. This method should not typically fail.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* acquired from somewhere */

ModelObjectKind kind;
HRESULT hr = spObject->GetKind(&kind);

// kind indicates the kind of model object
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)