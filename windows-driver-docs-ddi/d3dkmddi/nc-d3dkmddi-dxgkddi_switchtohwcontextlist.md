# DXGKDDI_SWITCHTOHWCONTEXTLIST callback function

## Description

Clarifies the order of execution of first and second contexts submitted.

## Parameters

### `hAdapter`

A handle to the hardware adapter.

### `pHwContextList`

Pointer to the [DXGKARG_SWITCHTOHWCONTEXTLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_switchtohwcontextlist) structure that represents the hardware context list.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

DXGKDDI_SWITCHTOHWCONTEXTLIST DxgkddiSwitchtohwcontextlist;

// Definition

NTSTATUS DxgkddiSwitchtohwcontextlist
(
	IN_CONST_HANDLE hAdapter
	IN_CONST_PDXGKARG_SWITCHTOHWCONTEXTLIST pHwContextList
)
{...}

```