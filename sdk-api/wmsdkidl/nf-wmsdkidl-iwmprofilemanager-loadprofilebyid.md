# IWMProfileManager::LoadProfileByID

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **LoadProfileByID** method loads a system profile identified by its globally unique identifier. To load a custom profile, use [IWMProfileManager::LoadProfileByData](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofilemanager-loadprofilebydata).

## Parameters

### `guidProfile` [in]

**GUID** identifying the profile. For more information, see the table of defined constants in [Using System Profiles](https://learn.microsoft.com/windows/desktop/wmformat/using-system-profiles).

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

Only system profiles have IDs. Because there are no system profiles for the Windows Media 9 Series codecs, this method is primarily useful for obtaining version 8 system profiles that you will convert to custom profiles using the Windows Media 9 Series codecs. For more information, see [Reusing Stream Configurations](https://learn.microsoft.com/windows/desktop/wmformat/reusing-stream-configurations).

## See also

[IWMProfileManager Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofilemanager)

[Using System Profiles](https://learn.microsoft.com/windows/desktop/wmformat/using-system-profiles)