# IMFDesiredSample::SetDesiredSampleTimeAndDuration

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Called by the presenter to set the time and duration of the sample that it requests from the mixer.

## Parameters

### `hnsSampleTime` [in]

The time of the requested sample.

### `hnsSampleDuration` [in]

The duration of the requested sample.

## Remarks

This value should be set prior to passing the buffer to the mixer for a Mix operation. The mixer sets the actual start and duration times on the sample before sending it back.

## See also

[How to Write an EVR Presenter](https://learn.microsoft.com/windows/desktop/medfound/how-to-write-an-evr-presenter)

[IMFDesiredSample](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfdesiredsample)