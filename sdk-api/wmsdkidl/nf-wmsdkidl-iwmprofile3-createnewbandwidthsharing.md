# IWMProfile3::CreateNewBandwidthSharing

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CreateNewBandwidthSharing** method creates a new bandwidth sharing object.

## Parameters

### `ppBS` [out]

Pointer to a variable that receives the address of the [IWMBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbandwidthsharing) interface of the new object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *ppBS* is **NULL**. |
| **E_OUTOFMEMORY** | The method is unable to allocate memory for the new object. |

## Remarks

To make use of the bandwidth sharing object, you must add it to the profile with a call to [AddBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-addbandwidthsharing). A bandwidth sharing object cannot exist on its own. If you release the profile object without adding the bandwidth sharing object to the profile, you will lose the bandwidth sharing object.

You must configure the bandwidth sharing object before you use **AddBandwidthSharing** to include the bandwidth sharing object in the profile. For more information about configuring bandwidth sharing objects, see [IWMBandwidthSharing Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbandwidthsharing).

## See also

[Bandwidth Sharing Object](https://learn.microsoft.com/windows/desktop/wmformat/bandwidth-sharing-object)

[IWMBandwidthSharing Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbandwidthsharing)

[IWMProfile3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[IWMProfile3::AddBandwidthSharing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile3-addbandwidthsharing)