# IMSVidInputDevices::Add

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Add** method adds an input device to the collection.

## Parameters

### `pDB` [in]

Pointer to the device's [IMSVidInputDevice](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidinputdevice) interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_ACCESSDENIED** | This collection is read-only; cannot add any items. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | NULL pointer argument. |

## See also

[IMSVidInputDevices Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidinputdevices)

[IMSVidInputDevices::Remove](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidinputdevices-remove)