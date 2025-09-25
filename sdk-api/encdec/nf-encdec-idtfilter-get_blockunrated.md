# IDTFilter::get_BlockUnRated

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_BlockUnRated** method indicates whether a program without rating information is blocked.

## Parameters

### `pfBlockUnRatedShows` [out, retval]

Receives a Boolean value. If the value is **TRUE**, unrated shows are blocked. Otherwise, they are not blocked.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The **EvalRat** object was not successfully created. |
| **S_OK** | Success. |

## Remarks

The filter passes this call through to the **EvalRat** object. For more information, see [IEvalRat::get_BlockUnRated](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nf-tvratings-ievalrat-get_blockunrated).

## See also

[IDTFilter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-idtfilter)