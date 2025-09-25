# PFND3D12DDI_UMD_CALLBACK_METHOD callback function

## Description

Used by the user mode driver to complete a context.

## Parameters

### `pContext`

A pointer to the context.

## Prototype

```
//Declaration

PFND3D12DDI_UMD_CALLBACK_METHOD Pfnd3d12ddiUmdCallbackMethod;

// Definition

void Pfnd3d12ddiUmdCallbackMethod
(
	void *pContext
)
{...}

```

## Remarks

## See also