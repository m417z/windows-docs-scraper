# NdrAsyncClientCall function

## Description

The **NdrAsyncClientCall** function is the asynchronous client-side entry point for the [/Oi](https://learn.microsoft.com/windows/desktop/Midl/-oi) and **/Oic** mode stub.

## Parameters

### `pStubDescriptor` [in]

Pointer to the MIDL-generated [MIDL_STUB_DESC](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_desc) structure that contains information about the description of the remote interface.

### `pFormat` [in]

Pointer to the MIDL-generated procedure format string that describes the method and parameters.

### `...`

Pointer to the client-side calling stack.

## Return value

Return value of the remote call. The maximum size of a return value is equivalent to the register size of the system. MIDL switches to the [/Os](https://learn.microsoft.com/windows/desktop/Midl/-os) mode stub if the return value size is larger than the register size.

Depending on the method definition, this function can throw an exception if there is a network or server failure.