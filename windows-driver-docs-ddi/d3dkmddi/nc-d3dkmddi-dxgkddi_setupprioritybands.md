# DXGKDDI_SETUPPRIORITYBANDS callback function

## Description

Set up the GPU scheduler priority band configuration, after adapter startup and before scheduling the first GPU work item. This call can be made in the middle of GPU work execution, and the GPU scheduler needs to use the new value during the next yield calculation.

## Parameters

### `hAdapter`

The logical adapter for which the priority band assignment is made.

### `pSetupPriorityBands`

Pointer to a [DXGKARG_SETUPPRIORITYBANDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setupprioritybands) structure that contains information to set up priority bands.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code.

## Prototype

```cpp
//Declaration

DXGKDDI_SETUPPRIORITYBANDS DxgkddiSetupprioritybands;

// Definition

NTSTATUS DxgkddiSetupprioritybands
(
	IN_CONST_HANDLE hAdapter
	IN_CONST_PDXGKARG_SETUPPRIORITYBANDS pSetupPriorityBands
)
{...}

DXGKDDI_SETUPPRIORITYBANDS *PDXGKDDI_SETUPPRIORITYBANDS

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of DXGKARG_SETUPPRIORITYBANDS and then calling DxgkDdiSetupPriorityBands.

## See also