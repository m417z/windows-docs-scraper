# RpcHttpProxyFreeString function

## Description

The **RpcHttpProxyFreeString** function is used as a callback to the Redirector DLL to free the resources associated with a new server string. This is called after the RPC Proxy has completed the connection to the RPC server and it is used to free the resources associated with a *NewServerName* or *NewServerPort*.

## Parameters

*String* \[in\]

The string for which the resource should be freed.

## Remarks

This function is defined by RPC and must be implemented by a redirector DLL. If a redirector DLL fails to implement both the [RpcNewHttpProxyChannel](https://learn.microsoft.com/windows/win32/rpc/rpc-new-http-proxy-channel) function and the **RpcHttpProxyFreeString** function, the Redirector DLL will be immediately unloaded and will not be called.

## Requirements

| Requirement | Value |
|-------------|-------|
| Minimum supported client | Windows Vista [desktop apps \| UWP apps] |
| Minimum supported server | Windows Server 2003 [desktop apps \| UWP apps] |
| Target Platform | Windows |
| Header | rpcdce.h (include Rpc.h) |
| Library | Rpcrt4.lib |
| DLL | Rpcrt4.dll |

## See also

- [RpcNewHttpProxyChannel](https://learn.microsoft.com/windows/win32/rpc/rpc-new-http-proxy-channel)
- [RPC_HTTP_REDIRECTOR_STAGE](https://learn.microsoft.com/windows/win32/rpc/rpc-http-redirector-stage)
- [RPC Functions](https://learn.microsoft.com/windows/win32/rpc/rpc-functions)