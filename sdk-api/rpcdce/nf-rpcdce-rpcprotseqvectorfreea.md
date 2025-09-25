# RpcProtseqVectorFreeA function

## Description

The
**RpcProtseqVectorFree** function frees the protocol sequences contained in the vector and the vector itself.

## Parameters

### `ProtseqVector`

Pointer to a pointer to a vector of protocol sequences. On return, the pointer is set to NULL.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server calls
**RpcProtseqVectorFree** to release the memory used to store a vector of protocol sequences and the individual protocol sequences.
**RpcProtseqVectorFree** sets the *ProtSeqVector* parameter to a null value.

For a list of Microsoft RPC supported protocol sequences, see
[String Binding](https://learn.microsoft.com/windows/desktop/Rpc/string-binding).

A server obtains a vector of protocol sequences by calling
[RpcNetworkInqProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnetworkinqprotseqs).

**Note** **RpcProtseqVectorFree** is available for server and client applications using Microsoft RPC, but is more common and convenient for server applications.

> [!NOTE]
> The rpcdce.h header defines RpcProtseqVectorFree as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNetworkInqProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnetworkinqprotseqs)