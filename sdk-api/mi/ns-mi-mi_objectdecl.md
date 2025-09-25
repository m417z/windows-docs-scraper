# MI_ObjectDecl structure

## Description

Contains properties common to the [MI_ClassDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_classdecl) and [MI_PropertyDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_propertydecl) structures. It can be used to write functions
that work on the common fields of these two types.

## Members

### `flags`

Flags.

### `code`

Hash code.

### `name`

Name of this feature.

### `qualifiers`

Describes metadata for classes and properties.

### `numQualifiers`

Length of **qualifiers** array.

### `properties`

The properties of this object.

### `_MI_PropertyDecl`

### `numProperties`

The number of properties of this object.

### `size`

Size of the structure.

## See also

[MI_ClassDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_classdecl)

[MI_FeatureDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_featuredecl)

[MI_PropertyDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_propertydecl)

[MI_Qualifier](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_qualifier)