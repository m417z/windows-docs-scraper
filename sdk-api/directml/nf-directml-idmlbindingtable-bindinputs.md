## Description

Binds a set of resources as input tensors.

If binding for a compiled operator, the number of bindings must exactly match the number of inputs of the operator, including optional tensors. This can be determined from the operator description used to create the operator. If too many or too few bindings are provided, device removal will occur. For optional tensors, you may use [DML_BINDING_TYPE_NONE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_binding_type) to specify 'no binding'. Otherwise, the binding type must match the tensor type when the operator was created.

For operator initializers, input bindings are expected to be of type [DML_BINDING_TYPE_BUFFER_ARRAY](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_binding_type) with one input binding per operator to initialize, supplied in the order that you specified the operators during creation or reset of the initializer. Each buffer array should have a size equal to the number of inputs of its corresponding operator to initialize. Input tensors that had the [DML_TENSOR_FLAG_OWNED_BY_DML](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_flags) flag set should be bound during initialize—otherwise, nothing should be bound for that tensor. If there is nothing to be bound as input for initialization of an operator (that is, there are no tensors with the [DML_TENSOR_FLAG_OWNED_BY_DML](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_flags) flag set) then you may supply `nullptr` or an empty [DML_BUFFER_ARRAY_BINDING](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_buffer_array_binding) to indicate 'no binding'.

To unbind all input resources, supply a *rangeCount* of 0, and a value of `nullptr` for *bindings*.

If an input tensor has the [DML_TENSOR_FLAG_OWNED_BY_DML](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_flags) flag set, it may only be bound when executing an operator initializer. Otherwise, if the [DML_TENSOR_FLAG_OWNED_BY_DML](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_flags) flag is not set, the opposite is true—the input tensor must not be bound when executing the initializer, but must be bound when executing the operator itself.

All buffers being bound as input must have heap type [D3D12_HEAP_TYPE_DEFAULT](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type), except when the [DML_TENSOR_FLAG_OWNED_BY_DML](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_flags) flag is set. If the [DML_TENSOR_FLAG_OWNED_BY_DML](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_flags) is set for a tensor that is being bound as input for an initializer, the buffer's heap type may be either [D3D12_HEAP_TYPE_DEFAULT](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type) or [D3D12_HEAP_TYPE_UPLOAD](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type).

Multiple bindings are permitted to reference the same [**ID3D12Resource**](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) in some cases; however, you should take care when an operator simultaneously reads and writes to the same region of a resource. A potential binding hazard exists when: a pair of bindings reference the same **ID3D12Resource**, and at least one of the bindings is involved in writing, and the buffer regions intersect (overlap by at least one byte). Binding hazards are validated using the following rules, as of DirectML 1.7.0:

- When binding for initialization, an input binding can never reference the same resource as the output binding—inputs are copied into the output resource (the future persistent resource for execution), and copying might require a resource state transition.
- When binding for execution, an input binding may reference the same resource as an output binding; however, the respective binding ranges can intersect only if the regions are identical *and* the operator supports in-place execution.
- If present, a persistent binding must not intersect with any output binding or temporary binding.
- If present, a temporary binding must not intersect any input binding, output binding, or persistent binding.

The above rules assume that two resources don't alias the same region of a heap, so extra caution is required when using placed or reserved resources.

## Parameters

### `bindingCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

This parameter determines the size of the *bindings* array (if provided).

### `bindings` [in, optional]

Type: **const [DML_BINDING_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_desc)\***

An optional pointer to a constant array of [DML_BINDING_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_desc) containing descriptions of the tensor resources to bind.

## Remarks

### Binding hazard examples

In the examples below, the rectangles represent a buffer resource referenced by at least one binding in a binding table. Each row indicates the range of bytes potentially read (R) or written (W) by the named binding. All examples assume that resources don't share the same physical memory.

#### Example 1

This example shows an input and output binding referencing different resources. A pair of bindings that reference different resources is never a hazard, so this is always a valid binding.

```
          Resource A          Resource B
          +---------------+   +---------------+
Input  0: |RRRRRRRRRRRRRRR|   |               |
Output 0: |               |   |WWWWWWWWWWWWWWW|
          +---------------+   +---------------+
```

#### Example 2

This example shows an input and output binding referencing different regions of the same resource. A pair of bindings with non-overlapping regions of the same resource is not a hazard when binding for execution. This is a valid binding when binding for execution, but it's invalid when binding for initialization.

```
          Resource A
          +---------------+
Input  0: |RRRRRRR        |
Output 0: |       WWWWWWWW|
          +---------------+
```

#### Example 3

This example shows two inputs bindings that overlap ranges. A pair of read-only bindings (input bindings and persistent bindings) can never be a hazard, regardless of any buffer-region intersection, so this is always a valid binding.

```
          Resource A          Resource B
          +---------------+   +---------------+
Input  0: |RRRRRRRRR      |   |               |
Input  1: |      RRRRRRRRR|   |               |
Output 0: |               |   |WWWWWWWWWWWWWWW|
          +---------------+   +---------------+
```

#### Example 4

This example shows an input and output binding with identical regions. This binding is valid if and only if the operator being bound supports in-place execution and the binding is for execution.

```
          Resource A
          +---------------+
Input  0: |RRRRRRRRRRRRRRR|
Output 0: |WWWWWWWWWWWWWWW|
          +---------------+
```

#### Example 5

The following binding is never valid, regardless of the operator's in-place execution support, because it involves a pair of bindings with overlapping regions that are not identical.

```
          Resource A
          +---------------+
Input  0: |RRRRRRRRRRRRR  |
Output 0: |    WWWWWWWWWWW|
          +---------------+
```

## Requirements

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)

[IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable)