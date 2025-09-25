# TYPEKIND enumeration

## Description

Specifies a type.

## Constants

### `TKIND_ENUM:0`

A set of enumerators.

### `TKIND_RECORD`

A structure with no methods.

### `TKIND_MODULE`

A module that can only have static functions and data (for example, a DLL).

### `TKIND_INTERFACE`

A type that has virtual and pure functions.

### `TKIND_DISPATCH`

A set of methods and properties that are accessible through [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke). By default, dual interfaces return TKIND_DISPATCH.

### `TKIND_COCLASS`

A set of implemented component object interfaces.

### `TKIND_ALIAS`

A type that is an alias for another type.

### `TKIND_UNION`

A union, all of whose members have an offset of zero.

### `TKIND_MAX`

End of enum marker.