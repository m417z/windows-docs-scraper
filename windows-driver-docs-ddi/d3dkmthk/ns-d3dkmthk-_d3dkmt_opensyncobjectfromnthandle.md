# _D3DKMT_OPENSYNCOBJECTFROMNTHANDLE structure

## Description

Describes information that is required to map an NT process handle to a graphics processing unit (GPU) synchronization object.

## Members

### `hNtHandle` [in]

An NT handle to the process.

### `hSyncObject` [out]

A handle of type **D3DKMT_HANDLE** that represents a kernel-mode handle to the kernel-mode synchronization object.