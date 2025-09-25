# RPC_IF_ID_VECTOR structure

## Description

The
**RPC_IF_ID_VECTOR** structure contains a list of interfaces offered by a server.

## Members

### `Count`

Number of interface-identification structures present in the array **IfHandl**.

### `IfId`

#### - IfHandl

Array of pointers to interface-identification structures that contains **Count** elements.

## Remarks

The interface identification vector contains a count member (**Count**), followed by an array of pointers to interface identifiers (
[RPC_IF_ID](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_if_id)).

The interface identification vector is a read-only vector. To obtain a vector of the interface identifiers registered by a server with the run-time library, an application calls
[RpcMgmtInqIfIds](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqifids). To obtain a vector of the interface identifiers exported by a server, an application calls
[RpcNsMgmtEntryInqIfIds](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtentryinqifidsa).

The RPC run-time library allocates memory for the interface identification vector. The application calls
[RpcIfIdVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcifidvectorfree) to free the interface identification vector.

## See also

[RpcIfIdVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcifidvectorfree)

[RpcMgmtInqIfIds](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtinqifids)

[RpcNsMgmtEntryInqIfIds](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtentryinqifidsa)