# _D3DKMT_GETCONTEXTINPROCESSSCHEDULINGPRIORITY structure

## Description

Describes information that is required for an in-process (in-proc) Microsoft Direct3D composition device to retrieve the scheduling priority for a device context that is in the same process as other device contexts.

## Members

### `hContext` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle to the device context to retrieve scheduling priority for.

### `Priority` [out]

The priority level that is retrieved for the device context relative to other device contexts within the same process.

A value of zero indicates that the context is scheduled with the same priority as other contexts within the same process.

A value of 1 indicates that the context is scheduled ahead of other contexts within the same process.