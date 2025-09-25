# IWMWriter::SetProfileByID

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetProfileByID** method specifies the profile to use for the current writing task, identifying the profile by its GUID.

## Parameters

### `guidProfile` [in]

GUID of the profile.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

Only system profiles have IDs. Use the methods of the **IWMProfileManager** interface to examine system profiles. The header file Wmsysprf.h has a list of system profiles and their IDs.

## See also

[IWMProfileManager Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofilemanager)

[IWMWriter Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriter)

[IWMWriter::SetProfile](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-setprofile)

[To Use Profiles with the Writer](https://learn.microsoft.com/windows/desktop/wmformat/to-use-profiles-with-the-writer)