# PFND3D12DDI_RESETCOMMANDLIST_0040 callback function

## Description

Implemented by the client driver to reset a command list back to its initial state as if a new command list was just created.

## Parameters

### `unnamedParam1`

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `unnamedParam2`

A pointer to the D3D12DDIARG_RESETCOMMANDLIST_0040 structure that contains arguments to reset the command list.

## Prototype

```cpp
//Declaration

PFND3D12DDI_RESETCOMMANDLIST_0040 Pfnd3d12ddiResetcommandlist0040;

// Definition

VOID Pfnd3d12ddiResetcommandlist0040
(
	 D3D12DDI_HCOMMANDLIST
	CONST D3D12DDIARG_RESETCOMMANDLIST_0040 *
)
{...}

PFND3D12DDI_RESETCOMMANDLIST_0040

```

## See also