# RpcNetworkInqProtseqs function

## Description

The
**RpcNetworkInqProtseqs** function returns all protocol sequences supported by both the RPC run-time library and the operating system. Client applications often use
[RpcNetworkIsProtseqValid](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnetworkisprotseqvalid). For a list of Microsoft RPC's supported protocol sequences, see
[String Binding](https://learn.microsoft.com/windows/desktop/Rpc/string-binding).

## Parameters

### `ProtseqVector`

Returns a pointer to a pointer to a protocol sequence vector.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NO_PROTSEQS** | No supported protocol sequences. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application calls the
**RpcNetworkInqProtseqs** function to obtain a vector containing the protocol sequences supported by both the RPC run-time library and the operating system. If there are no supported protocol sequences, this function returns the RPC_S_NO_PROTSEQS status code and a *ProtSeqVector* parameter value of **NULL**.

The server is responsible for calling the
[RpcProtseqVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcprotseqvectorfree) function to release the memory used by the vector.

## See also

[RpcNetworkIsProtseqValid](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnetworkisprotseqvalid)