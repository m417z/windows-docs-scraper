# PFND3DKMT_SUBMITPRESENTTOHWQUEUE callback function

## Description

pfnSubmitPresentToHwQueueCb is invoked by user mode drivers to submit a Blt Present operation to a hardware queue. This callback replaces [pfnPresentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentcb) in WDDM 2.0-2.3.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SUBMITPRESENTTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitpresenttohwqueue) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SUBMITPRESENTTOHWQUEUE Pfnd3dkmtSubmitpresenttohwqueue;

// Definition

NTSTATUS Pfnd3dkmtSubmitpresenttohwqueue
(
	CONST D3DKMT_SUBMITPRESENTTOHWQUEUE *
)
{...}

```

## Remarks

## See also