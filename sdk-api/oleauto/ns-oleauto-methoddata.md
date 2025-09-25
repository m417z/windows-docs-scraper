# METHODDATA structure

## Description

Describes a method or property.

## Members

### `szName`

 The method name.

### `ppdata`

An array of method parameters.

### `dispid`

 The ID of the method, as used in [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch).

### `iMeth`

 The index of the method in the VTBL of the interface, starting with 0.

### `cc`

The calling convention. The CDECL and Pascal calling conventions are supported by the dispatch interface creation functions, such as [CreateStdDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-createstddispatch).

### `cArgs`

 The number of arguments.

### `wFlags`

Invoke flags.

| Value | Meaning |
| --- | --- |
| **DISPATCH_METHOD** | The member is invoked as a method. If a property has the same name, both this and the DISPATCH_PROPERTYGET flag can be set. |
| **DISPATCH_PROPERTYGET** | The member is retrieved as a property or data member. |
| **DISPATCH_PROPERTYPUT** | The member is set as a property or data member. |
| **DISPATCH_PROPERTYPUTREF** | The member is changed by a reference assignment, rather than a value assignment. This flag is valid only when the property accepts a reference to an object. |

### `vtReturn`

The return type for the method.