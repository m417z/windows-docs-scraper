# NdrContextHandleInitialize function

## Description

The **NdrContextHandleInitialize** function initializes a new RPC context handle.

## Parameters

### `pStubMsg`

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that contains the current status of the RPC stub. Structure is for internal use only; do not modify.

### `pFormat`

Pointer to a **FORMAT_STRING** structure that contains the format of the new context handle.

## Return value

Returns a NDR_SCONTEXT structure that provides a newly initialized context on return or raises exception upon error.