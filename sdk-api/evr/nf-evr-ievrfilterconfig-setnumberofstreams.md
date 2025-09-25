# IEVRFilterConfig::SetNumberOfStreams

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Sets the number of input pins on the EVR filter.

## Parameters

### `dwMaxStreams` [in]

Specifies the total number of input pins on the EVR filter. This value includes the input pin for the reference stream, which is created by default. For example, to mix one substream plus the reference stream, set this parameter to 2.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid number of streams. The minimum is one, and the maximum is 16. |
| **VFW_E_WRONG_STATE** | This method has already been called, or at least one pin is already connected. |

## Remarks

After this method has been called, it cannot be called a second time on the same instance of the EVR filter. Also, the method fails if any input pins are connected.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IEVRFilterConfig](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-ievrfilterconfig)