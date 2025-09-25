# RpcNetworkIsProtseqValidW function

## Description

The
**RpcNetworkIsProtseqValid** function tells whether the specified protocol sequence is supported by both the RPC run-time library and the operating system. Server applications often use
[RpcNetworkInqProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnetworkinqprotseqs).

## Parameters

### `Protseq`

Pointer to a string identifier of the protocol sequence to be checked.

If the *Protseq* parameter is not a valid protocol sequence string,
**RpcNetworkIsProtseqValid** returns RPC_S_INVALID_RPC_PROTSEQ.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded.; protocol sequence supported |
| **RPC_S_PROTSEQ_NOT_SUPPORTED** | Protocol sequence not supported on this host. |
| **RPC_S_INVALID_RPC_PROTSEQ** | Invalid protocol sequence. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

An application calls the
**RpcNetworkIsProtseqValid** function to determine whether an individual protocol sequence is available for making remote procedure calls.

A protocol sequence is valid if both the RPC run-time library and the operating system support the specified protocols. For a list of Microsoft RPC's supported protocol sequences, see
[String Binding](https://learn.microsoft.com/windows/desktop/Rpc/string-binding). An application calls
[RpcNetworkInqProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnetworkinqprotseqs) to see all of the supported protocol sequences.

> [!NOTE]
> The rpcdce.h header defines RpcNetworkIsProtseqValid as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcNetworkInqProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnetworkinqprotseqs)