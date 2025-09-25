# IMarshal::UnmarshalInterface

## Description

Unmarshals an interface pointer.

## Parameters

### `pStm` [in]

A pointer to the stream from which the interface pointer is to be unmarshaled.

### `riid` [in]

A reference to the identifier of the interface to be unmarshaled.

### `ppv` [out]

The address of pointer variable that receives the interface pointer. Upon successful return, **ppv* contains the requested interface pointer of the interface to be unmarshaled.

## Return value

This method can return the standard return value E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The interface pointer was unmarshaled successfully. |
| **E_NOINTERFACE** | The specified interface is not supported. |

## Remarks

The COM library in the process where unmarshaling is to occur calls the proxy's implementation of this method.

### Notes to Callers

You do not call this method directly. There are, however, some situations in which you might call it indirectly through a call to [CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface). For example, if you are implementing a stub, your implementation would call **CoUnmarshalInterface** when the stub receives an interface pointer as a parameter in a method call.

### Notes to Implementers

The proxy's implementation should read the data written to the stream by the original object's implementation of [IMarshal::MarshalInterface](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-marshalinterface) and use that data to initialize the proxy object whose CLSID was returned by the marshaling stub's call to the original object's implementation of [IMarshal::GetUnmarshalClass](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-getunmarshalclass).

To return the appropriate interface pointer, the proxy implementation can simply call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on itself, passing the *riid* and *ppv* parameters. However, your implementation of **UnmarshalInterface** is free to create a different object and, if necessary, return a pointer to it.

Just before exiting, even if exiting with an error, your implementation should reposition the seek pointer in the stream immediately after the last byte of data read.

## See also

[CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface)

[IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal)