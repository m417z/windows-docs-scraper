# RPC_HTTP_REDIRECTOR_STAGE enumeration

## Description

The **RPC_HTTP_REDIRECTOR_STAGE** enumeration is used to identify the current stage at which the redirector implementation is being called. If a redirector implementation does not recognize or wish to process a stage, it must return **RPC_S_OK** with the exception of the interface stage. If a redirector implementation does not wish to process the interface stage, it must return **RPC_S_UNKNOWN_IF**.

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
- [RpcHttpProxyFreeString](https://learn.microsoft.com/windows/win32/rpc/rpc-http-proxy-free-string)
- [RPC Enumerated Types](https://learn.microsoft.com/windows/win32/rpc/rpc-enumerated-types)