# LocationKind enumeration

## Description

Defines the location of a field or other data.

## Constants

### `LocationMember`

The field is a member and has an offset relative to the this pointer.

### `LocationStatic`

The field is static and has an address.

### `LocationConstant`

The field is constant and has a value.

### `LocationNone`

The field has no location (e.g.: it has been optimized out or was a static which was defined but not declared).

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)