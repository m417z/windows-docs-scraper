# RpcNsMgmtSetExpAge function

## Description

The
**RpcNsMgmtSetExpAge** function modifies the application's global expiration age for local copies of name-service data.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `ExpirationAge`

Pointer to the default expiration age, in seconds. This value is used by all name service–next operations. An expiration age of 0 causes an immediate update of the local name-service data.

To reset the expiration age to an RPC-assigned default value of two hours, specify a value of RPC_C_NS_DEFAULT_EXP_AGE.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsMgmtSetExpAge** function modifies the global expiration age of an application. The expiration age is the amount of time that a local copy of data from a name-service attribute can exist before a request from the application for the attribute requires updating the local copy. When an application begins running, the RPC run-time library specifies a default expiration age of two hours. The default is global to the application. Typically, you should avoid using
**RpcNsMgmtSetExpAge**. Instead, you should rely on the default expiration age.

An expiration age is used by Pointer next operations (which read data from name-service attributes). A next operation typically starts by looking for a local copy of the attribute data being requested by an application. In the absence of a local copy, the next operation creates one with fresh attribute data from the name-service database. If a local copy already exists, the operation compares its actual age to the expiration age being used by the application. If the actual age exceeds the expiration age, the operation automatically tries to update the local copy with fresh attribute data. If updating is impossible, the old local data remains in place and the next operation fails, returning the RPC_S_NAME_SERVICE_UNAVAILABLE status code.

Setting the expiration age to a small value causes the Pointer next operations to frequently update local data for any name-service attribute requested by your application. For example, setting the expiration age to 0 forces all next operations to update local data for the name-service attribute requested by your application. Therefore, setting small expiration ages can create performance problems for your application and increase network traffic. Furthermore, if your application is using a remote name-service server, a small expiration age can adversely affect network performance for all applications.

## See also

[RpcNsMgmtHandleSetExpAge](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmthandlesetexpage)