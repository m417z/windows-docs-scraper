# RPC_IF_CALLBACK_FN callback function

## Description

The
**RPC_IF_CALLBACK_FN** is a prototype for a security-callback function that your application supplies. Your program can provide a callback function for each interface it defines.

## Parameters

### `InterfaceUuid`

### `Context` [in]

Pointer to an RPC_IF_ID server binding handle representing the client. In the function declaration, this must be of type RPC_IF_HANDLE, but it is a client binding handle and can be safely cast to it. The callback function may pass this handle to
[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient),
[RpcBindingServerFromClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingserverfromclient), [RpcGetAuthorizationContextForClient](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcgetauthorizationcontextforclient), or any other server side function that accepts a client binding handle to obtain information about the client.

#### - Interface [in]

UUID and version of the interface.

## Return value

The callback function should return RPC_S_OK if the client is allowed to call methods in this interface. Any other return code will cause the client to receive the exception RPC_S_ACCESS_DENIED.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

In some cases, the RPC run time may call the security-callback function more than once per client per interface. Be sure your callback function can handle this possibility.

The security callback must be declared as RPC_ENTRY.

## See also

[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex)