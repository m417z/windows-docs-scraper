# PFND3DKMT_RENDER callback function

## Description

The PFND3DKMT_RENDER callback function submits the current command buffer to the Microsoft DirectX graphics kernel subsystem (Dxgkrnl.sys).

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_render) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_RENDER Pfnd3dkmtRender;

// Definition

NTSTATUS Pfnd3dkmtRender
(
	D3DKMT_RENDER *
)
{...}

```

## Remarks

## See also