# GetInterface function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetInterface` function retrieves an interface pointer.

## Parameters

*pUnk*

Pointer to the **IUnknown** interface.

*ppv*

Address of a pointer to the retrieved interface.

## Return value

Returns an **HRESULT** value.

## Remarks

This member function performs a thread-safe increment of the reference count. To retrieve the interface and add a reference, call this function from your overriding implementation of the **INonDelegatingUnknown::NonDelegatingQueryInterface** method.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Combase.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [**COM Helper Functions**](https://learn.microsoft.com/windows/win32/directshow/com-helper-functions) [**INonDelegatingUnknown**](https://learn.microsoft.com/windows/win32/directshow/inondelegatingunknown)