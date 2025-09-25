# MFVP_MESSAGE_TYPE enumeration

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Defines messages for an enhanced video renderer (EVR) presenter. This enumeration is used with the [IMFVideoPresenter::ProcessMessage](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideopresenter-processmessage) method.

## Constants

### `MFVP_MESSAGE_FLUSH:0`

The presenter should discard any pending samples. The *ulParam* parameter is not used and should be zero.

### `MFVP_MESSAGE_INVALIDATEMEDIATYPE:0x1`

The mixer's output format has changed. The EVR will initiate format negotiation. The *ulParam* parameter is not used and should be zero.

### `MFVP_MESSAGE_PROCESSINPUTNOTIFY:0x2`

One input stream on the mixer has received a new sample. The *ulParam* parameter is not used and should be zero.

### `MFVP_MESSAGE_BEGINSTREAMING:0x3`

The EVR switched from stopped to paused. The presenter should allocate resources. The *ulParam* parameter is not used and should be zero.

### `MFVP_MESSAGE_ENDSTREAMING:0x4`

The EVR switched from running or paused to stopped. The presenter should free resources. The *ulParam* parameter is not used and should be zero.

### `MFVP_MESSAGE_ENDOFSTREAM:0x5`

All streams have ended. The *ulParam* parameter is not used and should be zero.

### `MFVP_MESSAGE_STEP:0x6`

Requests a frame step. The lower **DWORD** of the *ulParam* parameter contains the number of frames to step. If the value is *N*, the presenter should skip *N*–1 frames and display the *N*th frame. When that frame has been displayed, the presenter should send an **EC_STEP_COMPLETE** event to the EVR. If the presenter is not paused when it receives this message, it should return MF_E_INVALIDREQUEST.

### `MFVP_MESSAGE_CANCELSTEP:0x7`

Cancels a frame step. The *ulParam* parameter is not used and should be zero.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)