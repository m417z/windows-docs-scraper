# IMFDesiredSample::Clear

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Clears the time stamps previously set by a call to [IMFDesiredSample::SetDesiredSampleTimeAndDuration](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfdesiredsample-setdesiredsampletimeandduration).

## Remarks

After this method is called, the [IMFDesiredSample::GetDesiredSampleTimeAndDuration](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfdesiredsample-getdesiredsampletimeandduration) method returns MF_E_NOT_AVAILABLE.

This method also clears the time stamp and duration and removes all attributes from the sample.

## See also

[How to Write an EVR Presenter](https://learn.microsoft.com/windows/desktop/medfound/how-to-write-an-evr-presenter)

[IMFDesiredSample](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfdesiredsample)