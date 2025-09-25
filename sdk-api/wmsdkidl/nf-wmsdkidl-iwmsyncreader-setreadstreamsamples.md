# IWMSyncReader::SetReadStreamSamples

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetReadStreamSamples** method specifies whether samples from a stream will be delivered compressed or uncompressed.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number.

### `fCompressed` [in]

Boolean value that is True if samples will be compressed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | No file is open in the synchronous reader. |
| **NS_E_PROTECTED_CONTENT** | The stream is protected and not configured to deliver compressed samples. |
| **E_INVALIDARG** | *wStreamNum* specifies an invalid stream number. |

## Remarks

You can call **SetReadStreamSamples** at any time after a file has been loaded into the synchronous reader. You can continue making calls as needed during playback.

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)

[IWMSyncReader::GetReadStreamSamples](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-getreadstreamsamples)