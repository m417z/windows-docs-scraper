# CoGetMarshalSizeMax function

## Description

Returns an upper bound on the number of bytes needed to marshal the specified interface pointer to the specified object.

## Parameters

### `pulSize` [out]

A pointer to the upper-bound value on the size, in bytes, of the data packet to be written to the marshaling stream. If this parameter is 0, the size of the packet is unknown.

### `riid` [in]

A reference to the identifier of the interface whose pointer is to be marshaled. This interface must be derived from the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

### `pUnk` [in]

A pointer to the interface to be marshaled. This interface must be derived from the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

### `dwDestContext` [in]

The destination context where the specified interface is to be unmarshaled. Values for *dwDestContext* come from the enumeration [MSHCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshctx).

### `pvDestContext` [in, optional]

This parameter is reserved and must be **NULL**.

### `mshlflags` [in]

Indicates whether the data to be marshaled is to be transmitted back to the client process the normal case or written to a global table, where it can be retrieved by multiple clients. Values come from the enumeration [MSHLFLAGS](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshlflags).

## Return value

This function can return the standard return value E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The upper bound was returned successfully. |
| **CO_E_NOTINITIALIZED** | Before this function can be called, either the [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) function must be called. |

## Remarks

This function performs the following tasks:

1. Queries the object for an [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) pointer or, if the object does not implement **IMarshal**, gets a pointer to COM's standard marshaler.
2. Using the pointer obtained in the preceding item, calls [IMarshal::GetMarshalSizeMax](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-getmarshalsizemax).
3. Adds to the value returned by the call to [GetMarshalSizeMax](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-getmarshalsizemax) the size of the marshaling data header and, possibly, that of the proxy CLSID to obtain the maximum size in bytes of the amount of data to be written to the marshaling stream.

You do not explicitly call this function unless you are implementing [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal), in which case your marshaling stub should call this function to get the correct size of the data packet to be marshaled.

The value returned by this method is guaranteed to be valid only as long as the internal state of the object being marshaled does not change. Therefore, the actual marshaling should be done immediately after this function returns, or the stub runs the risk that the object, because of some change in state, might require more memory to marshal than it originally indicated.

## See also

[CoMarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalinterface)

[IMarshal::GetMarshalSizeMax](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-getmarshalsizemax)