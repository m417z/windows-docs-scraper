# ISBE2StreamMap::MapStream

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Maps a stream to an output pin for a [Stream Buffer Source](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter) filter.

By default, the stream mappings cannot be changed. Before calling this method, disable the default mapping mode by calling the [ISBE2Crossbar::EnableDefaultMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-enabledefaultmode) method without the **DEF_MODE_STREAMS** flag.

## Parameters

### `Stream` [in]

Identifier for the stream mapped to an output pin. The major type of the stream must match the major type of the pin.

## Return value

| Return code/value | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | The specified stream has already been mapped to a pin. |
| **E_UNEXPECTED** | Cannot unmap the stream, because the default mode is enabled. |
| **HRESULT_FROM_WIN32 (ERROR_NOT_FOUND)**<br><br>0x80070490 | No stream exists with the specified stream identifier. |

## Remarks

If the new stream has different media type from the previously mapped stream, the output pin follows the dynamic format change procedure described in [Dynamic Format Changes](https://learn.microsoft.com/windows/desktop/DirectShow/dynamic-format-changes), and flushes downstream pins as described in [Flushing](https://learn.microsoft.com/windows/desktop/DirectShow/flushing).

## See also

[ISBE2Crossbar](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2crossbar)

[ISBE2Crossbar::EnableDefaultMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-enabledefaultmode)

[ISBE2StreamMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2streammap)

[Stream Buffer Source Filter](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter)