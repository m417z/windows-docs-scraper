# IMSVidOutputDevices::Add

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Add** method adds an output device to the collection.

## Parameters

### `pDB` [in]

Specifies a pointer to the device's [IMSVidOutputDevice](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidoutputdevice) interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_ACCESSDENIED** | The collection is read-only; cannot add any items. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | NULL pointer argument. |

## See also

[IMSVidOutputDevices Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidoutputdevices)

[IMSVidOutputDevices::Remove](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidoutputdevices-remove)