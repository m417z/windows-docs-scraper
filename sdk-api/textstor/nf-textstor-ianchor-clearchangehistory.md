# IAnchor::ClearChangeHistory

## Description

The **IAnchor::ClearChangeHistory** method clears the anchor change history flags.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Applications should clear the anchor change history flags after receiving this call. The change history flags were set by [IAnchor::GetChangeHistory](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-getchangehistory).

## See also

[IAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-ianchor)

[IAnchor::GetChangeHistory](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-getchangehistory)