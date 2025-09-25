# NdrContextHandleSize function

## Description

The **NdrContextHandleSize** function returns the size of the supplied RPC context handle.

## Parameters

### `pStubMsg`

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that contains the current status of the RPC stub. The **BufferLength** member contains the size of the context handle, in bytes. Structure is for internal use only; do not modify.

### `pMemory`

Pointer to a string buffer that contains an RPC context handle.

### `pFormat`

Pointer to a **FORMAT_STRING** structure that contains the format of the context handle specified in *pMemory*.

## See also

[NdrContextHandleMemorySize](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-ndrcontexthandlememorysize)