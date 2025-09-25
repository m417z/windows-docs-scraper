# IWMProfileManager::SaveProfile

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SaveProfile** method saves a profile into an XML-formatted string.

## Parameters

### `pIWMProfile` [in]

Pointer to the [IWMProfile](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile) interface of the object containing the profile data to be saved.

### `pwszProfile` [in]

Pointer to a wide-character **null**-terminated string containing the profile. Set this to **NULL** to retrieve the length of string required.

### `pdwLength` [in, out]

On input, specifies the length of the *pwszProfile* string. On output, if the method succeeds, specifies a pointer to a **DWORD** containing the number of characters, including the terminating **null** character, required to hold the profile.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | There is not enough available memory. |
| **E_INVALIDARG** | Either the *pIWMProfile* or *pdwLength* parameter is **NULL**. |

## Remarks

You should make two calls to **SaveProfile**. On the first call, pass **NULL** as *pwszProfile*. On return, the value of *pdwLength* is set to the length required to hold the profile in string form. Then you can allocate the required amount of memory for the buffer and pass a pointer to it as *pwszProfile* on the second call.

This string contains all the profile information. It must not be displayed to users, and should not be altered. To change the settings in a saved profile, load it using the profile manager and change the settings using the profile object and related objects.

To save a custom profile for later use, you must save the content of the returned string in a .prx file. For more information on .prx files, see [Profiles](https://learn.microsoft.com/windows/desktop/wmformat/profiles).

To load a saved custom profile, copy the contents of the profile from the .prx file to a string and use [IWMProfileManager::LoadProfileByData](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofilemanager-loadprofilebydata).

## See also

[IWMProfileManager Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofilemanager)