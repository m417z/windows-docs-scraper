# IDMLBindingTable::BindTemporaryResource

## Description

Binds a buffer to use as temporary scratch memory. You can determine the required size of this buffer range by calling [IDMLDispatchable::GetBindingProperties](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldispatchable-getbindingproperties).

If the binding properties for the [IDMLDispatchable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldispatchable) specify a size of zero for the temporary resource, then you may
supply **nullptr** to this method (which indicates no resource to bind). Otherwise, a binding of type
[DML_BINDING_TYPE_BUFFER](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_binding_type) must be supplied that is at least as large as the required **TemporaryResourceSize**
returned by [IDMLDispatchable::GetBindingProperties](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldispatchable-getbindingproperties).

The temporary resource is typically used as scratch memory during execution of an operator. The contents
of a temporary resource need not be defined prior to execution. For example, DirectML doesn't require that
you zero the contents of the temporary resource prior to binding or executing an operator.

You don't need to preserve the contents of the temporary buffer, and your application is free to overwrite or
reuse its contents as soon as execution of an operator or initializer completes on the GPU. This is in contrast
to a persistent resource, whose contents must be preserved and lifetime extended for the lifetime of the
operator.

The supplied buffer range to be bound as the temporary buffer must have its start offset aligned to
[DML_TEMPORARY_BUFFER_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-directml-constants). The type of the heap underlying the buffer must be [D3D12_HEAP_TYPE_DEFAULT](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type).

## Parameters

### `binding` [in, optional]

Type: **const [DML_BINDING_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_desc)***

An optional pointer to a [DML_BINDING_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_desc) containing the description of a tensor resource to bind.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)

[IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable)