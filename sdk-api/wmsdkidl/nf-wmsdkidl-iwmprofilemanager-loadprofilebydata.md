# IWMProfileManager::LoadProfileByData

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **LoadProfileByData** method creates a profile object and populates it with data from a stored string. You must use this method to manipulate custom profiles. System profiles should be accessed using either [LoadProfileByID](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofilemanager-loadprofilebyid) or [LoadSystemProfile](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofilemanager-loadsystemprofile).

## Parameters

### `pwszProfile` [in]

Pointer to a wide-character **null**-terminated string containing the profile. Profile strings are limited to 153600 wide characters.

### `ppProfile` [out]

Pointer to a pointer to an [IWMProfile](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | There is not enough available memory. |
| **E_INVALIDARG** | Either the *ppProfile* or *pwszProfile* parameter is **NULL**. |

## Remarks

This string must match an XML-formatted string created by [IWMProfileManager::SaveProfile](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofilemanager-saveprofile). By convention, when such strings are saved to disk they are given the ".prx" extension.

## See also

[IWMProfileManager Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofilemanager)