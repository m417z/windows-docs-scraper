# CoGetStandardMarshal function

## Description

Creates a default, or standard, marshaling object in either the client process or the server process, depending on the caller, and returns a pointer to that object's [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) implementation.

## Parameters

### `riid` [in]

A reference to the identifier of the interface whose pointer is to be marshaled. This interface must be derived from the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

### `pUnk` [in]

A pointer to the interface to be marshaled.

### `dwDestContext` [in]

The destination context where the specified interface is to be unmarshaled. Values come from the enumeration [MSHCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshctx). Unmarshaling can occur either in another apartment of the current process (MSHCTX_INPROC) or in another process on the same computer as the current process (MSHCTX_LOCAL).

### `pvDestContext` [in, optional]

This parameter is reserved and must be **NULL**.

### `mshlflags` [in]

Indicates whether the data to be marshaled is to be transmitted back to the client process (the normal case) or written to a global table where it can be retrieved by multiple clients. Values come from the [MSHLFLAGS](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshlflags) enumeration.

### `ppMarshal` [out]

The address of **IMarshal*** pointer variable that receives the interface pointer to the standard marshaler.

## Return value

This function can return the standard return values E_FAIL, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) instance was returned successfully. |
| **CO_E_NOTINITIALIZED** | Before this function can be called, the [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) function must be called on the current thread. |

## Remarks

The **CoGetStandardMarshal** function creates a default, or standard, marshaling object in either the client process or the server process, as may be necessary, and returns that object's [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) pointer to the caller. If you implement **IMarshal**, you may want your implementation to call **CoGetStandardMarshal** as a way of delegating to COM's default implementation any destination contexts that you do not fully understand or want to handle. Otherwise, you can ignore this function, which COM calls as part of its internal marshaling procedures.

When the COM library in the client process receives a marshaled interface pointer, it looks for a CLSID to be used in creating a proxy for the purposes of unmarshaling the packet. If the packet does not contain a CLSID for the proxy, COM calls **CoGetStandardMarshal**, passing a **NULL***pUnk* value. This function creates a standard proxy in the client process and returns a pointer to that proxy's implementation of [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal). COM uses this pointer to call [CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface) to retrieve the pointer to the requested interface.

If your OLE server application's implementation of [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) calls **CoGetStandardMarshal**, you should pass both the IID of (*riid*), and a pointer to (*pUnk*), the interface being requested.

This function performs the following tasks:

1. Determines whether pUnk is **NULL**.
2. If *pUnk* is **NULL**, creates a standard interface proxy in the client process for the specified *riid* and returns the proxy's [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) pointer.
3. If *pUnk* is not **NULL**, checks to see if a marshaler for the object already exists, creates a new one if necessary, and returns the marshaler's [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) pointer.

## See also

[IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal)