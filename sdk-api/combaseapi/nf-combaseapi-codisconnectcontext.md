# CoDisconnectContext function

## Description

Disconnects all proxy connections that are being maintained on behalf of all interface pointers that point to objects in the current context.

This function blocks connections until all objects are successfully disconnected or the time-out expires. Only the context that actually manages the objects should call **CoDisconnectContext**.

## Parameters

### `dwTimeout` [in]

The time in milliseconds after which **CoDisconnectContext** returns even if the proxy connections for all objects have not been disconnected. INFINITE is an acceptable value for this parameter.

## Return value

This function can return the standard return values E_FAIL, E_INVALIDARG, and E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The proxy connections for all objects were successfully disconnected. |
| **RPC_E_TIMEOUT** | Not all proxy connections were successfully deleted in the time specified in *dwTimeout*. |
| **CO_E_NOTSUPPORTED** | The current context cannot be disconnected. |
| **CONTEXT_E_WOULD_DEADLOCK** | An object tried to call [CoDisconnectContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codisconnectcontext) on the context it is residing in. This would cause the function to time-out and deadlock if *dwTimeout* were set to INFINITE. |

## Remarks

The **CoDisconnectContext** function is used to support unloading services in shared service hosts where you must unload your service's binaries without affecting other COM servers that are running in the same process. If you control the process lifetime and you do not unload until the process exits, the COM infrastructure will perform the necessary cleanup automatically and you do not have to call this function.

The **CoDisconnectContext** function enables a server to correctly disconnect all external clients of all objects in the current context. Default contexts cannot be disconnected. To use **CoDisconnectContext**, you must first create a context that can be disconnected and register your class factories for objects from which you want to disconnect within that context. You can do this with the [IContextCallback](https://learn.microsoft.com/windows/desktop/api/ctxtcall/nn-ctxtcall-icontextcallback) interface.

If **CoDisconnectContext** returns RPC_E_TIMEOUT, this does not indicate that the function did not disconnect the objects, but that not all disconnections could be completed in the time specified by *dwTimeout* because of outstanding calls on the objects. All objects will be disconnected after all calls on them have been completed.

It is not safe to unload the DLL that hosts the service until **CoDisconnectContext** returns S_OK. If the function returns RPC_E_TIMEOUT, the service may perform other clean-up. The service must call the function until it returns S_OK, and then it can safely unload its DLL.

The **CoDisconnectContext** function performs the following tasks:

* Calls [CoDisconnectObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codisconnectobject) on all objects in the current context.
* Blocks until all objects have been disconnected or the time-out has expired.

The **CoDisconnectContext** function has the following limitations:

* Asynchronous COM calls are not supported.
* In-process objects must be registered and enabled using the CLSCTX_LOCAL_SERVER flag, or they will not be disconnected.
* COM+ is not supported.
* COM interface pointers are context-sensitive. Therefore, any interface pointer created in the context to be disconnected can only be used within that context.

#### Examples

```cpp
IContextCallback *icc;
hr = CoCreateInstance(CLSID_ContextSwitcher, NULL, CLSCTX_INPROC_SERVER, IID_IContextCallback, (void**)&icc);

icc->ContextCallback(EnterCallback, NULL, IID_IContextCallback, 5, NULL);

HRESULT __stdcall EnterCallback(ComCallData *pv)
{
    return CoRegisterClassObject(...);
}

/* All objects created by the class factories registered in the callback will be put into the newly created context.
To disconnect, re-enter the context, revoke the class factories, and call CoDisconnectContext. */

icc->ContextCallback(DisconnectCallback, NULL, IID_IContextCallback, 5, NULL);

HRESULT __stdcall DisconnectCallback(ComCallData *pv)
{
    CoRevokeClassObject(...);
    return CoDisconnectContext(timeout);
}

```

## See also

[CoDisconnectObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codisconnectobject)

[IContextCallback](https://learn.microsoft.com/windows/desktop/api/ctxtcall/nn-ctxtcall-icontextcallback)