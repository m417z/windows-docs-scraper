# IMSVidOutputDevices::get__NewEnum

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get__NewEnum** method retrieves an enumerator for the collection.

## Parameters

### `pD` [out]

Pointer to a variable that receives an **IEnumVARIANT** interface pointer.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | NULL pointer argument. |

## Remarks

This method is provided so that Automation clients can iterate through the collection using a `For...Each` loop.

The returned **IEnumVARIANT** interface is not thread safe, because it is intended primarily for use by Automation clients. Clients should not call methods on the interface from more than one thread. (C++ applications should generally use the [IMSVidOutputDevices::get_Item](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidoutputdevices-get_item) method instead.)

If the method succeeds, the **IEnumVARIANT** interface has an outstanding reference count. The caller must release the interface.

## See also

[IMSVidOutputDevices Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidoutputdevices)