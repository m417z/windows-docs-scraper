# IESIsdbCasResponseEvent::GetStatus

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the response status returned in an [IsdbCasResponse](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesisdbcasresponseevent) event.

## Parameters

### `pStatus` [out, retval]

Receives the status code. This can have any of the following values.

| Value | Meaning |
| --- | --- |
| 0x9000 | Success. |
| 0x6400 | Memory error. |
| 0x6581 | Write error. |
| 0x6700 | Interconnect command length. |
| 0x6800 | Unsupported class. |
| 0x6A86 | Incorrect parameter. |
| 0x6D00 | Unsupported instruction. |
| 0x6E00 | Unsupported class. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESIsdbCasResponseEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesisdbcasresponseevent)