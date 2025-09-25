# _D3DKMT_CHECKSHAREDRESOURCEACCESS structure

## Description

The D3DKMT_CHECKSHAREDRESOURCEACCESS structure describes parameters that the [D3DKMTCheckSharedResourceAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtchecksharedresourceaccess) function uses to determine if a process can access a shared resource.

## Members

### `hResource` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the shared resource to check.

### `ClientPid` [in]

A UINT value that represents the process identifier (PID) for the client process that requires access to the shared resource that the **hProcess** member specifies.

## See also

[D3DKMTCheckSharedResourceAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtchecksharedresourceaccess)