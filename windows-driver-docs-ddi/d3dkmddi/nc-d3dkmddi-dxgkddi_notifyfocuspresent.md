# DXGKDDI_NOTIFYFOCUSPRESENT callback function

## Description

Notifies the GPU scheduler of a particular Present N, and the GPU scheduler will in turn perform the yield check on all GPU nodes and run a yield algorithm if necessary.

## Parameters

### `hAdapter`

The logical adapter for which a new focus Present has completed. The GPU scheduler will in turn notify all individual GPU engine schedulers of the new present.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code.

## Prototype

```cpp
//Declaration

DXGKDDI_NOTIFYFOCUSPRESENT DxgkddiNotifyfocuspresent;

// Definition

NTSTATUS DxgkddiNotifyfocuspresent
(
	IN_CONST_HANDLE hAdapter
)
{...}

DXGKDDI_NOTIFYFOCUSPRESENT *PDXGKDDI_NOTIFYFOCUSPRESENT

```