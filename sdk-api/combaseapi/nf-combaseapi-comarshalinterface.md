# CoMarshalInterface function

## Description

Writes into a stream the data required to initialize a proxy object in some client process.

## Parameters

### `pStm` [in]

A pointer to the stream to be used during marshaling. See [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

### `riid` [in]

A reference to the identifier of the interface to be marshaled. This interface must be derived from the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

### `pUnk` [in]

A pointer to the interface to be marshaled. This interface must be derived from the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

### `dwDestContext` [in]

The destination context where the specified interface is to be unmarshaled. The possible values come from the enumeration [MSHCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshctx). Currently, unmarshaling can occur in another apartment of the current process (MSHCTX_INPROC), in another process on the same computer as the current process (MSHCTX_LOCAL), or in a process on a different computer (MSHCTX_DIFFERENTMACHINE).

### `pvDestContext` [in, optional]

This parameter is reserved and must be **NULL**.

### `mshlflags` [in]

The flags that specify whether the data to be marshaled is to be transmitted back to the client process (the typical case) or written to a global table, where it can be retrieved by multiple clients. The possible values come from the [MSHLFLAGS](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshlflags) enumeration.

## Return value

This function can return the standard return values E_FAIL, E_OUTOFMEMORY, and E_UNEXPECTED, the stream-access error values returned by [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream), as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The **HRESULT** was marshaled successfully. |
| **CO_E_NOTINITIALIZED** | The [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) function was not called on the current thread before this function was called. |

## Remarks

The **CoMarshalInterface** function marshals the interface referred to by riid on the object whose [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) implementation is pointed to by *pUnk*. To do so, the **CoMarshalInterface** function performs the following tasks:

1. Queries the object for a pointer to the [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) interface. If the object does not implement **IMarshal**, meaning that it relies on COM to provide marshaling support, **CoMarshalInterface** gets a pointer to COM's default implementation of **IMarshal**.
2. Gets the CLSID of the object's proxy by calling [IMarshal::GetUnmarshalClass](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-getunmarshalclass), using whichever [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) interface pointer has been returned.
3. Writes the CLSID of the proxy to the stream to be used for marshaling.
4. Marshals the interface pointer by calling [IMarshal::MarshalInterface](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-marshalinterface).

The COM library in the client process calls the [CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface) function to extract the data and initialize the proxy. Before calling **CoUnmarshalInterface**, seek back to the original position in the stream.

If you are implementing existing COM interfaces or defining your own interfaces using the Microsoft Interface Definition Language (MIDL), the MIDL-generated proxies and stubs call **CoMarshalInterface** for you. If you are writing your own proxies and stubs, your proxy code and stub code should each call **CoMarshalInterface** to correctly marshal interface pointers. Calling [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) directly from your proxy and stub code is not recommended.

If you are writing your own implementation of [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal), and your proxy needs access to a private object, you can include an interface pointer to that object as part of the data you write to the stream. In such situations, if you want to use COM's default marshaling implementation when passing the interface pointer, you can call **CoMarshalInterface** on the object to do so.

## See also

[CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface)

[IMarshal::MarshalInterface](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-marshalinterface)