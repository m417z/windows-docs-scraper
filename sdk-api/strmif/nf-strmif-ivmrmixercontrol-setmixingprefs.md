# IVMRMixerControl::SetMixingPrefs

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Sets the mixing preferences for the stream.

## Parameters

### `dwMixerPrefs` [in]

Bitwise **OR** combination of [VMRMixerPrefs](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vmrmixerprefs) flags.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The flags for the mixing preferences are divided into three groups: decimation, filtering, and render target. The VMRMixerPrefs enumeration defines bitmasks to isolate these flags:

* MixerPref_DecimateMask
* MixerPref_FilteringMask
* MixerPref_RenderTargetMask

You must specify a valid flag for each group. If you want to change a single flag, you can get the current preferences, remove the flag you don't want, and add the flag you want. For example:

| C++ |
| --- |
| ``` // Get the current mixing preferences. DWORD dwPrefs; pMixControl->GetMixingPrefs(&dwPrefs);  <br><br>// Remove the current render target flag. dwPrefs &= ~MixerPref_RenderTargetMask; <br><br>// Add the render target flag that we want. dwPrefs |= MixerPref_RenderTargetYUV;<br><br>// Set the new flags. pMixControl->SetMixingPrefs(dwPrefs); ``` |

If the VMR is in renderless mode, you must set the allocator-presenter before calling `SetMixingPrefs`. Otherwise, the VMR cannot determine the capabilities of the Direct3D device.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRMixerControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrmixercontrol)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)