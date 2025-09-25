# IMSVidDevice::get__ClassID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get__ClassID** method retrieves the device's class identifier (CLSID) as a **GUID**.

## Parameters

### `Clsid` [out]

Pointer to a variable of type **GUID** that receives the CLSID.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | NULL pointer argument. |

## See also

[IMSVidDevice Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsviddevice)