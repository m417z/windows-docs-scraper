## Description

Contains information about the binding requirements of a particular compiled operator, or operator initializer. This struct is retrieved from [IDMLDispatchable::GetBindingProperties](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldispatchable-getbindingproperties).

## Members

### `RequiredDescriptorCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The minimum size, in descriptors, of the binding table required for a particular dispatchable object (an operator initializer, or a compiled operator).

### `TemporaryResourceSize`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The minimum size in bytes of the temporary resource that must be bound to the binding table for a particular dispatchable
object. A value of zero means that a temporary resource is not required.

### `PersistentResourceSize`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The minimum size in bytes of the persistent resource that must be bound to the binding table for a particular
dispatchable object. Persistent resources must be supplied during initialization of a compiled operator (where it
is bound as an output of the operator initializer) as well as during execution. A value of zero means that a
persistent resource is not required. Only compiled operators have persistent resources—operator initializers
always return a value of 0 for this member.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)