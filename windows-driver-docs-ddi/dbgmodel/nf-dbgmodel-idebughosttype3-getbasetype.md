## Description

If the type is a derivative of another single type (e.g.: as MyStruct * is derived from MyStruct'), the GetBaseType method returns the base type of the derivation. For pointers, this returns the type pointed to. For arrays, this returns what the array is an array of. If the type is not such a derivative type, an error is returned.

Note that this method has nothing to do with C++ (or other linguistic) base classes. Such are symbols ([IDebugHostBaseClass](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostbaseclass)) which can be enumerated from the derived class via a call to the EnumerateChildren method.

## Parameters

### `baseType`

The type that this type is derived from is returned here. This is the type pointed to, the type an array contains, etc...

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostType3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3)