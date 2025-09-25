# NdrConvert function

## Description

The **NdrConvert** function converts the network buffer from the data representation of the sender to the data representation of the receiver if they are different.

## Parameters

### `pStubMsg` [in]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **pRpcMsg** member points to a structure whose **Buffer** member contains the data to convert. This structure is for internal use only and should not be modified.

### `pFormat` [in]

Pointer to type format of the data to convert.

## Return value

This function has no return values. If an error occurs, the function throws one of the following exception codes.

| Error | Description |
| --- | --- |
| RPC_BAD_STUB_DATA or RPC_X_INVALID_BOUND | The network buffer is incorrect. |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |

## Remarks

The **NdrConvert** function is used by all [/Oi](https://learn.microsoft.com/windows/desktop/Midl/-oi), **/Oic**, and [/Os](https://learn.microsoft.com/windows/desktop/Midl/-os) mode stubs.