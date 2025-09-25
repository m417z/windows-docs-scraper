## Description

Specifies a resource binding that is an array of individual buffer bindings.

## Members

### `BindingCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of individual buffer ranges to bind to this slot. This field determines the size of the *Bindings* array.

### `Bindings`

Type: **const [DML_BUFFER_BINDING](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_buffer_binding)***

The individual buffer ranges to bind.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)