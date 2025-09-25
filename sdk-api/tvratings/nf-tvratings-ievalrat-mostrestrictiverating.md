# IEvalRat::MostRestrictiveRating

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **MostRestrictiveRating** method compares two ratings and returns the more restrictive of the two.

## Parameters

### `enSystem1` [in]

The rating system of the first rating to compare, specified as a member of the [EnTvRat_System](https://learn.microsoft.com/previous-versions/dd375612(v=vs.85)) enumeration.

### `enEnLevel1` [in]

The rating level of the first rating, specified as a member of the [EnTvRat_GenericLevel](https://learn.microsoft.com/previous-versions/dd375610(v=vs.85)) enumeration.

### `lbfEnAttr1` [in]

Specifies the content attributes of the first rating, as a bitwise combination of flags from the [BfEnTvRat_GenericAttributes](https://learn.microsoft.com/previous-versions/dd318226(v=vs.85)) enumeration.

### `enSystem2` [in]

The rating system of the second rating to compare, specified as a member of the [EnTvRat_System](https://learn.microsoft.com/previous-versions/dd375612(v=vs.85)) enumeration.

### `enEnLevel2` [in]

The rating level of the second rating, specified as a member of the [EnTvRat_GenericLevel](https://learn.microsoft.com/previous-versions/dd375610(v=vs.85)) enumeration.

### `lbfEnAttr2` [in]

Specifies the content attributes of the second rating, as a bitwise combination of flags from the [BfEnTvRat_GenericAttributes](https://learn.microsoft.com/previous-versions/dd318226(v=vs.85)) enumeration.

### `penSystem` [out]

Receives the rating system of the more restrictive rating.

### `penEnLevel` [out]

Receives the rating level of the more restrictive rating.

### `plbfEnAttr` [out]

Receives a bitwise combination of flags from the [BfEnTvRat_GenericAttributes](https://learn.microsoft.com/previous-versions/dd318226(v=vs.85)) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_FALSE** | The ratings are from two different rating systems. |
| **S_OK** | The method succeeded. |

## Remarks

This method enables the client to determine which of two ratings is more restrictive. For example, in the MPAA system, PG is more restrictive than R. The more restrictive rating is returned in the *penSystem*, *penEnLevel*, and *plbfEnAttr* parameters.

When the method compares ratings from two different ratings systems, it returns a rating expressed in the first system, unless the first system is unknown (TvRat_SystemDontKnow). In that case, it returns a rating using the second system.

The method returns S_FALSE if the ratings systems are not the same. There may not be an exact mapping between the two systems.

## See also

[IEvalRat Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nn-tvratings-ievalrat)