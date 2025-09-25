# RpcNsMgmtHandleSetExpAge function

## Description

The
**RpcNsMgmtHandleSetExpAge** function sets the expiration age of a name-service handle for local copies of name-service data.

**Note** This function is not supported on Windows Vista and later operating systems.

## Parameters

### `NsHandle`

Name-service handle for which an expiration age is set. A name-service handle is returned from a name service begin operation.

### `ExpirationAge`

Integer value, in seconds, that sets the expiration age of local name-service data read by all next routines using the specified *NsHandle* parameter.

An expiration age of 0 causes an immediate update of the local name-service data.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NAME_SERVICE_UNAVAILABLE** | The name service is unavailable. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcNsMgmtHandleSetExpAge** function sets a handle-expiration age for a specified name–service handle (*NsHandle*). The expiration age is the amount of time that a local copy of data from a name-service attribute can exist before a request from the application for the attribute requires updating the local copy. When an application begins running, the RPC run-time library specifies a default expiration age of two hours. The default is global to the application. A handle-expiration age applies only to a specific name-service handle and temporarily overrides the current global expiration age.

A handle-expiration age is used exclusively by Pointer next operations (which read data from name-service attributes). A next operation typically starts by looking for a local copy of the attribute data being requested by an application. In the absence of a local copy, the next operation creates one with fresh attribute data from the name-service database. If a local copy already exists, the operation compares its actual age to the expiration age being used by the application (which, in this case, is the expiration age set for the name-service handle). If the actual age exceeds the handle-expiration age, the operation automatically tries to update the local copy with fresh attribute data. If updating is impossible, the old local data remains in place and the next operation fails, returning the RPC_S_NAME_SERVICE_UNAVAILABLE status code.

The scope of a handle-expiration age is a single series of next operations. The
**RpcNsMgmtHandleSetExpAge** function operates within the following context:

* A begin operation creates a name-service handle.
* A call to the
  **RpcNsMgmtHandleSetExpAge** function creates an expiration age for the handle.
* A series of next operations for the name-service handle uses the handle expiration age.
* A done operation for the name-service handle deletes both the handle and its expiration age.

**Note** Typically, you should avoid using
**RpcNsMgmtHandleSetExpAge**. Instead, you should rely on the application's global expiration age. Setting the handle-expiration age to a small value causes the name service next operations to frequently update local data for any name-service attribute requested by your application. For example, setting the expiration age to 0 forces the next operation to update local data for the name-service attribute requested by your application. Therefore, setting a small handle-expiration age can create performance problems for your application. Furthermore, if your application is using a remote name-service server, a small expiration age can adversely affect network performance for all applications.

Limit use of
**RpcNsMgmtHandleSetExpAge** to the following situations:

* When you must always get accurate name-service data.

  For example, during management operations to update a profile, you may need to always see the profile's current contents. In this case, before beginning to inquire about a profile, your application should call the
  **RpcNsMgmtHandleSetExpAge** function and specify 0 for the *ExpirationAge* parameter.
* When a request using the default expiration age has failed, and your application needs to retry the operation.

  For example, a client application using name service import operations should first try to obtain bindings using the application's default expiration age. However, sometimes the import-next operation returns either no binding handles or an insufficient number of them. In this case, the client could retry the import operation and, after the
  [RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina) call, include an
  **RpcNsMgmtHandleSetExpAge** call and specify 0 for the *ExpirationAge* parameter. When the client calls the import-next function again, the small handle-expiration age causes the import-next operation to update the local attribute data.

## See also

[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina)

[RpcNsMgmtInqExpAge](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtinqexpage)

[RpcNsMgmtSetExpAge](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsmgmtsetexpage)