# PFND3DDDI_SUBMITPRESENTBLTTOHWQUEUECB callback function

## Description

Implemented by the client driver to submit a present blt to the hardware queue.

## Parameters

### `hDevice`

A handle to the device.

### `unnamedParam2`

A pointer to the [D3DDDICB_SUBMITPRESENTBLTTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_submitpresentblttohwqueue) structure that holds information on submitting a present blt to the hardware queue.

## Return value

|Return code|Description|
|--|--|
|S_OK|The call was completed successfully.|

This function might also return other HRESULT values.

## Prototype

```cpp
//Declaration

PFND3DDDI_SUBMITPRESENTBLTTOHWQUEUECB Pfnd3dddiSubmitpresentblttohwqueuecb;

// Definition

HRESULT Pfnd3dddiSubmitpresentblttohwqueuecb
(
	HANDLE hDevice
	D3DDDICB_SUBMITPRESENTBLTTOHWQUEUE *
)
{...}

PFND3DDDI_SUBMITPRESENTBLTTOHWQUEUECB

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DDDICB_SUBMITPRESENTBLTTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_submitpresentblttohwqueue) and then calling Pfnd3dddiSubmitpresentblttohwqueuecb.