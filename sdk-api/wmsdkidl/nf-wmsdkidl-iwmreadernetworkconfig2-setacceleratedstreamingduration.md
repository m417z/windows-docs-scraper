# IWMReaderNetworkConfig2::SetAcceleratedStreamingDuration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetAcceleratedStreamingDuration** method sets the accelerated streaming duration. This duration applies to the Fast Start feature of Windows Media Services, which enables content to be played quickly without waiting for lengthy initial buffering.

## Parameters

### `cnsAccelDuration` [in]

Specifies the accelerated streaming duration, in 100-nanosecond units. The maximum value is 1,200,000,000. This is the amount of data at the beginning of the content that is streamed at an accelerated rate.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When using Fast Start, the server running Windows Media Services will send some data at the beginning of the content at a faster rate than that specified by the bit rate of the content.

## See also

[IWMReaderNetworkConfig2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig2)

[IWMReaderNetworkConfig2::GetAcceleratedStreamingDuration](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig2-getacceleratedstreamingduration)