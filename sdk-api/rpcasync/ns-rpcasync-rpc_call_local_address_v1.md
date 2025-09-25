# RPC_CALL_LOCAL_ADDRESS_V1 structure

## Description

The **RPC_CALL_LOCAL_ADDRESS_V1** structure contains information about the local address on which a call was made.

## Members

### `Version`

Version of the **RPC_CALL_LOCAL_ADDRESS** structure. For this structure, this value must be set to 1.

### `Buffer`

Pointer to a user-supplied opaque data block that contains the local address.

### `BufferSize`

On input, this member contains the size of the buffer pointed to by the **Buffer** member, in bytes. On output, it contains the actual number of bytes written to buffer. For example, if the buffer is allocated a size of 8 bytes, but the local address written to it is 4, this parameter will specify 8 on input and contain 4 on output.

### `AddressFormat`

[RpcLocalAddressFormat](https://learn.microsoft.com/windows/desktop/api/rpcasync/ne-rpcasync-rpclocaladdressformat) enumeration values that specifies the format of the local address written to **Buffer**. For this version of the structure, only IPv4 and IPv6 addresses are supported; if another is specified, RPC_S_CANNOT_SUPPORT is returned.

## See also

[RPC_CALL_ATTRIBUTES_V2](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_call_attributes_v2_a)