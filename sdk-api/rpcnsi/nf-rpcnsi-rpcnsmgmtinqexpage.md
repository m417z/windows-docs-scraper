# RpcNsMgmtInqExpAge function

## Description

The
**RpcNsMgmtInqExpAge** function returns the global expiration age for local copies of name-service data.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `ExpirationAge`

Pointer to the default expiration age, in seconds. This value is used by all name service next operations.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsMgmtInqExpAge** function returns the expiration age that the application is using. The expiration age is the amount of time in seconds that a local copy of data from a name-service attribute can exist before a request from the application for the attribute requires updating the local copy. When an application begins running, the RPC run-time library specifies a default expiration age of two hours. The default is global to the application.

An expiration age is used by Pointer next operations (which read data from name-service attributes). A next operation typically starts by looking for a local copy of the attribute data being requested by an application. In the absence of a local copy, the next operation creates one with fresh attribute data from the name-service database. If a local copy already exists, the operation compares its actual age to the expiration age being used by the application. If the actual age exceeds the expiration age, the operation automatically tries to update the local copy with fresh attribute data. If updating is impossible, the old local data remains in place and the next operation fails.

Applications typically should use only the default expiration age. For special cases, however, an application can substitute a user-supplied global expiration age for the default by calling
[RpcNsMgmtSetExpAge](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtsetexpage). The
**RpcNsMgmtInqExpAge** function returns the current global expiration age, whether a default or a user-supplied value. An application can also override the global expiration age temporarily by calling the
[RpcNsMgmtHandleSetExpAge](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmthandlesetexpage) function.

## See also

[RpcNsMgmtHandleSetExpAge](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmthandlesetexpage)

[RpcNsMgmtSetExpAge](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtsetexpage)