# IWMReaderAdvanced::GetReceiveStreamSamples

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetReceiveStreamSamples** method ascertains whether stream samples are delivered to the [IWMReaderCallbackAdvanced::OnStreamSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallbackadvanced-onstreamsample) call.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number. Stream numbers are in the range of 1 through 63.

### `pfReceiveStreamSamples` [out]

Pointer to a Boolean value that is set to True if stream samples are delivered to **OnStreamSample**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pfReceiveStreamSamples* parameter is **NULL**, or the stream number is not valid. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

Stream samples are samples received directly from the source file, and are not decompressed. If you receive compressed samples, you must either keep them compressed, or decompress them with your application. The Windows Media Format SDK does not provide methods to decompress samples once they have been removed from a file.

## See also

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)

[IWMReaderAdvanced::SetReceiveStreamSamples](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-setreceivestreamsamples)