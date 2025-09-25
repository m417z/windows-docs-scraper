# IWMProfile::GetName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetName** method retrieves the name of a profile.

## Parameters

### `pwszName` [out]

Pointer to a wide-character **null**-terminated string containing the name. Pass **NULL** to retrieve the length of the name.

### `pcchName` [in, out]

On input, specifies the length of the *pwszName* buffer. On output, if the method succeeds, specifies a pointer to the length of the name, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pcchName* parameter is **NULL**. |
| **ASF_E_BUFFERTOOSMALL** | The *pwszName* parameter is not large enough. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

You should make two calls to **GetName**. On the first call, pass **NULL** as *pwszName*. On return, the value pointed to by *pcchName* is set to the number of wide characters, including the terminating **null** character, required to hold the profile name. Then you can allocate the required amount of memory for the string and pass a pointer to it as *pwszName* on the second call.

Profiles have names and descriptions that are used when displaying lists of profiles.

## See also

[IWMProfile Interface](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile)

[IWMProfile2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile2)

[IWMProfile3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[IWMProfile::SetName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-setname)