## Description

Specifies parameters to [IDMLDevice::CreateBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-createbindingtable) and [IDMLBindingTable::Reset](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmlbindingtable-reset).

## Members

### `Dispatchable`

Type: **[IDMLDispatchable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldispatchable)***

A pointer to an [IDMLDispatchable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldispatchable) interface representing the dispatchable object (an operator initializer, or a compiled operator) for which this binding table will represent the bindings—either an
[IDMLCompiledOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlcompiledoperator) or an [IDMLOperatorInitializer](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmloperatorinitializer). The binding table maintains a strong reference to this
interface pointer. This value may not be null.

### `CPUDescriptorHandle`

Type: **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)**

A valid CPU descriptor handle representing the start of a range into a constant buffer view (CBV)/shader resource view (SRV)/ unordered access view (UAV) descriptor heap into which
DirectML may write descriptors.

### `GPUDescriptorHandle`

Type: **[D3D12_GPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_gpu_descriptor_handle)**

A valid GPU descriptor handle representing the start of a range into a constant buffer view (CBV)/shader resource view (SRV)/ unordered access view (UAV) descriptor heap that DirectML may use to bind resources to the pipeline.

### `SizeInDescriptors`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The size of the binding table, in descriptors. This is the maximum number of descriptors that DirectML is
permitted to write, from the start of both the supplied CPU and GPU descriptor handles. Call
[IDMLDispatchable::GetBindingProperties](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldispatchable-getbindingproperties) to determine the number of descriptors required to execute a
dispatchable object.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)