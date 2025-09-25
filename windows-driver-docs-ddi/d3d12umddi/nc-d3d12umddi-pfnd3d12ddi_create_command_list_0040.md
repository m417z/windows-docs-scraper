# PFND3D12DDI_CREATE_COMMAND_LIST_0040 callback function

## Description

Pointer to the CreateCommandList function that creates a command list.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_COMMAND_LIST_0040 structure that describes the parameters that the user-mode display driver uses to create a command list.

### `unnamedParam3`

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `unnamedParam4`

A handle to the command list that the driver should use, when it calls back into the Direct3D runtime.

## Return value

Returns an HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_COMMAND_LIST_0040 Pfnd3d12ddiCreateCommandList0040;

// Definition

HRESULT Pfnd3d12ddiCreateCommandList0040
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_COMMAND_LIST_0040 *
	 D3D12DDI_HCOMMANDLIST
	 D3D12DDI_HRTCOMMANDLIST
)
{...}

PFND3D12DDI_CREATE_COMMAND_LIST_0040

```

## Remarks

## See also