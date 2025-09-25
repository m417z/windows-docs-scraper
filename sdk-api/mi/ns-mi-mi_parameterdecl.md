# MI_ParameterDecl structure

## Description

Represents CIM method parameters.

## Members

### `flags`

flags

#### MI_FLAG_PROPERTY ((1 << 2))

Indicates structure is a property.

### `code`

Hash code: (name[0] << 16) | (name[len-1] << 8) | len

### `name`

Name of this parameter.

### `qualifiers`

Set of qualifiers for this parameter.

### `numQualifiers`

Number of parameter qualifiers.

### `type`

Type of parameter.

### `className`

Name of reference class or strongly typed embedded instance.

### `subscript`

If the parameter is an array type of a fixed length, this value holds the subscript value.

### `offset`

Offset from the start of the instance of where the value field of this parameter will exist.