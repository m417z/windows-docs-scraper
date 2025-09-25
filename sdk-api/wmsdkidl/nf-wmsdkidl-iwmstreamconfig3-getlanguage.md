# IWMStreamConfig3::GetLanguage

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetLanguage** method retrieves the RFC1766-compliant language string for the stream.

## Parameters

### `pwszLanguageString` [out]

Pointer to a wide-character **null**-terminated string containing the language string. Pass **NULL** to retrieve the size of the string, which is returned in *pcchLanguageStringLength*.

### `pcchLanguageStringLength` [in, out]

Pointer to a **WORD** containing the size of the language string in wide characters. This size includes the terminating **null** character.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IWMStreamConfig3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig3)

[IWMStreamConfig3::SetLanguage](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig3-setlanguage)