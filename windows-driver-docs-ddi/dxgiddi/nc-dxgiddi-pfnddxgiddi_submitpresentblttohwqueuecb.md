# PFNDDXGIDDI_SUBMITPRESENTBLTTOHWQUEUECB callback function

## Description

The **PFNDDXGIDDI_SUBMITPRESENTBLTTOHWQUEUECB** callback function is implemented by a graphics client driver to submit a present Blt to the hardware queue.

## Parameters

### `hDevice`

A handle to the device.

### `unnamedParam2`

Pointer to a [**DXGIDDICB_SUBMITPRESENTBLTTOHWQUEUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_submitpresentblttohwqueue) structure that contains information to submit a present Blt to hardware queue.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code.

## Prototype

```cpp
//Declaration

PFNDDXGIDDI_SUBMITPRESENTBLTTOHWQUEUECB PfnddxgiddiSubmitpresentblttohwqueuecb;

// Definition

HRESULT PfnddxgiddiSubmitpresentblttohwqueuecb
(
    HANDLE hDevice
    DXGIDDICB_SUBMITPRESENTBLTTOHWQUEUE *
)
{...}

PFNDDXGIDDI_SUBMITPRESENTBLTTOHWQUEUECB

```