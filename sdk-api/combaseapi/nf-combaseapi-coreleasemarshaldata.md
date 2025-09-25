# CoReleaseMarshalData function

## Description

Destroys a previously marshaled data packet.

## Parameters

### `pStm` [in]

A pointer to the stream that contains the data packet to be destroyed. See [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Return value

This function can return the standard return values E_FAIL, E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The data packet was successfully destroyed. |
| **STG_E_INVALIDPOINTER** | An error related to the *pStm* parameter. |
| **CO_E_NOTINITIALIZED** | The [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) function was not called on the current thread before this function was called. |

## Remarks

**Important**

Security Note: Calling this method with untrusted data is a security risk. Call this method only with trusted data.

The **CoReleaseMarshalData** function performs the following tasks:

1. The function reads a CLSID from the stream.
2. If COM's default marshaling implementation is being used, the function gets an [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) pointer to an instance of the standard unmarshaler. If custom marshaling is being used, the function creates a proxy by calling the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function, passing the CLSID it read from the stream, and requests an **IMarshal** interface pointer to the newly created proxy.
3. Using whichever [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) interface pointer it has acquired, the function calls [IMarshal::ReleaseMarshalData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-releasemarshaldata).

You typically do not call this function. The only situation in which you might need to call this function is if you use custom marshaling (write and use your own implementation of [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal)). Examples of when **CoReleaseMarshalData** should be called include the following situations:

* An attempt was made to unmarshal the data packet, but it failed.
* A marshaled data packet was removed from a global table.

As an analogy, the data packet can be thought of as a reference to the original object, just as if it were another interface pointer being held on the object. Like a real interface pointer, that data packet must be released at some point. The use of [IMarshal::ReleaseMarshalData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-releasemarshaldata) to release data packets is analogous to the use of [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release interface pointers.

Note that you do not need to call **CoReleaseMarshalData** after a successful call of the [CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface) function; that function releases the marshal data as part of the processing that it does.

**Important** You must call the **CoReleaseMarshalData** function in the same apartment that called [CoMarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalinterface) to marshal the object into the stream. Failure to do this may cause the object reference held by the marshaled packet in the stream to be leaked.

## See also

[IMarshal::ReleaseMarshalData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imarshal-releasemarshaldata)