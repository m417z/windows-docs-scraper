# REGFILTERPINS structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `REGFILTERPINS` structure contains pin information for registering a filter.

## Members

### `strName`

Name of the pin. (Obsolete.)

### `bRendered`

If **TRUE**, the filter renders the input from this pin. (Applies only to input pins. For output pins, the value is always **FALSE**.)

### `bOutput`

If **TRUE**, this pin is an output pin. Otherwise, the pin is an input pin.

### `bZero`

If **TRUE**, the filter can have zero instances of this pin.

### `bMany`

If **TRUE**, the filter can create more than one instance of this type of pin.

### `clsConnectsToFilter`

Class identifier (CLSID) of the filter to which this pin connects. (Obsolete.)

### `strConnectsToPin`

Name of the pin to which this pin connects. (Obsolete.)

### `nMediaTypes`

Number of media types supported by this pin.

### `lpMediaType`

Pointer to an array of [REGPINTYPES](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regpintypes) structures, of size **nMediaTypes**.

## Remarks

This structure is used in the [IFilterMapper2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper2) interface for filter registration. If you use this structure, set the **dwVersion** member of the [REGFILTER2](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regfilter2) structure to 1. If you need to register a medium or pin category for the pin, use the [REGFILTERPINS2](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regfilterpins2) structure instead. In that case, set the **REGFILTER2** structure's **dwVersion** member to 2.

The equivalent **AMOVIESETUP_PIN** type is used in class factory templates ([CFactoryTemplate](https://learn.microsoft.com/windows/desktop/DirectShow/cfactorytemplate)).

The **strName**, **clsConnectsToFilter**, and **strConnectsToPin** members are obsolete. Their values are not added to the registry.

For more information, see [How to Register DirectShow Filters](https://learn.microsoft.com/windows/desktop/DirectShow/how-to-register-directshow-filters).

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)