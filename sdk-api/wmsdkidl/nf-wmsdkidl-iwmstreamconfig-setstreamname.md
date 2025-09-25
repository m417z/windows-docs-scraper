# IWMStreamConfig::SetStreamName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetStreamName** method assigns a name to the stream represented by the stream configuration object.

## Parameters

### `pwszStreamName` [in]

Pointer to a wide-character **null**-terminated string containing the stream name. Stream names are limited to 256 wide characters.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pwszStreamName* parameter is **NULL**. |

## Remarks

This method is purely for the convenience of the developer during profile manipulation and file writing. The name assigned using this method is not stored in the header section of ASF files created using the profile and is therefore not available through the reader object or synchronous reader object.

The new value will not take effect in the profile until you call [IWMProfile::ReconfigStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-reconfigstream).

## See also

[IWMStreamConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig)

[IWMStreamConfig::GetStreamName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig-getstreamname)