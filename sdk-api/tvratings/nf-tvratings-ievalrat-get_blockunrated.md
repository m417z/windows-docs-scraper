# IEvalRat::get_BlockUnRated

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_BlockUnRated** method indicates whether a program without rating information is blocked.

## Parameters

### `pfBlockUnRatedShows` [out, retval]

Receives a Boolean value. If the value is **TRUE**, unrated shows are blocked. Otherwise, they are not blocked.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | The method succeeded. |

## Remarks

**Note**By default, unrated programs should be allowed. Return **FALSE** in *pfBlockUnRatedShows* unless the **put_BlockUnRated** method was previously called with the value **TRUE**.

## See also

[IEvalRat Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nn-tvratings-ievalrat)

[IEvalRat::put_BlockUnRated](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nf-tvratings-ievalrat-put_blockunrated)