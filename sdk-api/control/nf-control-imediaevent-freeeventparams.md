# IMediaEvent::FreeEventParams

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `FreeEventParams` method frees resources associated with the parameters of an event.

## Parameters

### `lEvCode` [in]

Event code.

### `lParam1` [in]

First event parameter.

### `lParam2` [in]

Second event parameter.

## Return value

Returns S_OK.

## Remarks

After you call the [IMediaEvent::GetEvent](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediaevent-getevent) method to retrieve an event notification, you must call `FreeEventParams`. This method frees any resources that were allocated for the event parameters. Pass in the same variables used for the **GetEvent** call.

#### Examples

```cpp

hr = pEvent->GetEvent(&evCode, &param1, &param2, 0);
// Handle the event (not shown).
hr = pEvent->FreeEventParams(evCode, param1, param2);

```

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaEvent Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaevent)

[IMediaEventEx](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaeventex)