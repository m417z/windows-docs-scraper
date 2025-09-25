# IMSVidClosedCaptioning2::get_Service

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Service** method retrieves the current closed captioning service.

## Parameters

### `On` [out]

Pointer to a variable that receives a member of the [MSVidCCService](https://learn.microsoft.com/windows/desktop/api/segment/ne-segment-msvidccservice) enumeration.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | Success. |

## See also

[IMSVidClosedCaptioning2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidclosedcaptioning2)