## Description

Binds a set of resources as output tensors.

If binding for a compiled operator, the number of bindings must exactly match the number of inputs of the operator, including optional tensors. This can be determined from the operator description used to create the operator. If too many or too few bindings are provided, device removal will occur. For optional tensors, you may use [DML_BINDING_TYPE_NONE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_binding_type) to specify 'no binding'. Otherwise, the binding type must match the tensor type when the operator was created.

For operator initializers, the output bindings are the persistent resources of each operator, supplied in the order the operators were given when creating or resetting the initializer. If a particular operator does not require a persistent resource, you should prove an empty binding in that slot.

To unbind all input resources, supply a *rangeCount* of 0, and a value of **nullptr** for *bindings*.

The writable areas of two output tensors must not overlap with one another. The 'writable area' of an output buffer being bound is defined as being the start offset of the buffer range, up to the *TotalTensorSizeInBytes* as specified in the tensors description.

All buffers being bound as output must have heap type [D3D12_HEAP_TYPE_DEFAULT](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type).

## Parameters

### `bindingCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

This parameter determines the size of the *bindings* array (if provided).

### `bindings` [in, optional]

Type: **const [DML_BINDING_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_desc)***

An optional pointer to a constant array of [DML_BINDING_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_desc) containing descriptions of the tensor resources to bind.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)

[IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable)