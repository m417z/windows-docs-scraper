# IMSVidDevice::get_Category

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Category** method retrieves the category of the device as a **BSTR**.

## Parameters

### `Guid` [out]

**BSTR** that receives the device category.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | NULL pointer argument. |

## Remarks

The device category is identified by a **GUID**. This method returns a string representation of the **GUID**.

This method is provided for Automation clients. C++ applications can use the [IMSVidDevice::get__Category](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsviddevice-get__category) method, which returns a **GUID** rather than a **BSTR**.

The caller must free the returned string, using the **SysFreeString** function.

## See also

[IMSVidDevice Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsviddevice)