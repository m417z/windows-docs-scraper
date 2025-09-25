## Description

Contains the description of a binding so that you can add it to the binding table via a call to one of the [IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable) methods.

 A binding can refer to an input or an output tensor resource, or to a persistent or a temporary resource, and there are methods on [IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable) to bind each kind. The type of the structure pointed to by *Desc* depends on the value of *Type*.

## Members

### `Type`

Type: [**DML_BINDING_TYPE**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_binding_type)

A [DML_BINDING_TYPE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_binding_type) specifying the type of the binding; whether it refers to a single buffer, or to an array of buffers.

### `Desc`

Type: **const void***

A pointer to a constant structure whose type depends on the value *Type*. If *Type* is [DML_BINDING_TYPE_BUFFER](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_binding_type), then *Desc* should point to a [DML_BUFFER_BINDING](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_buffer_binding). If *Type* is [DML_BINDING_TYPE_BUFFER_ARRAY](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_binding_type), then *Desc* should point to a [DML_BUFFER_ARRAY_BINDING](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_buffer_array_binding).

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)

[IDMLBindingTable::BindInputs](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmlbindingtable-bindinputs)

[IDMLBindingTable::BindOutputs](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmlbindingtable-bindoutputs)

[IDMLBindingTable::BindPersistentResource](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmlbindingtable-bindpersistentresource)

[IDMLBindingTable::BindTemporaryResource](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmlbindingtable-bindtemporaryresource)