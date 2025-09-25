# IWMReaderAdvanced::SetReceiveStreamSamples

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetReceiveStreamSamples** method specifies whether stream samples are delivered to the [IWMReaderCallbackAdvanced::OnStreamSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallbackadvanced-onstreamsample) callback.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number. Stream numbers are in the range of 1 through 63.

### `fReceiveStreamSamples` [in]

Boolean value that is True if stream samples are delivered.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |
| **E_NOINTERFACE** | No callback interface has been specified. |
| **NS_E_PROTECTED_CONTENT** | Attempted read on a file protected by [DRM](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary). |

## Remarks

Stream samples are samples received directly from the source file, and are not decompressed. If you receive compressed samples, you must either keep them compressed, or decompress them with your application. The Windows Media Format SDK does not provide methods to decompress samples once they have been removed from a file.

The application can register itself to receive samples directly from the Windows Media streams rather than letting the reader decompress them first. To do this, the object implementing [IWMReaderCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallback) (supplied by the application) must support [IWMReaderCallbackAdvanced](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallbackadvanced). To determine which streams are in an ASF file, and what their stream numbers are, call **QueryInterface** using the reader object to access the [IWMProfile](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile) interface, and examine the streams in the profile.

## See also

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)

[IWMReaderAdvanced::GetReceiveStreamSamples](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-getreceivestreamsamples)