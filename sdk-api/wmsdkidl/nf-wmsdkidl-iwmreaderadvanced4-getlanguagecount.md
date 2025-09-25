# IWMReaderAdvanced4::GetLanguageCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetLanguageCount** method retrieves the total number of languages supported by an output. Only outputs associated with streams mutually exclusive by language will have more than one supported language.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `pwLanguageCount` [out]

Pointer to a **WORD** containing the language count.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method should not be confused with [IWMLanguageList::GetLanguageCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmlanguagelist-getlanguagecount). This method retrieves supported languages for a specific output. The methods of the [IWMLanguageList](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmlanguagelist) interface manipulate a list of languages at the file level. An individual output might not support all of the languages in the language list.

## See also

[IWMReaderAdvanced4 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced4)

[IWMReaderAdvanced4::GetLanguage](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced4-getlanguage)