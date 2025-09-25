# IMSVidXDSEvent::RatingChange

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

**Note**This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 or later.

The **RatingChange** method is called when the current rating changes.

## Parameters

### `PrevRatingSystem` [in]

The previous rating system, as an [EnTvRat_System](https://learn.microsoft.com/previous-versions/dd375612(v=vs.85)) enumeration type.

### `PrevLevel` [in]

The previous rating level, as an [EnTvRat_GenericLevel](https://learn.microsoft.com/previous-versions/dd375610(v=vs.85)) enumeration type. The meaning of this value depends on the rating system.

### `PrevAttributes` [in]

The previous rating attributes. This value is a bitwise OR of flags from the [BfEnTvRat_GenericAttributes](https://learn.microsoft.com/previous-versions/dd318226(v=vs.85)) enumeration. These flags specify content attributes, such as violence or adult language. Content attributes do not apply to all rating systems.

### `NewRatingSystem` [in]

The new rating system, as an **EnTvRat_System** enumeration type.

### `NewLevel` [in]

The new rating level, as an **EnTvRat_GenericLevel** enumeration type.

### `NewAttributes` [in]

Specifies the new rating attributes. This value is a bitwise OR of flags from the **BfEnTvRat_GenericAttributes** enumeration.

## Return value

Return S_OK or an error code.

## See also

[IMSVidXDSEvent Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidxdsevent)