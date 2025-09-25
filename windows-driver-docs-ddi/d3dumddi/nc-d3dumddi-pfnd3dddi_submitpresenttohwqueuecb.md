# PFND3DDDI_SUBMITPRESENTTOHWQUEUECB callback function

## Description

pfnSubmitPresentToHwQueueCb is invoked by user mode drivers to submit a Blt Present operation to a hardware queue.

## Parameters

### `hDevice`

A handle to a device.

### `unnamedParam2`

Pointer to a [D3DDDICB_SUBMITPRESENTTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_submitpresenttohwqueue) structure.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3DDDI_SUBMITPRESENTTOHWQUEUECB Pfnd3dddiSubmitpresenttohwqueuecb;

// Definition

HRESULT Pfnd3dddiSubmitpresenttohwqueuecb
(
	HANDLE hDevice
	D3DDDICB_SUBMITPRESENTTOHWQUEUE *
)
{...}

```

## Remarks

## See also