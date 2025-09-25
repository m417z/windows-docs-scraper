# IWMProfile3::RemoveBandwidthSharing

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **RemoveBandwidthSharing** method removes a bandwidth sharing object from the profile. If you do not already have a pointer to the [IWMBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbandwidthsharing) interface of the object you want to remove, you must obtain one with a call to [IWMProfile3::GetBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-getbandwidthsharing).

## Parameters

### `pBS` [in]

Pointer to a bandwidth sharing object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pBS* is **NULL**.<br><br>OR<br><br>The bandwidth sharing object pointed to by *pBS* is not part of the profile. |

## Remarks

This method does not release the bandwidth sharing object from memory. You must make a call to the **Release** method.

## See also

[IWMProfile3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[IWMProfile3::AddBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-addbandwidthsharing)