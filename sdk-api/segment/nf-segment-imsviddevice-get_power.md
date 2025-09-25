# IMSVidDevice::get_Power

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Power** method queries whether the device is off or on.

## Parameters

### `Power` [out]

Pointer to a variable that receives one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | The device is on. |
| VARIANT_FALSE | The device is off. |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Not implemented. |
| **E_POINTER** | NULL pointer argument. |

## Remarks

Not all device types implement this method.

## See also

[IMSVidDevice Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsviddevice)

[IMSVidDevice::put_Power](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsviddevice-put_power)