# IVMRSurface9::GetSurface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetSurface` method retrieves the attached Direct3D surface.

## Parameters

### `lplpSurface` [out]

Address of a variable that receives an **IDirect3DSurface9** interface pointer. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *lplpSurface* is invalid. |
| **E_FAIL** | No Direct3D surface is attached to this sample. |

## Remarks

The media sample object increments the reference count on the returned interface. The caller must call Release on the interface.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRSurface9 Interface](https://learn.microsoft.com/windows/desktop/api/vmr9/nn-vmr9-ivmrsurface9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)