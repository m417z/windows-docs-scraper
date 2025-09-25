# MI_MethodDecl structure

## Description

Represents a CIM method.

## Members

### `flags`

Flags:

#### MI_FLAG_METHOD

#### MI_FLAG_STATIC

### `code`

Hash code: `(name[0] << 16) | (name[len-1] << 8) | len`

### `name`

The method name.

### `qualifiers`

The qualifiers of the method.

### `_MI_Qualifier`

### `numQualifiers`

The number of qualifiers.

### `parameters`

The parameters of the method.

### `_MI_ParameterDecl`

### `numParameters`

The number of parameters.

### `size`

The size of the structure.

### `returnType`

The post result type of this method.

### `origin`

The ancestor class that first defined a method with this name.

### `propagator`

The ancestor class that last defined a method with this name.

### `schema`

The schema this class belongs to.

### `_MI_SchemaDecl`

### `function`

The extrinsic function that implements this method.

## See also

[MI_FeatureDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_featuredecl)

[MI_MethodDecl_Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn792321(v=vs.85))

[MI_ParameterDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_parameterdecl)

[MI_Qualifier](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_qualifier)

[MI_SchemaDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_schemadecl)