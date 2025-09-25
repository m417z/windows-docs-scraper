# IWMReaderAdvanced4::GetMaxSpeedFactor

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetMaxSpeedFactor** method retrieves the maximum playback rate that can be delivered by the source. For network content, this value reflects the available bandwidth relative to the maximum bit rate of the content.

## Parameters

### `pdblFactor` [out]

Pointer to a variable that receives the maximum playback rate.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL pointer argument. |

## Remarks

If the server is using Fast Cache streaming, this method returns 1.0. For local files, including cached content, the method returns DBL_MAX. If no file is open, the method returns 0.0.

## See also

[IWMReaderAdvanced4 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced4)

[IWMReaderAdvanced4::IsUsingFastCache](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced4-isusingfastcache)