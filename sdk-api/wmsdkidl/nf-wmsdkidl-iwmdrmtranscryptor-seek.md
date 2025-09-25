# IWMDRMTranscryptor::Seek

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**Seek** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **Seek** method sets the DRM transcryptor to read from the specified point in the data stream of the loaded file. Subsequent [Read](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmtranscryptor-read) calls generate data beginning at that point.

## Parameters

### `hnsTime` [in]

Seek time in 100-nanosecond units.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | There is no file loaded in the transcryptor. |

## Remarks

This method is asynchronous. It returns immediately, but processing is not complete until a WMT_TRANSCRYPTOR_SEEKED message is sent to the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback method.

If the seek operation fails, no message is sent.

The first successful call to **Seek** causes the transcryptor to read the ASF header for the content. All subsequent **Seek** calls change the reading location in the data section, but do not generate a header or an ASF Data Object (the ASF object that contains top-level information about the data section).

To convert the entire file, call **Seek** with a presentation time of 0.

## See also

[IWMDRMTranscryptor Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmtranscryptor)

[IWMDRMTranscryptor::Read](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmtranscryptor-read)