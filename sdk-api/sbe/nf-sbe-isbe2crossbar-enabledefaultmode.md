# ISBE2Crossbar::EnableDefaultMode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Enables or disables the profile default mode and stream default mode for a crossbar in a [Stream Buffer Source](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter) filter.
The *profile* describes a set of media types that can be used to create out pins, one media type per output pin. The *stream mapping* describes the mappings between the streams within a WTV file and filter output pins.

 If you do not call the **EnableDefaultMode** method in your application, the crossbar uses a default profile and a default stream map. In this case, the crossbar is said to be in *profile default mode* and *stream default mode*, respectively. You can use the **EnableDefaultMode** method to disable either mode or both modes, so that you can specify custom profiles or stream mappings. You can also use an `EnableDefaultMode(FALSE)` call to disable both default modes.

## Parameters

### `DefaultFlags` [in]

Specifies the default modes for the crossbar. This can be any combination of the following values.

| Value | Meaning |
| --- | --- |
| DEF_MODE_PROFILE | Enables profile default mode. The default profile is used, and you cannot specify custom profiles by calling the [SetOutputProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-setoutputprofile) method. If you omit this flag, profile default mode is disabled so that you can specify a custom output profile. |
| DEF_MODE_STREAMS | Enables stream default mode. The Stream Buffer Engine (SBE) handles the mapping between streams and output pins, and you cannot change these mappings by calling the [ISBE2StreamMap::MapStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2streammap-mapstream) method. If you omit this flag, stream default mode is disabled, so that you can specify a custom mapping. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In stream default mode, SBE first checks the Windows Media Center TV settings to determine if a preferred language is set. If a preferred language is set:

* If an audio stream in the preferred language exists, SBE outputs that audio stream.
* If an audio stream in the preferred language does not exist, SBE outputs the default audio stream, which is set when the stream is captured.

If no preferred language is set, Windows Media Center is either not present or not configured. In this case:

* If an audio stream in the language the operating system locale exists, SBE outputs that audio stream.
* Otherwise, SBE outputs the default audio stream.

## See also

[ISBE2Crossbar](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2crossbar)

[ISBE2Crossbar::SetOutputProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-setoutputprofile)

[ISBE2StreamMap::MapStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2streammap-mapstream)

[Stream Buffer Source Filter](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter)