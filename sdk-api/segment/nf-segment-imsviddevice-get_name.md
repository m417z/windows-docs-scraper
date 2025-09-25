# IMSVidDevice::get_Name

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Name** method retrieves the friendly name of the device.

## Parameters

### `Name` [out]

Pointer to a variable that receives the friendly name.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | NULL pointer argument. |

## Remarks

The caller must free the returned string, using the **SysFreeString** function.

## See also

[IMSVidDevice Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsviddevice)