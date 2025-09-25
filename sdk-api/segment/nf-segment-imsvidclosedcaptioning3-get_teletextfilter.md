# IMSVidClosedCaptioning3::get_TeleTextFilter

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **get_TeleTextFilter** method retrieves the filter that handles teletext.

## Parameters

### `punkTTFilter` [out]

Pointer to a variable that receives a reference to the teletext filter.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | Success. |

## See also

[IMSVidClosedCaptioning3 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidclosedcaptioning3)