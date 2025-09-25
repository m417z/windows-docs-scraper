# ISBE2Crossbar::SetOutputProfile

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Replaces the default or current input profile with the profile specified in this method.

You can discover the current input profile by calling the [GetInitialProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-getinitialprofile) method. This profile can be changed over time as media types are updated on input to the [Stream Buffer Source](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter) filter.

A custom profile can contain only one stream per major media type. For example, a custom profile can contain only a single audio stream.

By default, the filter crossbar has profile default mode enabled, which means that you cannot set a custom output profile. Before you can set a custom output profile, you must disable profile default mode by calling the [EnableDefaultMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-enabledefaultmode) method without the DEF_MODE_PROFILE flag.

## Parameters

### `pProfile` [in]

Pointer to the [ISBE2MediaTypeProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2mediatypeprofile) interface for the profile that replaces the crossbar default profile.

### `pcOutputPins` [in, out]

On input, specifies the size of an array allocated to receive [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) pointers for the output pins that correspond to the streams in the new profile. The *ppOutputPins* parameter points to this array. On output, if the call succeeds, gets the actual number of **IPin** pointers returned in the *ppOutputPins* output parameter.

### `ppOutputPins` [in, out]

On input, specifies a pointer to an array of uninitialized [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) pointers. On output, if the call succeeds, the **IPin** pointers in the array are initialized to point to the filter output pins that have the media types listed in the new profile. The *pcOutputPins* parameter gives the number of elements in the array. The caller is responsible for freeing the **IPin** interface pointers returned in the array.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return value | Description |
| --- | --- |
| S_OK | Success. |
| E_INVALIDARG | The *pProfile* parameter is **NULL**. |
| E_POINTER | The *pcOutputPins* parameter is **NULL**. |
| E_UNEXPECTED | Cannot set output profile because profile default mode is enabled. |

## See also

[EnableDefaultMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2crossbar-enabledefaultmode)

[IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin)

[ISBE2Crossbar](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2crossbar)

[ISBE2MediaTypeProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2mediatypeprofile)

[Stream Buffer Source Filter](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter)