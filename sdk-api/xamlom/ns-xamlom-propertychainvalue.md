# PropertyChainValue structure

## Description

Represents a property defined on an element.

## Members

### `Index`

The index of property in the XAML runtime.

### `Type`

The type of the object.

### `DeclaringType`

The base type of the object.

### `ValueType`

The type of the current value of the property.

### `ItemType`

Collection item type, or **null** if not a collection.

### `Value`

The value of the property. (Represents an **InstanceHandle** if [MetadataBit](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ne-xamlom-metadatabit) is set.)

### `Overridden`

Indicates whether the property is overridden by some property in the value chain.

### `MetadataBits`

A bit field that represents [MetadataBit](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ne-xamlom-metadatabit)s.

### `PropertyName`

The name of the property.

### `PropertyChainIndex`

The index in the [PropertyChainSource](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/ns-xamlom-propertychainsource) returned by GetPropertyValuesChain
that represents the source of this property.