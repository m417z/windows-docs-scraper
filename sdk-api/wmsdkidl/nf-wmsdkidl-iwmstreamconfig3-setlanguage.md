# IWMStreamConfig3::SetLanguage

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetLanguage** method sets the language for a stream using an RFC1766-compliant string.

## Parameters

### `pwszLanguageString` [in]

Pointer to a wide-character null-terminated string containing the language string.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

The string passed to this method must be an RFC1766-compliant string. Use of other strings will cause problems when streaming a file made with this profile. For a list of commonly used language strings, see [Language Strings](https://learn.microsoft.com/windows/desktop/wmformat/language-strings).

The new value will not take effect in the profile until you call [IWMProfile::ReconfigStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-reconfigstream).

## See also

[IWMStreamConfig3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig3)

[IWMStreamConfig3::GetLanguage](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig3-getlanguage)