# FUNCKIND enumeration

## Description

Specifies the function type.

## Constants

### `FUNC_VIRTUAL:0`

The function is accessed the same as PUREVIRTUAL, except the function has an implementation.

### `FUNC_PUREVIRTUAL`

The function is accessed through the virtual function table (VTBL), and takes an implicit this pointer.

### `FUNC_NONVIRTUAL`

The function is accessed by static address and takes an implicit this pointer.

### `FUNC_STATIC`

The function is accessed by static address and does not take an implicit this pointer.

### `FUNC_DISPATCH`

The function can be accessed only through [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch).