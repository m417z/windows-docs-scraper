# IWMStreamConfig::SetBitrate

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetBitrate** method specifies the bit rate for the stream.

## Parameters

### `pdwBitrate` [in]

**DWORD** containing the bit rate, in bits per second.

## Return value

This method always returns S_OK.

## Remarks

The bit rate is the number of bits per second given to the stream in the ASF file, not including any overhead. For compressed bit streams, such as audio or video, a higher bit rate gives higher quality.

The new value will not take effect in the profile until you call [IWMProfile::ReconfigStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-reconfigstream).

## See also

[IWMStreamConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig)

[IWMStreamConfig::GetBitrate](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig-getbitrate)