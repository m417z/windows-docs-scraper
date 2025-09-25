# PFND3DDDI_WAITFORSYNCHRONIZATIONOBJECTFROMCPUCB callback function

## Description

The **pfnWaitForSynchronizationObjectFromCpuCb** callback waits for a monitored fence to reach a certain value before processing subsequent context commands.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

Pointer to a [**D3DDDICB_WAITFORSYNCHRONIZATIONOBJECTFROMCPU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_waitforsynchronizationobjectfromcpu) structure that provides the details of the requested operation.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.