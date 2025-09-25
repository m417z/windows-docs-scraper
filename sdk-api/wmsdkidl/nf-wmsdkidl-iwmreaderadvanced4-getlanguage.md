# IWMReaderAdvanced4::GetLanguage

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetLanguage** method retrieves information about a language supported by an output. You must specify an output number and a language index, and this method will supply the RFC1766-compliant language string.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number for which you want to identify the language.

### `wLanguage` [in]

**WORD** containing the language index of the supported language for which you want the details.

### `pwszLanguageString` [out]

Pointer to a wide-character **null**-terminated string containing the RFC1766-compliant language string. Pass **NULL** to retrieve the size of the string, which will be returned in *pcbLanguageStringLength*.

### `pcchLanguageStringLength` [in, out]

Pointer to a **WORD** containing the size of *pwszLanguageString* in wide characters. This size includes the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When setting the language to use for an output, you must set the value of the **g_wszLanguage** setting to the language index passed to this method as *wLanguage*. Do not use the language index assigned by the language list, which will be different.

## See also

[IWMReaderAdvanced4 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced4)

[IWMReaderAdvanced4::GetLanguageCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced4-getlanguagecount)