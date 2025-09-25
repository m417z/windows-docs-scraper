# IDTFilter::put_BlockUnRated

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_BlockUnRated** method specifies whether to block a program for which rating information has not been obtained.

## Parameters

### `fBlockUnRatedShows` [in]

Boolean value. Specify **TRUE** to block unrated programs, or specify **FALSE** not to block unrated programs.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The **EvalRat** object was not successfully created. |
| **S_OK** | Success. |

## Remarks

The filter passes this call through to the **EvalRat** object. For more information, see [IEvalRat::put_BlockUnRated](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nf-tvratings-ievalrat-put_blockunrated).

## See also

[IDTFilter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-idtfilter)