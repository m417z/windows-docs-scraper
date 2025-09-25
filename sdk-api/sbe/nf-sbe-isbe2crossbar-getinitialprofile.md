# ISBE2Crossbar::GetInitialProfile

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the initial profile that lists the media types that are present in the currently loaded WTV file. The media types in the profile correspond to the active pins on a [Stream Buffer Source](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter) filter at the time the currently loaded WTV file is created. The profile is fixed per loaded WTV file and does not change while the filter has a WTV file loaded . However, if the crossbar is not in default profile mode, you can call the [SetOutputProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-setoutputprofile) method to set a new profile for the crossbar. To disable default profile mode, call the [EnableDefaultMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-enabledefaultmode) method without the DEF_MODE_PROFILE flag.

## Parameters

### `ppProfile` [out]

Receives a pointer to the [ISBE2MediaTypeProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2mediatypeprofile) interface that implements the profile.
The caller is responsible for releasing this interface. You can use this pointer to create a custom profile that you pass to the [SetOutputProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-setoutputprofile) method.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return value | Description |
| --- | --- |
| S_OK | Success. |
| E_POINTER | Null pointer argument. |
| E_FAIL | Empty initial profiles. |

## See also

[ISBE2Crossbar](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2crossbar)

[ISBE2MediaTypeProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2mediatypeprofile)

[ISBE2SpanningEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2spanningevent)

[Stream Buffer Sink2 Filter](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-sink2-filter)