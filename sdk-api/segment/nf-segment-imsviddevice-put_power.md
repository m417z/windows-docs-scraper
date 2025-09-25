# IMSVidDevice::put_Power

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Power** method turns the device on or off.

## Parameters

### `Power` [in]

Specifies whether to turn the power on or off. Use one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | Turn the device on. |
| VARIANT_FALSE | Turn the device off. |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

Not all device types implement this method.

## See also

[IMSVidDevice Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsviddevice)

[IMSVidDevice::get_Power](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsviddevice-get_power)