# MI_FeatureDecl structure

## Description

Contains properties that are common to the [MI_PropertyDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_propertydecl)
[MI_ParameterDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_parameterdecl) and [MI_MethodDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_methoddecl) structures.

## Members

### `flags`

Flags.

### `code`

Hash code: `(name[0] << 16) | (name[len-1] << 8) | len */`

### `name`

Name of this feature.

### `qualifiers`

Describes metadata for classes, properties, methods, and parameters.

### `numQualifiers`

Length of **qualifiers** array.