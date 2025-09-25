# IWMPlayerHook::PreDecode

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **PreDecode** method is called by the reader object before a sample from the output to which the **IWMPlayerHook** interface is assigned is passed to the video processor for decoding.

## Return value

The method returns an **HRESULT**. You should return S_OK.

## Remarks

To assign an implementation of the **IWMPlayerHook** interface to an output in the reader object, call [IWMReaderAdvanced5::SetPlayerHook](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced5-setplayerhook).

## See also

[Enabling DirectX Video Acceleration](https://learn.microsoft.com/windows/desktop/wmformat/enabling-directx-video-acceleration)

[IWMPlayerHook Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmplayerhook)