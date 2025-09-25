# IMSVidInputDevice::IsViewable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **IsViewable** method determines whether this device can view the specified tune request.

Currently this method is not implemented by any of the supported input devices.

## Parameters

### `v` [in]

Specifies the tune request as a **VARIANT** type.

### `pfViewable` [out]

Pointer to variable that receives one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | The device can view this tune request. |
| VARIANT_FALSE | The device cannot view this tune request. |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Not implemented. |
| **E_POINTER** | NULL pointer argument. |

## See also

[IMSVidInputDevice Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidinputdevice)