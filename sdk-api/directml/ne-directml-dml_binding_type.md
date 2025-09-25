## Description

Defines constants that specify the nature of the resource(s) referred to by a binding description (a [DML_BINDING_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_desc) structure).

## Constants

### `DML_BINDING_TYPE_NONE`

Indicates that no resources are to be bound.

### `DML_BINDING_TYPE_BUFFER`

Specifies a binding that binds a single buffer to the binding table. The corresponding binding desc type is [DML_BUFFER_BINDING](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_buffer_binding).

### `DML_BINDING_TYPE_BUFFER_ARRAY`

Specifies a binding that binds an array of buffers to the binding table. The corresponding binding desc type is [DML_BUFFER_ARRAY_BINDING](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_buffer_array_binding).

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding), [DML_BINDING_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_desc)