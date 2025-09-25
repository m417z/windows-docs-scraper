# IWMProfile3::AddBandwidthSharing

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddBandwidthSharing** method adds an existing bandwidth sharing object to the profile. Bandwidth sharing objects are created with a call to [CreateNewBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-createnewbandwidthsharing). You must configure the bandwidth sharing object before adding it to the profile.

## Parameters

### `pBS` [in]

Pointer to the [IWMBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbandwidthsharing) interface of a bandwidth sharing object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pBS* is **NULL**.<br><br>OR<br><br>The bandwidth sharing object has a bandwidth sharing type value that is not valid. |
| **E_UNEXPECTED** | An unknown error occurred while adding the bandwidth sharing object to the internal collection in the profile. |
| **E_OUTOFMEMORY** | The method was unable to allocate memory. |
| **NS_E_NO_STREAM** | The bandwidth sharing object contains no streams. |

## Remarks

Making a call to **AddBandwidthSharing** without first using the methods of **IWMBandwidthSharing** to configure the bandwidth sharing object will result in an error.

## See also

[Bandwidth Sharing Object](https://learn.microsoft.com/windows/desktop/wmformat/bandwidth-sharing-object)

[IWMProfile3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[IWMProfile3::GetBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-getbandwidthsharing)

[IWMProfile3::RemoveBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-removebandwidthsharing)