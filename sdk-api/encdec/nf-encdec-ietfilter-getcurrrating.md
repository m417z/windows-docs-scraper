# IETFilter::GetCurrRating

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetCurrRating** method retrieves the current rating, based on the most recent media sample.

## Parameters

### `pEnSystem` [out]

Receives the rating system, as an [EnTvRat_System](https://learn.microsoft.com/previous-versions/dd375612(v=vs.85)) enumeration type.

### `pEnRating` [out]

Receives the rating level, as an [EnTvRat_GenericLevel](https://learn.microsoft.com/previous-versions/dd375610(v=vs.85)) enumeration type. The meaning of this value depends on the rating system.

### `plbfEnAttr` [out]

Receives a bitwise combination of flags from the [BfEnTvRat_GenericAttributes](https://learn.microsoft.com/previous-versions/dd318226(v=vs.85)) enumeration. The flags specify content attributes, such as violence or adult language. Content attributes do not apply to all rating systems.

## Return value

Returns S_OK if successful, or an error code otherwise.

## See also

[IETFilter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-ietfilter)