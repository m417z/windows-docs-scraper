# IWMReaderAdvanced4::AddLogParam

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddLogParam** method adds a named value to the logging information that the reader object will send to the sever.

## Parameters

### `wszNameSpace` [in]

Optional wide-character string that contains the namespace for the log entry. This parameter can be **NULL**. Namespace names are limited to 1024 wide characters.

### `wszName` [in]

Wide-character string that contains the name of the log entry. Log entry names are limited to 1024 wide characters.

### `wszValue` [in]

Wide-character string that contains the value of the log entry. Log entry values are limited to 1024 wide characters.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | One of the parameters exceeded the allowed string length. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

The reader object sends logging data to the server in the form of an XML stream. The **AddLogParam** method enables the client to specify additional logging entries. The *wszNameSpace* parameter can be used to specify an XML namespace for the new entry. If you do not specify a namespace, the default namespace is used. However, the reader will not override log entries already defined by the server, with the following exception: If the server specifies an empty string ("") for the cs-media-role or cs-media-name entry, you can overwrite these entries. By default, a server running Windows Media Services 9 Series sends an empty string for cs-media-role, and the name of the file for cs-media-name.

To send the logging information to the server, call the **SendLogParams** method. To retrieve the log entries on the server, you must provide a custom logging plug-in, using the Windows Media Services 9 Series SDK. The default logging plug-in writes just the W3C-compliant log summary, so custom log entries are not included in the log.

## See also

[IWMReaderAdvanced4 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced4)

[IWMReaderAdvanced4::SendLogParams](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced4-sendlogparams)