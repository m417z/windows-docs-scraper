# NdrClientCall2 function

## Description

The **NdrClientCall2** function is the client-side entry point for the [/Oicf](https://learn.microsoft.com/windows/desktop/Midl/-oi) mode stub.

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

## Remarks

The **NdrClientCall2** function is used by all [/Oicf](https://learn.microsoft.com/windows/desktop/Midl/-oi) mode client-side stubs. The **NdrClientCall2** function transmits all [in] data to the remote server, and upon receipt of the response packet, returns the [out] value to the client-side application.