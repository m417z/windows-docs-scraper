# IWMLanguageList::AddLanguageByRFC1766String

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddLanguageByRFC1766String** method adds an entry to the list of supported languages for a file based upon a language tag compliant with RFC 1766.

## Parameters

### `pwszLanguageString` [in]

Pointer to a wide-character null-terminated string containing an RFC 1766-compliant language tag.

### `pwIndex` [out]

Pointer to a **WORD**. On output, this will be set to the index assigned to the added language entry.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

For a list of common RFC 1766-compliant language identifiers, see [Language Strings](https://learn.microsoft.com/windows/desktop/wmformat/language-strings).

## See also

[IWMLanguageList Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmlanguagelist)