# IWMProfileManager::CreateEmptyProfile

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CreateEmptyProfile** method creates an empty profile object. You can use the interfaces of the profile object to configure the profile. When you are done configuring the profile, you can save it to a string using [IWMProfileManager::SaveProfile](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofilemanager-saveprofile).

## Parameters

### `dwVersion` [in]

**DWORD** containing one member of the [WMT_VERSION](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_version) enumeration type.

### `ppProfile` [out]

Pointer to a pointer to an [IWMProfile](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | There is not enough available memory. |
| **E_INVALIDARG** | The *ppProfile* parameter is **NULL**. |

## Remarks

Use this method to create any profile that uses the Windows Media® Audio and Video 9 Series codecs. For more information, see [Reusing Stream Configurations](https://learn.microsoft.com/windows/desktop/wmformat/reusing-stream-configurations).

## See also

[IWMProfileManager Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofilemanager)

[WMT_VERSION](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_version)