# DEXTER\_PARAM structure

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

> [!Note]
> \[Deprecated. This API may be removed from future releases of Windows.\]

Specifies the value that a property assumes at a given time.

## Members

**Name**

Name of the property.

**dispID**

Reserved. Set to zero.

**nValues**

Number of values that the property assumes.

## Remarks

The object must support the **IDispatch** interface.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------|
| Header<br> | Qedit.h |

## See also

[**IPropertySetter**](https://learn.microsoft.com/windows/win32/directshow/ipropertysetter)

[**DEXTER\_VALUE**](https://learn.microsoft.com/windows/win32/directshow/dexter-value)

