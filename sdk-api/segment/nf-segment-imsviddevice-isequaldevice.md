# IMSVidDevice::IsEqualDevice

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **IsEqualDevice** method queries whether this device and another device represent the same underlying hardware.

## Parameters

### `Device` [in]

Pointer to the other device's [IMSVidDevice](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsviddevice) interface.

### `IsEqual` [out]

Pointer to a variable that receives one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | The two devices represent the same underlying hardware. |
| VARIANT_FALSE | The two devices do not represent the same hardware. |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success; returned VARIANT_TRUE. |
| **S_FALSE** | Success; returned VARIANT_FALSE. |
| **E_POINTER** | NULL pointer argument. |
| **E_UNEXPECTED** | Unexpected error occurred. |

## See also

[IMSVidDevice Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsviddevice)