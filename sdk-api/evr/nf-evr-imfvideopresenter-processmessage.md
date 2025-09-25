# IMFVideoPresenter::ProcessMessage

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Sends a message to the video presenter. Messages are used to signal the presenter that it must perform some action, or that some event has occurred.

## Parameters

### `eMessage` [in]

Specifies the message as a member of the [MFVP_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/evr/ne-evr-mfvp_message_type) enumeration.

### `ulParam` [in]

Message parameter. The meaning of this parameter depends on the message type.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The video renderer has been shut down. |

## See also

[How to Write an EVR Presenter](https://learn.microsoft.com/windows/desktop/medfound/how-to-write-an-evr-presenter)

[IMFVideoPresenter](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideopresenter)