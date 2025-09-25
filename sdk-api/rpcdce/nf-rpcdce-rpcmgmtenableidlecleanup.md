# RpcMgmtEnableIdleCleanup function

## Description

The
**RpcMgmtEnableIdleCleanup** function enables RPC to close idle resources, such as network connections, on the client.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_OUT_OF_THREADS** | Out of threads. |
| **RPC_S_OUT_OF_RESOURCES** | Out of resources. |
| **RPC_S_OUT_OF_MEMORY** | Out of memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**Note** **RpcMgmtEnableIdleCleanup** is a Microsoft extension to the OSF-DCE RPC specification.

Calling this function only is sufficient. Once called, idle resource cleanup cannot be turned off. In some cases, depending on Windows version and configuration, RPC Runtime may need to create a separate thread in order to perform such cleanup, which is why idle resource cleanup is not always turned on. On Windows XP and later versions of Windows, RPC Runtime is programmed to automatically turn on idle resource cleanup if idle resources reach a certain threshold.

## See also

[RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif)