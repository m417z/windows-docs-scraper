# VARKIND enumeration

## Description

Specifies the variable type.

## Constants

### `VAR_PERINSTANCE:0`

The variable is a field or member of the type. It exists at a fixed offset within each instance of the type.

### `VAR_STATIC`

There is only one instance of the variable.

### `VAR_CONST`

The VARDESC describes a symbolic constant. There is no memory associated with it.

### `VAR_DISPATCH`

The variable can only be accessed through [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).