# UUID_VECTOR structure

## Description

The
**UUID_VECTOR** structure contains a list of [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid)s.

## Members

### `Count`

Number of [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid)s present in the array **Uuid**.

### `Uuid`

Array of pointers to [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid)s that contains **Count** elements.

## Remarks

The [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) vector contains a count member containing the total number of **UUID**s in the vector, followed by an array of pointers to **UUID**s.

An application constructs a [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) vector to contain object **UUID**s to be exported or unexported from the name service.

## See also

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace)

[RpcEpUnregister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepunregister)

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)

[RpcNsBindingUnexport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingunexporta)