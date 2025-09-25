# MetadataBit enumeration

## Description

Defines constants that are used to define the [PropertyChainValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ns-xamlom-propertychainvalue) returned from XAML Diagnostics.

## Constants

### `None:0`

No special bits are set.

### `IsValueHandle:0x1`

The value represents a string representation of an **InstanceHandle**.

### `IsPropertyReadOnly:0x2`

The property is read only and cannot be set locally.

### `IsValueCollection:0x4`

The value represents a collection object. (When set, **IsValueHandle** is also set.)

### `IsValueCollectionReadOnly:0x8`

The value represents a read only collection.

### `IsValueBindingExpression:0x10`

The value represents the evaluated value of a binding expression.

### `IsValueNull:0x20`

The value is **null**. (Introduced in Windows 10, version 1607.)

### `IsValueHandleAndEvaluatedValue:0x40`

The value represents a string representation of an **InstanceHandle** and an evaluated value. (Introduced in Windows 10, version 1607.)