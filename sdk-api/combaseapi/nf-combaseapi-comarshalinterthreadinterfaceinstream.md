# CoMarshalInterThreadInterfaceInStream function

## Description

Marshals an interface pointer from one thread to another thread in the same process.

## Parameters

### `riid` [in]

A reference to the identifier of the interface to be marshaled.

### `pUnk` [in]

A pointer to the interface to be marshaled, which must be derived from [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown). This parameter can be **NULL**.

### `ppStm` [out]

The address of the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)* pointer variable that receives the interface pointer to the stream that contains the marshaled interface.

## Return value

This function can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

The **CoMarshalInterThreadInterfaceInStream** function enables an object to easily and reliably marshal an interface pointer to another thread in the same process. The stream returned in the *ppStm* parameter is guaranteed to behave correctly when a client running in the receiving thread attempts to unmarshal the pointer. The client can then call the [CoGetInterfaceAndReleaseStream](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetinterfaceandreleasestream) to unmarshal the interface pointer and release the stream object.

The **CoMarshalInterThreadInterfaceInStream** function performs the following tasks:

1. Creates a stream object.
2. Passes the stream object's IStream pointer to [CoMarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalinterface).
3. Returns the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer to the caller.

## See also

[CoGetInterfaceAndReleaseStream](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetinterfaceandreleasestream)