# IEVRTrustedVideoPlugin::IsInTrustedVideoMode

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Queries whether the plug-in has any transient vulnerabilities at this time.

## Parameters

### `pYes` [out]

Receives a Boolean value. If **TRUE**, the plug-in has no transient vulnerabilities at the moment and can receive protected content. If **FALSE**, the plug-in has a transient vulnerability. If the method fails, the EVR treats the value as **FALSE** (untrusted).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method provides a way for the plug-in to report temporary conditions that would cause the input trust authority (ITA) to distrust the plug-in. For example, if an EVR presenter is in windowed mode, it is vulnerable to GDI screen captures.

To disable screen capture in Direct3D, the plug-in must do the following:

* Create the Direct3D device in full-screen exclusive mode.
* Specify the D3DCREATE_DISABLE_PRINTSCREEN flag when you create the device. For more information, see **IDirect3D9::CreateDevice** in the DirectX documentation.

In addition, the graphics adapter must support the Windows Vista Display Driver Model (WDDM) and the Direct3D extensions for Windows Vista (sometimes called D3D9Ex or D3D9L).

If these conditions are met, the presenter can return **TRUE** in the *pYes* parameter. Otherwise, it should return **FALSE**.

The EVR calls this method whenever the device changes. If the plug-in returns **FALSE**, the EVR treats this condition as if the plug-in had a new output connector of unknown type. The policy object can then allow or block playback, depending on the ITA's policy.

This method should be used only to report transient conditions. A plug-in that is never in a trusted state should not implement the [IEVRTrustedVideoPlugin](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-ievrtrustedvideoplugin) interface at all.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IEVRTrustedVideoPlugin](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-ievrtrustedvideoplugin)

[Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)