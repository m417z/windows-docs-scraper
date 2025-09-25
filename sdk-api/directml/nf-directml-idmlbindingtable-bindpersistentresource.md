# IDMLBindingTable::BindPersistentResource

## Description

Binds a buffer as a persistent resource. You can determine the required size of this buffer range by calling [IDMLDispatchable::GetBindingProperties](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldispatchable-getbindingproperties).

If the binding properties for the operator specify a size of zero for the persistent resource, then you may supply **nullptr** to this method (which indicates no resource to bind). Otherwise, a binding of type [DML_BINDING_TYPE_BUFFER](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_binding_type) must be supplied that is at least as large as the required **PersistentResourceSize** returned by [IDMLDispatchable::GetBindingProperties](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldispatchable-getbindingproperties).

Unlike the temporary resource, the persistent resource's contents and lifetime must persist as long as the compiled operator does. That is, if an operator requires a persistent resource, then your application must supply it during initialization and subsequently also supply it to all future executes of the operator without modifying its contents.

The persistent resource is typically used by DirectML to store lookup tables or other long-lived data that is computed during initialization of an operator and reused on future executions of that operator.

As the persistent resource's data is opaque, once initialized it cannot be copied or moved to another buffer.

The persistent resource is only written to during initialization of an operator and is thereafter immutable; all subsequent executions are guaranteed not to write to the persistent resource.

The supplied buffer range to be bound as the persistent buffer must have its start offset aligned to [DML_PERSISTENT_BUFFER_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-directml-constants). The type of the heap underlying the buffer must be [D3D12_HEAP_TYPE_DEFAULT](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_type).

## Parameters

### `binding` [in, optional]

Type: **const [DML_BINDING_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_desc)***

An optional pointer to a [DML_BINDING_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_desc) containing the description of a tensor resource to bind.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)

[IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable)