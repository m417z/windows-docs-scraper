# ISBE2StreamMap::EnumMappedStreams

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Enumerates streams that are mapped to output pins in a [Stream Buffer Source](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter) filter.

## Parameters

### `ppStreams` [out]

Receives a pointer to the [ISBE2EnumStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2enumstream) interface for an enumeration object that lists all streams mapped to the filter outputs pin.
The caller is responsible for freeing the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In Windows 7, only one stream at a time can be mapped to an output pin, although a call to the [ISBE2StreamMap::MapStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2streammap-mapstream) method can be used to change the stream mapped to any particular pin while the graph is running. In previous versions of Windows, a stream mapped to a pin could not be changed while the graph was running.

## See also

[ISBE2Crossbar](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2crossbar)

[ISBE2EnumStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2enumstream)

[ISBE2StreamMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2streammap)

[Stream Buffer Source Filter](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter)