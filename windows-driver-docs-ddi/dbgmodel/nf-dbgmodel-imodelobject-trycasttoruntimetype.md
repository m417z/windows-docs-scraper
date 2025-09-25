# IModelObject::TryCastToRuntimeType

## Description

The TryCastToRuntimeType method will ask the debug host to perform an analysis and determine the actual runtime type (e.g.: most derived class) of the given object. The exact analysis utilized is specific to the debug host and may include RTTI (C++ run time type information), examination of the V-Table(virtual function table) structure of the object, or any other means that the host can use to reliably determine dynamic/runtime type from the static type. Failure to convert to a runtime type does not mean that this method call will fail. In such cases, the method will return the given object (the this pointer) in the output argument.

## Parameters

### `runtimeTypedObject`

The conversion of the given object to an instance of its dynamic/runtime type will be returned in this argument. If analysis fails to find a change in static type, the given object (this pointer) maybe returned (with an additional reference) in this output.

## Return value

This method returns HRESULT that indicates success or failure. Note that an analysis which cannot find a derived type is not a failure as defined here.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spUnknown; /* get an IUnknown pointer to some CFoo */

ComPtr<IModelObject> spRuntimeObj;
if (SUCCEEDED(spUnknown->TryCastToRuntimeType(&spRuntimeObj)))
{
    // spRuntimeObj will refer to the CFoo.
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)