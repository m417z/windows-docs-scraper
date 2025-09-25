# ISBE2MediaTypeProfile::DeleteStream

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Removes a stream from a media type profile.

## Parameters

### `Index` [in]

The index of the stream to remove. To get the number of the streams in the profile, call the [ISBE2MediaTypeProfile::GetStreamCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2mediatypeprofile-getstreamcount) method.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****E_INVALIDARG**** | Invalid parameter. |

## See also

[ISBE2MediaTypeProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2mediatypeprofile)