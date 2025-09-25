# IWMCodecAMVideoAccelerator::SetPlayerNotify

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetPlayerNotify** method is called by the output pin on the source filter to provide the decoder [DMO](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) with the source filter's **IWMPlayerTimestampHook** interface to enable the source filter to update the time stamps on the samples before they are delivered to the renderer.

## Parameters

### `pHook` [in]

Pointer to the **IWMPlayerTimestampHook** interface exposed on the player.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code

## See also

[Enabling DirectX Video Acceleration](https://learn.microsoft.com/windows/desktop/wmformat/enabling-directx-video-acceleration)

[IWMCodecAMVideoAccelerator Interface](https://learn.microsoft.com/windows/desktop/api/wmdxva/nn-wmdxva-iwmcodecamvideoaccelerator)