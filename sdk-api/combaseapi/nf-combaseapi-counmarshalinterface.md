# CoUnmarshalInterface function

## Description

Initializes a newly created proxy using data written into the stream by a previous call to the [CoMarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalinterface) function, and returns an interface pointer to that proxy.

## Parameters

### `pStm` [in]

A pointer to the stream from which the interface is to be unmarshaled.

### `riid` [in]

A reference to the identifier of the interface to be unmarshaled. For **IID_NULL**, the returned interface is the one defined by the stream, objref.iid.

### `ppv` [out]

The address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppv* contains the requested interface pointer for the unmarshaled interface.

## Return value

This function can return the standard return value E_FAIL, errors returned by [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance), and the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The interface pointer was unmarshaled successfully. |
| **STG_E_INVALIDPOINTER** | *pStm* is an invalid pointer. |
| **CO_E_NOTINITIALIZED** | The [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) function was not called on the current thread before this function was called. |
| **CO_E_OBJNOTCONNECTED** | The object application has been disconnected from the remoting system (for example, as a result of a call to the [CoDisconnectObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codisconnectobject) function). |
| **REGDB_E_CLASSNOTREG** | An error occurred reading the registration database. |
| **E_NOINTERFACE** | The final [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) of this function for the requested interface returned E_NOINTERFACE. |

## Remarks

**Important**

Security Note: Calling this method with untrusted data is a security risk. Call this method only with trusted data.

The **CoUnmarshalInterface** function performs the following tasks:

1. Reads from the stream the CLSID to be used to create an instance of the proxy.
2. Gets an [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) pointer to the proxy that is to do the unmarshaling. If the object uses COM's default marshaling implementation, the pointer thus obtained is to an instance of the generic proxy object. If the marshaling is occurring between two threads in the same process, the pointer is to an instance of the in-process free threaded marshaler. If the object provides its own marshaling code, **CoUnmarshalInterface** calls the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function, passing the CLSID it read from the marshaling stream. **CoCreateInstance** creates an instance of the object's proxy and returns an **IMarshal** interface pointer to the proxy.
3. Using whichever IMarshal interface pointer it has acquired, the function then calls [IMarshal::UnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-unmarshalinterface) and, if appropriate, [IMarshal::ReleaseMarshalData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-releasemarshaldata).

The primary caller of this function is COM itself, from within interface proxies or stubs that unmarshal an interface pointer. There are, however, some situations in which you might call **CoUnmarshalInterface**. For example, if you are implementing a stub, your implementation would call **CoUnmarshalInterface** when the stub receives an interface pointer as a parameter in a method call.

## See also

[CoMarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalinterface)

[IMarshal::UnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-unmarshalinterface)