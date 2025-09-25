# PFNDDXGIDDI_SUBMITPRESENTTOHWQUEUECB callback function

## Description

**pfnSubmitPresentToHwQueueCb** submits a Present operation to a hardware queue.

## Parameters

### `hDevice`

A handle to a device.

### `unnamedParam2`

Pointer to a [**DXGIDDICB_SUBMITPRESENTTOHWQUEUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_submitpresenttohwqueue) structure.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFNDDXGIDDI_SUBMITPRESENTTOHWQUEUECB PfnddxgiddiSubmitpresenttohwqueuecb;

// Definition

HRESULT PfnddxgiddiSubmitpresenttohwqueuecb
(
    HANDLE hDevice
    DXGIDDICB_SUBMITPRESENTTOHWQUEUE *
)
{...}

```