# IWMPacketSize2::SetMinPacketSize

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetMinPacketSize** method sets the minimum [packet](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) size for files created with the profile. This method cannot be called from an interface belonging to a reader or synchronous reader object.

## Parameters

### `dwMinPacketSize` [in]

**DWORD** specifying the new minimum packet size for files created with the profile.

## Return value

This method always returns S_OK.

## Remarks

This method is used to force the writer to create packet sizes that are larger than the default size. The writer object, by default, selects an optimal packet size based on the bit rate. At bit rates below 350 kbps, it is approximately 1440 bytes. Below 100 kbps, the default packet size is calculated to provide approximately 10 packets per second, or ((bit_rate / 8) / 10).

Although larger packets result in a smaller file, they can also make the file more difficult to stream over a network. Use this method with caution if you are creating files that will be streamed. It is recommended that the packet size never be set to a value greater than 8000 bytes, which is the default packet size above 350 kbps.

## See also

[IWMPacketSize2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmpacketsize2)

[IWMPacketSize2::GetMinPacketSize](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmpacketsize2-getminpacketsize)