# IDMLCommandRecorder::RecordDispatch

## Description

Records execution of a dispatchable object (an operator initializer, or a compiled operator) onto a command
list.

This method doesn't submit the execution to the GPU; it merely records it onto the command list. You are responsible for closing the command list and submitting it to the Direct3D 12 command queue.

Prior to execution of this call on the GPU, all resources bound must be in the [D3D12_RESOURCE_STATE_UNORDERED_ACCESS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states) state, or a
state implicitly promotable to **D3D12_RESOURCE_STATE_UNORDERED_ACCESS**, such as **D3D12_RESOURCE_STATE_COMMON**. After this call completes, the resources
remain in the **D3D12_RESOURCE_STATE_UNORDERED_ACCESS** state. The only exception to this is for upload heaps bound when executing an
operator initializer and while one or more tensors has the [DML_TENSOR_FLAG_OWNED_BY_DML](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_flags) flag set. In that case, any
upload heaps bound for input must be in the **D3D12_RESOURCE_STATE_GENERIC_READ** state and will remain in that state, as required by
all upload heaps.

This method resets the following state on the command list.

* Compute root signature
* Pipeline state

No other command list state is modified.

Although this method takes a binding table representing the resources to bind to the pipeline, it doesn't
set the descriptor heaps containing the descriptors themselves. Therefore, your application is responsible for
calling [ID3D12GraphicsCommandList::SetDescriptorHeaps](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-setdescriptorheaps) to bind the correct descriptor heaps to the pipeline.

If [DML_EXECUTION_FLAG_DESCRIPTORS_VOLATILE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_execution_flags) was not set when compiling the operator, then all bindings must
be set on the binding table before **RecordDispatch** is called, otherwise the behavior is undefined. Otherwise,
if the **_DESCRIPTORS_VOLATILE** flag is set, binding of resources may be deferred until the Direct3D 12 command list is
submitted to the command queue for execution.

This method acts logically like a call to [ID3D12GraphicsCommandList::Dispatch](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-dispatch). As such, unordered access view (UAV) barriers are
necessary to ensure correct ordering if there are data dependencies between dispatches. This method does not
insert UAV barriers on input nor output resources. Your application must ensure that the correct UAV barriers
are performed on any inputs if their contents depend on an upstream dispatch, and on any outputs if there are
downstream dispatches that depend on those outputs.

This method doesn't hold references to any of the interfaces passed in. It is your responsibility to
ensure that the [IDMLDispatchable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldispatchable) object is not released until all dispatches using it have completed execution
on the GPU.

## Parameters

### `commandList`

Type: **[ID3D12CommandList](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandlist)***

A pointer to an [ID3D12CommandList](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandlist) interface representing the command list to record the execution into. The command list must be open and must have type
[D3D12_COMMAND_LIST_TYPE_DIRECT](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_command_list_type) or **D3D12_COMMAND_LIST_TYPE_COMPUTE**.

### `dispatchable`

Type: **[IDMLDispatchable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldispatchable)***

A pointer to an [IDMLDispatchable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldispatchable) interface representing the object (an operator initializer, or a compiled operator) whose execution will be recorded into the command list.

### `bindings`

Type: **[IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable)***

A pointer to an [IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable) interface representing the bindings to use for executing the dispatchable object. If the [DML_EXECUTION_FLAG_DESCRIPTORS_VOLATILE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_execution_flags)
flag was not set, then you must fill out all required bindings, otherwise an error will result.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)

[IDMLCommandRecorder](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlcommandrecorder)