# IMSVidStreamBufferSource::MaxRatingsLevel

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **MaxRatingsLevel** method specifies the maximum ratings level the object is permitted to play.

## Parameters

### `enSystem` [in]

Specifies the rating system, as an [EnTvRat_System](https://learn.microsoft.com/previous-versions/dd375612(v=vs.85)) enumeration value.

### `enRating` [in]

Specifies the maximum rating level, as an [EnTvRat_GenericLevel](https://learn.microsoft.com/previous-versions/dd375610(v=vs.85)) enumeration value.

### `lbfEnAttr` [in]

Specifies zero or more ratings attributes, as a bitwise combination of flags from the [BfEnTvRat_GenericAttributes](https://learn.microsoft.com/previous-versions/dd318226(v=vs.85)) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMSVidStreamBufferSource Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidstreambuffersource)

[TV Ratings Components](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/tv-ratings-components)