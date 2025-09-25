# IWMBandwidthSharing::SetType

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetType** method sets the type of sharing (exclusive or partial) for the bandwidth sharing object.

## Parameters

### `guidType` [in]

Globally unique identifier specifying the type of combined stream to be used. The only valid GUIDs are those in the following table.

| Bandwidth sharing type | Description |
| --- | --- |
| CLSID_WMBandwidthSharing_Exclusive | Only one of the constituent streams can be active at any given time. |
| CLSID_WMBandwidthSharing_Partial | The constituent streams can be active simultaneously. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The GUID passed in *guidType* is any value other than CLSID_BandwidthSharingExclusive or CLSID_BandwidthSharingPartial. |

## Remarks

The settings of a bandwidth sharing object are purely informational. They are not checked for accuracy.

## See also

[IWMBandwidthSharing Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbandwidthsharing)

[IWMBandwidthSharing::GetType](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmbandwidthsharing-gettype)