# IWMReaderNetworkConfig2::GetEnableThinning

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetEnableThinning** method ascertains whether Intelligent Streaming is enabled. Intelligent Streaming is the communication between the reader and the streaming server that enables the server to change the content sent based on available bandwidth.

## Parameters

### `pfEnableThinning` [out]

Pointer to a variable that receives a Boolean value. The value is **TRUE** if thinning is enabled, or **FALSE** if thinning is disabled.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL pointer argument. |

## Remarks

With Intelligent Streaming enabled, the reader responds to insufficient bandwidth by requesting that the server reduce the bit rate by using one of the following techniques. If one technique does not solve the problem, the reader will try the next one:

* If the file is encoded using multiple bit rates (MBR), the first step the reader takes to rectify insufficient bandwidth is to request a lower bit rate version of streams.
* If the file is not MBR, or if using a lower bit rate stream does not reduce the bandwidth requirements enough, the reader requests that the server thin the video streams. This means that the server reduces the frame rate of the video being streamed.
* If thinning the video streams does not reduce the bandwidth requirements enough, the reader requests that the server stop sending video streams.

If Intelligent Streaming is disabled by setting *pfEnableThinning* to **FALSE**, the reader will not request any bandwidth corrections.

This feature applies only to content streaming from a server running Windows Media Services.

## See also

[IWMReaderNetworkConfig2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig2)

[IWMReaderNetworkConfig2::SetEnableThinning](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig2-setenablethinning)