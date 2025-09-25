# IMSVidDevice::get_ClassID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_ClassID** method retrieves the device's class identifier (CLSID) as a **BSTR**.

## Parameters

### `Clsid` [out]

Pointer to a variable that receives a string representation of the CLSID.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | NULL pointer argument. |

## Remarks

This method is provided for Automation clients. C++ applications can use the [IMSVidDevice::get__ClassID](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsviddevice-get__classid) method, which returns a **GUID** rather than a **BSTR**.

The caller must free the returned string, using the **SysFreeString** function.

## See also

[IMSVidDevice Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsviddevice)