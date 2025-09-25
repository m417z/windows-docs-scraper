# PointerKind enumeration

## Description

Defines the kind of a pointer type.

## Constants

### `PointerStandard`

Indicates a standard C/C++ pointer -- a *

### `PointerReference`

Indicates a C/C++ reference (whether const or not) -- a &

### `PointerRValueReference`

Indicates a C/C++ rvalue reference (whether const or not) -- a &&

### `PointerCXHat`

Indicates a C++/CX hat managed pointer (whether const or not) -- a ^

### `PointerManagedReference`

Indicates a managed pointer reference

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)