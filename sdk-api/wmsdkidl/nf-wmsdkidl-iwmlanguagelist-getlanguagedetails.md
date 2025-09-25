# IWMLanguageList::GetLanguageDetails

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetLanguageDetails** method retrieves the RFC 1766-compliant language tag for an entry in the list of supported languages.

## Parameters

### `wIndex` [in]

**WORD** containing the index in the language list.

### `pwszLanguageString` [out]

Pointer to the RFC 1766-compliant language tag of the language list entry specified by *wIndex*. Pass **NULL** to retrieve the length of the string, which will be returned in *pcbLanguageStringLength*.

### `pcchLanguageStringLength` [in, out]

Pointer to a **WORD** containing the length of the language string, in wide characters. This length includes the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

For a list of common RFC 1766-compliant language identifiers, see [Language Strings](https://learn.microsoft.com/windows/desktop/wmformat/language-strings).

## See also

[IWMLanguageList Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmlanguagelist)