# IWMReaderAdvanced2::SetLogClientID

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetLogClientID** method specifies whether the reader logs the client's unique ID or an anonymous session ID.

## Parameters

### `fLogClientID` [in]

Specify one of the following values:

| Value | Description |
| --- | --- |
| TRUE | Send the client's unique ID. |
| FALSE | Send an anonymous session ID. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

When the reader object streams content over the network, it sends logging data to the originating server. This logging information includes a GUID that identifies the session. By default, the reader generates an anonymous session ID. If the value of *fLogClientID* is **TRUE**, the reader sends an ID that uniquely identifies the current user. The unique ID is stored in the registry under HKEY_CURRENT_USER. If the key does not exist, the reader creates it dynamically.

Anonymous session IDs always have the following form:

```
3300AD50-2C39-46c0-AE0A-XXXXXXXXXXXX
```

where the last six bytes are randomly generated.

## See also

[Client Logging](https://learn.microsoft.com/windows/desktop/wmformat/client)

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)

[IWMReaderAdvanced2::GetLogClientID](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced2-getlogclientid)