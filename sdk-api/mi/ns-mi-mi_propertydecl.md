# MI_PropertyDecl structure

## Description

Represents a class property (element) in a class's declaration.

## Members

### `flags`

#### MI_FLAG_PROPERTY ((1 << 2))

Indicates structure is a property.

#### MI_FLAG_KEY ((1 << 12))

Indicate structure is a key property.

### `code`

Hash code: (name[0] << 16) | (name[len-1] << 8) | len

### `name`

Name of this property.

### `qualifiers`

Qualifier set for this property.

### `numQualifiers`

Number of qualifiers.

### `type`

Type of property.

### `className`

Name of reference class or embedded instance class name.

### `subscript`

If property is a fixed length array, then this value will hold the length of the array.

### `offset`

Offset of this property field from the start of the [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance).

### `origin`

Ancestor class that first defined a property with this name.

### `propagator`

Ancestor class that last defined a property with this name.

### `value`

Default value of this property.