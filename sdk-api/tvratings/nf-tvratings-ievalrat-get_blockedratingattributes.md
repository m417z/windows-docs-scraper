# IEvalRat::get_BlockedRatingAttributes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_BlockedRatingAttributes** method determines whether content is blocked for a given rating system and rating level.

## Parameters

### `enSystem` [in]

Specifies the rating system, as an [EnTvRat_System](https://learn.microsoft.com/previous-versions/dd375612(v=vs.85)) enumeration type.

### `enLevel` [in]

Specifies the rating level, as an [EnTvRat_GenericLevel](https://learn.microsoft.com/previous-versions/dd375610(v=vs.85)) enumeration type. The meaning of this value depends on the rating system.

### `plbfAttrs` [out, retval]

[out, retval] Receives a bitwise combination of flags from the [BfEnTvRat_GenericAttributes](https://learn.microsoft.com/previous-versions/dd318226(v=vs.85)) enumeration. The flags indicate whether the overall rating is blocked, or specific attributes within the rating are blocked.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## Remarks

If the **BfIsBlocked** flag is set, all content with the specified rating level will be blocked. If one of the **BfIsAttr_X** flags is set, any content with that rating level and attribute will be blocked.

## See also

[IEvalRat Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nn-tvratings-ievalrat)

[IEvalRat::put_BlockedRatingAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nf-tvratings-ievalrat-put_blockedratingattributes)