# PFND3D12DDI_CREATESCHEDULINGGROUPCONTEXTVIRTUAL_CB_0050 callback function

## Description

Creates a virtual context associated with a scheduling group.

## Parameters

### `hRTSchedulingGroup`

A D3D12DDI_HRTSCHEDULINGGROUP_0050 runtime handle type that represents the contexts associated with a hardware scheduling group.

### `unnamedParam2`

A pointer to a [D3DDDICB_CREATECONTEXTVIRTUAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createcontextvirtual) structure that describes the context to create.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATESCHEDULINGGROUPCONTEXTVIRTUAL_CB_0050 Pfnd3d12ddiCreateschedulinggroupcontextvirtualCb0050;

// Definition

HRESULT Pfnd3d12ddiCreateschedulinggroupcontextvirtualCb0050
(
	D3D12DDI_HRTSCHEDULINGGROUP_0050 hRTSchedulingGroup
	D3DDDICB_CREATECONTEXTVIRTUAL *
)
{...}

```

## Remarks

This callback should be used with contexts that support virtual addressing.

## See also