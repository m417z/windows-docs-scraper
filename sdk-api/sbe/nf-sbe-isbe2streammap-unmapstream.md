# ISBE2StreamMap::UnmapStream

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Removes the mapping between a stream and an output pin for a [Stream Buffer Source](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter) filter. After a successful call to this method, the output pin stops sending media samples. To resume sending media samples, the pin must be mapped to another stream by a call to the [MapStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2streammap-mapstream) method.

By default, the stream mappings cannot be changed. Before calling this method, disable the default mapping mode by calling the [ISBE2Crossbar::EnableDefaultMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-enabledefaultmode) method without the **DEF_MODE_STREAMS** flag.

## Parameters

### `Stream` [in]

Identifier for the stream. This stream will be unmapped from the output pin.

## Return value

| Return code | Description |
| --- | --- |
| **S_FALSE** | The specified stream does not exist or was not previously mapped to a pin. |
| **S_OK** | Success. |
| **E_UNEXPECTED** | Cannot unmap the stream, because the default mode is enabled. |

## See also

[ISBE2Crossbar](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2crossbar)

[ISBE2Crossbar::EnableDefaultMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-enabledefaultmode)

[ISBE2StreamMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2streammap)

[ISBE2StreamMap::MapStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2streammap-mapstream)