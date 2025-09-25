# IMarshal::ReleaseMarshalData

## Description

Destroys a marshaled data packet.

## Parameters

### `pStm` [in]

A pointer to a stream that contains the data packet to be destroyed.

## Return value

This method can return the standard return values S_OK and E_FAIL, as well as any of the stream-access errors for the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface.

## Remarks

If an object's marshaled data packet does not get unmarshaled in the client process space and the packet is no longer needed, the client calls **ReleaseMarshalData** on the proxy's [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) implementation to instruct the object to destroy the data packet. The call occurs within the [CoReleaseMarshalData](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreleasemarshaldata) function. The data packet serves as an additional reference on the object, and releasing the data is like releasing an interface pointer by calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

If the marshaled data packet somehow does not arrive in the client process or if **ReleaseMarshalData** is not successfully re-created in the proxy, COM can call this method on the object itself.

### Notes to Callers

You will rarely if ever have occasion to call this method yourself. A possible exception would be if you were to implement [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) on a class factory for a class object on which you are also implementing **IMarshal**. In this case, if you were marshaling the object to a table where it could be retrieved by multiple clients, you might, as part of your unmarshaling routine, call **ReleaseMarshalData** to release the data packet for each proxy.

### Notes to Implementers

If your implementation stores state information about marshaled data packets, you can use this method to release the state information associated with the data packet represented by *pStm*. Your implementation should also position the seek pointer in the stream past the last byte of data.

## See also

[CoReleaseMarshalData](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreleasemarshaldata)

[IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal)