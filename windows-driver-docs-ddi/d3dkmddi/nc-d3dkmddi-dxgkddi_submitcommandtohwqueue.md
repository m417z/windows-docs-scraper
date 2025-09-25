# DXGKDDI_SUBMITCOMMANDTOHWQUEUE callback function

## Description

Invoked by the DirectX graphics kernel to append a DMA (direct memory access) buffer to a GPU visible hardware queue.

## Parameters

### `hAdapter`

A handle to the adapter.

### `pSubmitCommandToHwQueue`

Pointer to a [DXGKARG_SUBMITCOMMANDTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_submitcommandtohwqueue) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

DXGKDDI_SUBMITCOMMANDTOHWQUEUE DxgkddiSubmitcommandtohwqueue;

// Definition

NTSTATUS DxgkddiSubmitcommandtohwqueue
(
	IN_CONST_HANDLE hAdapter
	IN_CONST_PDXGKARG_SUBMITCOMMANDTOHWQUEUE pSubmitCommandToHwQueue
)
{...}

```

## Remarks

This call is the first part of a two step submission process.

WDDM synchronization class: [Zero Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level), no reentrancy within the same hardware queue

## See also