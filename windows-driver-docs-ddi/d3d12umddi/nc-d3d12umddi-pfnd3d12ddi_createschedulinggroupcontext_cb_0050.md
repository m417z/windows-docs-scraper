# PFND3D12DDI_CREATESCHEDULINGGROUPCONTEXT_CB_0050 callback function

## Description

Creates a context associated with a scheduling group.

## Parameters

### `hRTSchedulingGroup`

A D3D12DDI_HRTSCHEDULINGGROUP_0050 runtime handle type that represents the contexts associated with a hardware scheduling group.

### `unnamedParam2`

Pointer to a [D3DDDICB_CREATECONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createcontext) structure that contains information needed to create a context.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATESCHEDULINGGROUPCONTEXT_CB_0050 Pfnd3d12ddiCreateschedulinggroupcontextCb0050;

// Definition

HRESULT Pfnd3d12ddiCreateschedulinggroupcontextCb0050
(
	D3D12DDI_HRTSCHEDULINGGROUP_0050 hRTSchedulingGroup
	D3DDDICB_CREATECONTEXT *
)
{...}

```

## Remarks

Destroys are not provided for these objects, as their lifetime is completely managed by the owning runtime object.
Validation will be in place that hardware queue creation must be done against a context either associated with the same command queue, or with a parent scheduling group. The driver is allowed to create hardware queues which reference both types of contexts for a single [CreateCommandQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createcommandqueue_0050). The CreateCommandQueue callback is reviewed so the driver is informed of this relationship.

## See also