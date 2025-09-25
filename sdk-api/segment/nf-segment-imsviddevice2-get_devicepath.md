# IMSVidDevice2::get_DevicePath

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 or later.

The **get_DevicePath** method retrieves the device path.

## Parameters

### `DevPath` [out]

Pointer to a **BSTR** that receives the device path. The caller must free the returned string, using the **SysFreeString** function.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This property is not a human-readable string, but is guaranteed to be unique per device. You can use this property to distinguish between two or more instances of the same model of device.

## See also

[IMSVidDevice2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsviddevice2)