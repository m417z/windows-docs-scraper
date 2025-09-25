# IEVRTrustedVideoPlugin::DisableImageExport

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Enables or disables the ability of the plug-in to export the video image.

## Parameters

### `bDisable` [in]

Boolean value. Specify **TRUE** to disable image exporting, or **FALSE** to enable it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

An EVR plug-in might expose a way for the application to get a copy of the video frames. For example, the standard EVR presenter implements [IMFVideoDisplayControl::GetCurrentImage](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-getcurrentimage).

If the plug-in supports image exporting, this method enables or disables it. Before this method has been called for the first time, the EVR assumes that the mechanism is enabled.

If the plug-in does not support image exporting, this method should return S_OK and ignore the value of *bDisable*. If the method fails, the EVR treats it as a failure to enforce the policy, which will probably cause playback to stop.

While image exporting is disabled, any associated export method, such as [GetCurrentImage](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-getcurrentimage), should return MF_E_LICENSE_INCORRECT_RIGHTS.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IEVRTrustedVideoPlugin](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-ievrtrustedvideoplugin)

[Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)