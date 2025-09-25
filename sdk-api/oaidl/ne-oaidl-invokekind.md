# INVOKEKIND enumeration

## Description

Specifies the way a function is invoked.

## Constants

### `INVOKE_FUNC:1`

The member is called using a normal function invocation syntax.

### `INVOKE_PROPERTYGET:2`

The function is invoked using a normal property-access syntax.

### `INVOKE_PROPERTYPUT:4`

The function is invoked using a property value assignment syntax. Syntactically, a typical programming language might represent changing a property in the same way as assignment. For example: object.property : = value.

### `INVOKE_PROPERTYPUTREF:8`

The function is invoked using a property reference assignment syntax.

## Remarks

In C, value assignment is written as *pobj1 = *pobj2, while reference assignment is written as pobj1 = pobj2. Other languages have other syntactic conventions. A property or data member can support only a value assignment, a reference assignment, or both. The INVOKEKIND enumeration constants are the same constants that are passed to [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) to specify the way in which a function is invoked.