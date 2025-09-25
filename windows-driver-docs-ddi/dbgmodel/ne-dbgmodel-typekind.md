# TypeKind enumeration

## Description

Defines the kind of a type.

## Constants

### `TypeUDT`

A user defined type (a struct, class, union, etc...). A model object which has a native type whose kind is TypeUDT has a canonical representation of ObjectTargetObject where the type is always kept inside the corresponding [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject).

### `TypePointer`

A pointer. A model object which has a native type whose kind is TypePointer has a canonical representation of ObjectIntrinsic where the pointer's value is zero extended to VT_UI8 and kept as intrinsic data in this 64-bit form. Any type symbol of TypePointer has a base type (as returned by the GetBaseType method) of the type that the pointer points to.

### `TypeMemberPointer`

A pointer to class member. A model object which has a native type whose kind is TypeMemberPointer has a canonical representation which is intrinsic (the value being the same as the pointer value). The exact meaning of this value is compiler/debug host specific.

### `TypeArray`

An array. A model object which has a native type whose kind is TypeArray has a canonical representation of ObjectTargetObject. The base address of the array is the object's location (retrieved via the GetLocation method) and the type of the array is always kept. Any type symbol of TypeArray has a base type (as returned by the GetBaseType method) of the type that the array is an array of.

### `TypeFunction`

A function.

### `TypeTypedef`

A typedef. A model object which has a native type whose kind would otherwise be TypeTypedef has a canonical representation identical to the canonical representation of the final type underlying the typedef. This appears completely transparent to the end user of the object and the type information unless the explicit typedef methods of [IDebugHostType2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype2) are utilized to query typedef information or there is an explicit data model registered against the typedef. Note that the GetTypeKind method will never return TypeTypedef. Every method will return what the final type underlying the typedef would return. There are typedef specific methods on [IDebugHostType2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype2) which can be used to get the typedef specific information.

### `TypeEnum`

An enum. A model object which has a native type whose kind is TypeEnum has a canonical representation of ObjectIntrinsic where the value and type of the intrinsic is identical to the enum value.

### `TypeIntrinsic`

An intrinsic (base type). A model object which has a native type whose kind is TypeIntrinsic has a canonical representation of ObjectIntrinsic. The type information may or may not be kept -- particularly if the underlying type is fully described by the variant data type (VT_*) of the intrinsic data stored in the [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)

## `TypeExtendedArray`

The type is an array which cannot be expressed as TypeArray. This is due to things such as dynamic sizes, dynamic bounds, etc... CLI arrays are represented as TypeExtendedArray.

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)