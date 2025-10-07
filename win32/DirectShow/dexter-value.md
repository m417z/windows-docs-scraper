# DEXTER\_VALUE structure

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

> [!Note]
> \[Deprecated. This API may be removed from future releases of Windows.\]

Identifies a property that is to be set on a transition or effect, along with the number of distinct values that the property assumes over the duration of the transition or effect.

## Members

**v**

Value of the property.

**rt**

Time at which the property assumes the value, relative to the start of the transition or effect.

**dwInterp**

Flag indicating how the property progresses from the previous value to this value. Must be one of the following:

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| **DEXTERF\_JUMP** | The property jumps instantly to the new value at the specified time.<br> |
| **DEXTERF\_INTERPOLATE** | The property is interpolated linearly over time from the previous value.<br> |

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------|
| Header<br> | Qedit.h |

## See also

[**IPropertySetter**](https://learn.microsoft.com/windows/win32/directshow/ipropertysetter)

[**DEXTER\_PARAM**](https://learn.microsoft.com/windows/win32/directshow/dexter-param)

