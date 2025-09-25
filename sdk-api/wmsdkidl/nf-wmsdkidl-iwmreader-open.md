# IWMReader::Open

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Open** method opens an ASF file for reading.

## Parameters

### `pwszURL` [in]

Pointer to a wide-character **null**-terminated string containing the path and name of the file to be opened. This method accepts a path to a folder on a local machine, a path to a network share, or a uniform resource locator (URL).

### `pCallback` [in]

Pointer to the object that implements the [IWMReaderCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallback) interface.

### `pvContext` [in]

Generic pointer, for use by the application. This is passed to the application in calls to **OnStatus**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pCallback* parameter is **NULL**. |
| **E_OUTOFMEMORY** | There is not enough available memory. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

This method is asynchronous; it returns very quickly and sends a WMT_OPENED status notification to the application's [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) method when the file is opened and ready for use.

Because the method returns before the file is opened, a return value of S_OK does not necessarily mean that the file has been opened successfully. To ascertain the success of the call, you must check the value of the *hr* parameter of **OnStatus** when the WMT_OPENED notification is received.

If *hr* equals NS_E_NO_STREAM it means that the header is not yet available, and that a WMT_SOURCE_SWITCH event will be sent as soon as the header becomes available. No WMT_EOF will be sent before the WMT_SOURCE_SWITCH.

Applications that read files from behind a firewall will have better performance when opening files if the address is specified using the domain name server (DNS) name instead of the IP address.

## See also

[IWMReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreader)

[IWMReader::Close](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-close)

[IWMReader::Start](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-start)

[IWMReader::Stop](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-stop)

[IWMReaderAdvanced2::OpenStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced2-openstream)

[IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus)