# CoGetObjectContext function

## Description

Returns the context for the current object.

## Parameters

### `riid` [in]

A reference to the ID of an interface that is implemented on the context object.

For objects running within COM applications, IID_IComThreadingInfo, IID_IContext, and IID_IContextCallback are available.

For objects running within COM+ applications, IID_IObjectContext, IID_IObjectContextActivity IID_IObjectContextInfo, and IID_IContextState are available.

### `ppv` [out]

The address of a pointer to the interface specified by *riid* on the context object.

## Return value

This function can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The object context was successfully retrieved. |
| **E_NOINTERFACE** | The requested interface was not available. |
| **CO_E_NOTINITIALIZED** | Before this function can be called, the [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) function must be called on the current thread. |

## Remarks

**CoGetObjectContext** retrieves the context for the object from which it is called, and returns a pointer to an interface that can be used to manipulate context properties. Context properties are used to provide services to configured components running within COM+ applications.

For components running within COM applications, the following interfaces are supported for accessing context properties: [IComThreadingInfo](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icomthreadinginfo), [IContext](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icontext), and [IContextCallback](https://learn.microsoft.com/windows/desktop/api/ctxtcall/nn-ctxtcall-icontextcallback).

For components running within COM+ applications, the following interfaces are supported for accessing context properties: [IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext), [IObjectContextActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontextactivity), [IObjectContextInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontextinfo), and [IContextState](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icontextstate).

## See also

[Contexts and Threading Models](https://learn.microsoft.com/windows/desktop/cossdk/com--contexts-and-threading-models)