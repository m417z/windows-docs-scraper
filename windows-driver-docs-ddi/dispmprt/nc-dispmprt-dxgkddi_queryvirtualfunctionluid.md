# DXGKDDI_QUERYVIRTUALFUNCTIONLUID callback function

## Description

Queries for a virtual function's locally unique identifier.

## Parameters

### `Context`

A handle to the context.

### `pArgs`

Pointer to a DXGKARG_QUERYVIRTUALFUNCTIONLUID structure.

## Prototype

```
//Declaration

DXGKDDI_QUERYVIRTUALFUNCTIONLUID DxgkddiQueryvirtualfunctionluid;

// Definition

VOID DxgkddiQueryvirtualfunctionluid
(
	HANDLE Context
	DXGKARG_QUERYVIRTUALFUNCTIONLUID * pArgs
)
{...}

```

## Remarks

## See also