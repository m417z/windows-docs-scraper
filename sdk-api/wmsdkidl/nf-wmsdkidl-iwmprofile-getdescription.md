# IWMProfile::GetDescription

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetDescription** method retrieves the profile description. The description is a string that contains an explanation of what the profile should be used for.

## Parameters

### `pwszDescription` [out]

Pointer to a wide-character **null**-terminated string containing the description. Pass **NULL** to retrieve the required length for the description.

### `pcchDescription` [in, out]

On input, specifies the length of the *pwszDescription* string. On output, if the method succeeds, specifies a pointer to a count of the number of characters in the name, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pcchName* parameter is **NULL**. |
| **ASF_E_BUFFERTOOSMALL** | The buffer pointed to by the *pwszDescription* parameter is not large enough. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

You should make two calls to **GetDescription**. On the first call, pass **NULL** as *pwszDescription*. On return, the value pointed to by *pcchDescription* is set to the number of wide characters, including the terminating **null** character, required to hold the profile description. Then you can allocate the required amount of memory for the string and pass a pointer to it as *pwszDescription* on the second call.

## See also

[IWMProfile Interface](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile)

[IWMProfile2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile2)

[IWMProfile3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[IWMProfile::SetDescription](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-setdescription)