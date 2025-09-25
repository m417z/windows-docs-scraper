# IWMReaderAdvanced2::OpenStream

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OpenStream** method opens a Windows Media stream for reading.

## Parameters

### `pStream` [in]

Pointer to an **IStream** interface (see the Remarks section below).

### `pCallback` [in]

Pointer to an [IWMReaderCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallback) interface.

### `pvContext` [in]

Generic pointer, for use by the application. This is passed to the application in calls to **IWMReaderCallback::OnStatus**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pCallback* parameter is **NULL**. |
| **E_OUTOFMEMORY** | There is not enough available memory. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

This method is identical to [IWMReader::Open](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-open), except that it takes an **IStream** interface pointer instead of a URL. An **IStream** is a standard COM interface for providing data. This allows the application to provide its own data, rather than just getting data from a file or a network. For example, if you have an **IStream** interface pointer that represents the contents of a supported media file (Windows Media Audio, Windows Media Video, MP3, for example) and, for performance reasons, you do not want to write a temporary file , this is a way you can use the SDK to parse and decompress your content.

This method sends a WMT_OPENED status notification to the application's **IWMReaderCallback::OnStatus** function. ([OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) is inherited by **IWMReaderCallback** from [IWMStatusCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstatuscallback).)

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)