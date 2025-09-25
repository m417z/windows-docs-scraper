# IWMProfile3::GetBandwidthSharing

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetBandwidthSharing** method retrieves a bandwidth sharing object from a profile.

## Parameters

### `dwBSIndex` [in]

**DWORD** containing the index number of the bandwidth sharing object you want to retrieve.

### `ppBS` [out]

Pointer to receive the address of the [IWMBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbandwidthsharing) interface of the object requested.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *ppBS* is **NULL**.<br><br>OR<br><br>*dwBSIndex* refers to an invalid index number. |
| **E_OUTOFMEMORY** | The method is unable to allocate memory for the bandwidth sharing object. |

## Remarks

Bandwidth sharing objects in a profile are assigned sequential index numbers in the order in which they were added to the profile. When you create multiple bandwidth sharing objects for a profile, you should keep track of the contents of each one. Otherwise you will have to examine each one to ascertain its settings.

## See also

[Bandwidth Sharing Object](https://learn.microsoft.com/windows/desktop/wmformat/bandwidth-sharing-object)

[IWMProfile3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[IWMProfile3::AddBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-addbandwidthsharing)

[IWMProfile3::GetBandwidthSharingCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-getbandwidthsharingcount)

[IWMProfile3::RemoveBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-removebandwidthsharing)