# IMSVidVideoRenderer2::get_Allocator_ID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Allocator_ID** method retrieves an identifier for the VMR filter's allocator-presenter.

## Parameters

### `ID` [out]

Receives the identifier. If the returned value is -1, the [MSVidVideoRenderer](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer) object will assign a default identifier when it builds the filter graph.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |

## Remarks

The identifier is for application use; it is not used by the VMR.

## See also

[IMSVidVideoRenderer2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidvideorenderer2)