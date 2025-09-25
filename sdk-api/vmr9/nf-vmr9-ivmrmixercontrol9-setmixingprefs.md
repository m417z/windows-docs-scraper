# IVMRMixerControl9::SetMixingPrefs

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetMixingPrefs` method sets the mixing preferences for the stream.

## Parameters

### `dwMixerPrefs` [in]

Bitwise OR combination of [VMR9MixerPrefs](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9mixerprefs) flags.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The flags for the mixing preferences are divided into three groups: decimation, filtering, and render target. The VMR9MixerPrefs enumeration defines bitmasks to isolate these flags:

* MixerPref9_DecimateMask
* MixerPref9_FilteringMask
* MixerPref9_RenderTargetMask

You must specify a valid flag for each group. If you want to change a single flag, you can get the current preferences, remove the flag you don't want, and add the flag you want. For example:

```cpp

// Get the current mixing preferences.
DWORD dwPrefs;
pMixControl->GetMixingPrefs(&dwPrefs);

// Remove the current render target flag.
dwPrefs &= ~MixerPref_RenderTargetMask;

// Add the render target flag that we want.
dwPrefs |= MixerPref_RenderTargetYUV;

// Set the new flags.
pMixControl->SetMixingPrefs(dwPrefs);

```

If the VMR is in renderless mode, you must set the allocator-presenter before calling `SetMixingPrefs`. Otherwise, the VMR cannot determine the capabilities of the Direct3D device.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRMixerControl9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrmixercontrol9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)