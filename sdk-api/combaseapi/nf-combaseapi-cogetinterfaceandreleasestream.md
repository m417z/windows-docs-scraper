# CoGetInterfaceAndReleaseStream function

## Description

Unmarshals a buffer containing an interface pointer and releases the stream when an interface pointer has been marshaled from another thread to the calling thread.

## Parameters

### `pStm` [in]

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface on the stream to be unmarshaled.

### `iid` [in]

A reference to the identifier of the interface requested from the unmarshaled object.

### `ppv` [out]

The address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppv* contains the requested interface pointer to the unmarshaled interface.

## Return value

This function can return the standard return values S_OK and E_INVALIDARG, as well as any of the values returned by [CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface).

## Remarks

**Important**

Security Note: Calling this method with untrusted data is a security risk. Call this method only with trusted data.

The **CoGetInterfaceAndReleaseStream** function performs the following tasks:

* Calls [CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface) to unmarshal an interface pointer previously passed in a call to [CoMarshalInterThreadInterfaceInStream](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalinterthreadinterfaceinstream).
* Releases the stream pointer. Even if the unmarshaling fails, the stream is still released because there is no effective way to recover from a failure of this kind.

## See also

[CoMarshalInterThreadInterfaceInStream](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalinterthreadinterfaceinstream)

[CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface)