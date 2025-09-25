# NdrContextHandleMemorySize function

## Description

The **NdrContextHandleMemorySize** function returns the size of the supplied RPC context handle as represented in local memory.

## Parameters

### `pStubMsg`

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that contains the current status of the RPC stub. The **BufferLength** member contains the size of the context handle, in bytes. Structure is for internal use only; do not modify.

### `pFormat`

Pointer to a **FORMAT_STRING** structure that contains the format of the context handle specified in *pMemory*.

## Return value

Returns the size of the context handle in memory, in bytes.

## See also

[NdrContextHandleSize](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-ndrcontexthandlesize)