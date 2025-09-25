# RPC_PROTSEQ_VECTOR structure

## Description

The
**RPC_PROTSEQ_VECTOR** structure contains a list of protocol sequences the RPC run-time library uses to send and receive remote procedure calls.

## Members

### `Count`

Number of protocol-sequence strings present in the array **Protseq**.

### `Protseq`

Array of pointers to protocol-sequence strings. The number of pointers present is specified by the **Count** member.

## Remarks

The protocol-sequence vector contains a count member (**Count**), followed by an array of pointers to protocol-sequence strings (**Protseq**).

The protocol-sequence vector is a read-only vector. To obtain a protocol-sequence vector, a server application calls
[RpcNetworkInqProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnetworkinqprotseqs). The RPC run-time library allocates memory for the protocol-sequence vector. The server application calls
[RpcProtseqVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcprotseqvectorfree) to free the protocol-sequence vector.

## See also

[RpcNetworkInqProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcnetworkinqprotseqs)

[RpcProtseqVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcprotseqvectorfree)