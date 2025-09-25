# RPC_C_OPT_COOKIE_AUTH_DESCRIPTOR structure

## Description

The **RPC_C_OPT_COOKIE_AUTH_DESCRIPTOR** structure contains a cookie that is inserted into the header of RPC/HTTP traffic. This cookie can be used for authentication or for load balancing. When used for authentication, [RPC_S_COOKIE_AUTH_FAILED](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes--1700-3999-) is returned from an RPC call if cookie authentication fails. There are no specific error messages when used for load balancing.

## Members

### `BufferSize`

The length, in bytes, of **Buffer**.

### `Buffer`

A null-terminated string that contains the cookie.

## Remarks

A pointer to this structure is passed as the OptionValue when making a call to [RpcBindingSetOption](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetoption) with [RPC_C_OPT_COOKIE_AUTH](https://learn.microsoft.com/windows/desktop/Rpc/binding-option-constants) as the option.