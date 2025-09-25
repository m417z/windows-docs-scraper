# IWMStreamConfig::SetBufferWindow

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetBufferWindow** method specifies the maximum latency between when a stream is received and when it begins to be displayed.

## Parameters

### `msBufferWindow` [in]

Buffer window, in milliseconds.

## Return value

This method always returns S_OK.

## Remarks

For high bit rate streams (typically, more than 1 megabit per second), a latency (or buffer window) of 1 second is typical; for lower bit rate streams, a latency of approximately 3 seconds is often used.

Setting the buffer window to -1 (0xFFFFFFFF) indicates that the buffer window is unknown. In this case, the writer selects the buffer window size.

For video streams, a larger buffer window gives higher quality.

**Note** A problem can arise if you create a file containing streams with widely varying buffer windows. Playback applications created with a previous version of the Windows Media Format SDK have difficulty rendering the data from such files properly. If you are creating files to be used with older players, you should ensure that the buffer windows of any two streams do not vary by more than five seconds.

The new value will not take effect in the profile until you call [IWMProfile::ReconfigStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-reconfigstream).

## See also

[IWMStreamConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig)

[IWMStreamConfig::GetBufferWindow](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig-getbufferwindow)