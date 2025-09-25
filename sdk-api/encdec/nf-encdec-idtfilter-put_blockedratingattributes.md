# IDTFilter::put_BlockedRatingAttributes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_BlockedRatingAttributes** method specifies whether to block content that has a specified rating.

## Parameters

### `enSystem` [in]

Specifies the rating system, as an [EnTvRat_System](https://learn.microsoft.com/previous-versions/dd375612(v=vs.85)) enumeration type.

### `enLevel` [in]

Specifies the rating level, as an [EnTvRat_GenericLevel](https://learn.microsoft.com/previous-versions/dd375610(v=vs.85)) enumeration type.

### `lbfAttrs` [in]

Bitwise combination of zero or more flags from the [BfEnTvRat_GenericAttributes](https://learn.microsoft.com/previous-versions/dd318226(v=vs.85)) enumeration.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The **EvalRat** object was not successfully created. |
| **S_OK** | Success. |

## Remarks

The filter passes this call through to the **EvalRat** object. For more information, see [IEvalRat::put_BlockedRatingAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nf-tvratings-ievalrat-put_blockedratingattributes).

## See also

[IDTFilter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-idtfilter)