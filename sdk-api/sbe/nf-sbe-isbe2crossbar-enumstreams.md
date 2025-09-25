# ISBE2Crossbar::EnumStreams

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets an enumeration object for all streams that are discovered in a WTV file. The filter crossbar, which exposes the [ISBE2Crossbar](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2crossbar) interface, manages the mappings between the streams in the WTV file and the filter output pins.

The WTV file format supports dynamic creation and deletion of streams within the file. An [SBE2_STREAM_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/ns-sbe-sbe2_stream_desc) global spanning event in the file signals when a stream is created or deleted.

## Parameters

### `ppStreams` [out]

Receives a pointer to the [ISBE2EnumStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2enumstream) interface that the crossbar implements.
You can use the methods that are defined by the **ISBE2EnumStream** interface to enumerate the streams that can be mapped to output pins in the current profile. The caller is responsible for releasing the interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return value | Description |
| --- | --- |
| S_OK | Success. |
| E_POINTER | **NULL** pointer argument. |
| E_FAIL | No streams found. |

## See also

[ISBE2Crossbar](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2crossbar)

[ISBE2EnumStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2enumstream)

[Stream Buffer Source Filter](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter)