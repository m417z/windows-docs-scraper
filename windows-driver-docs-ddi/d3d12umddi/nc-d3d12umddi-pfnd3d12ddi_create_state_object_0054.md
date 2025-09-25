# PFND3D12DDI_CREATE_STATE_OBJECT_0054 callback function

## Description

UMD's **PFND3D12DDI_CREATE_STATE_OBJECT_0054** function creates a state object.

## Parameters

### `unnamedParam1`

[in] Handle to the device on which the state object is being created. It represents the GPU device on which all Direct3D 12 operations are performed.

### `unnamedParam2`

[in] Pointer to a [**D3D12DDIARG_CREATE_STATE_OBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_state_object_0054) structure that describes the state object to create.

### `unnamedParam3`

[out] A **D3D12DDI_HSTATEOBJECT_0054** handle to the newly created state object returned by the function. This handle is used by the driver to reference the state object in subsequent operations.

### `unnamedParam4`

[in] Handle to a runtime (RT) state object. The runtime uses this handle to reference the state object in its own operations.

## Return value

**PFND3D12DDI_CREATE_STATE_OBJECT_0054** returns S_OK for success; otherwise it returns an appropriate error code.

## Remarks

A state object represents a variable amount of configuration state, including shaders, that an application manages as a single unit and which is given to a driver atomically to process (for example, to compile and optimize) however it sees fit. State objects are built out of subobjects. A [subobject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_state_subobject_0054) has a type and corresponding data.

## See also

[**D3D12DDIARG_CREATE_STATE_OBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_state_object_0054)