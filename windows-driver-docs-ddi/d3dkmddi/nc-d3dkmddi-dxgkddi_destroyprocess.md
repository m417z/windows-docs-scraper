# DXGKDDI_DESTROYPROCESS callback function

## Description

**DxgkDdiDestroyProcess** destroys a kernel mode driver process object.

## Parameters

### `hAdapter`

A handle to the display adapter.

### `hKmdProcess`

A handle to the kernel mode driver process.

## Return value

 Returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes defined in **Ntstatus.h**.