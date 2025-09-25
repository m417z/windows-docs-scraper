# PFND3D12DDI_CREATEHWQUEUE_CB_0050 callback function

## Description

Creates a hardware queue associated with a command queue.

## Parameters

### `hRTCommandQueue`

The handle of the command queue for the driver to use when it calls back into the runtime.

### `unnamedParam2`

Pointer to a [D3DDDICB_CREATEHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createhwqueue) structure that contains information needed to create a hardware queue.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATEHWQUEUE_CB_0050 Pfnd3d12ddiCreatehwqueueCb0050;

// Definition

HRESULT Pfnd3d12ddiCreatehwqueueCb0050
(
	D3D12DDI_HRTCOMMANDQUEUE hRTCommandQueue
	D3DDDICB_CREATEHWQUEUE *
)
{...}

```

## Remarks

Destroys are not provided for these objects, as their lifetime is completely managed by the owning runtime object.
Validation will be in place that hardware queue creation must be done against a context either associated with the same command queue, or with a parent scheduling group. The driver is allowed to create hardware queues which reference both types of contexts for a single [CreateCommandQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createcommandqueue_0050). The CreateCommandQueue callback is reviewed so the driver is informed of this relationship.

## See also