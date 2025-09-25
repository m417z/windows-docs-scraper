# IWMWriterPushSink::Connect

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Connect** method connects to a publishing point on a Windows Media server.

## Parameters

### `pwszURL` [in]

Wide-character string that contains the URL of the publishing point on the Windows Media server. For example, if the URL is "http://MyServer/MyPublishingPoint", the push sink connects to the publishing point named MyPublishingPoint on the server named MyServer. The default port number is 80. If the server is using a different port, specify the port number in the URL. For example, "http://MyServer:8080/MyPublishingPoint" specifies port number 8080.

### `pwszTemplateURL` [in]

Optional wide-character string that contains the URL of an existing publishing point to use as a template. This parameter can be **NULL**.

### `fAutoDestroy` [in]

Boolean value that specifies whether to remove the publishing point after the push sink disconnects from the server.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | Invalid argument; *pwszURL* cannot be **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **NS_E_INVALID_NAME** | Host name is not valid. |

## Remarks

If the publishing point specified in *pwsURL* does not exist, the server creates a new publishing point. The caller must have write and create permissions on the server. The new publishing point has the same configuration as the publishing point specified in the *pwszTemplateURL* parameter. If *pwszTemplateURL* is **NULL**, the new publishing point has the same configuration as the server's default publishing point.

## See also

[IWMWriterPushSink Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterpushsink)