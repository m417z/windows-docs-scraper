# IAnchor::GetChangeHistory

## Description

The **IAnchor::GetChangeHistory** method gets the history of deletions that have occurred immediately preceding or following the anchor.

## Parameters

### `pdwHistory` [out]

Bit field flags that specify that deletions have occurred immediately preceding or following the anchor. One or both of the following values can be set.

| Value | Meaning |
| --- | --- |
| **TS_CH_PRECEDING_DEL** | Text preceding the anchor has been deleted. |
| **TS_CH_FOLLOWING_DEL** | Text following the anchor has been deleted. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The value of *pdwHistory* is invalid. |

## Remarks

The *pdwHistory* change flags must be set when deletions adjacent to the anchor have occurred.

The change flags remain set until they are cleared with a call to [IAnchor::ClearChangeHistory](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-clearchangehistory).

## See also

[IAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-ianchor)

[IAnchor::ClearChangeHistory](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-clearchangehistory)