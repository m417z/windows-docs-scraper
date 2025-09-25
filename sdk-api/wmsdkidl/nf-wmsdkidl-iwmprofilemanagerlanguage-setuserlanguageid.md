# IWMProfileManagerLanguage::SetUserLanguageID

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetUserLanguageID** method sets the language of the system profiles that will be parsed by the profile manager object.

## Parameters

### `wLangID` [in]

**WORD** containing the language identifier (LANGID) of the language you want to use.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_NOMATCHING_ELEMENT** | The specified LANGID represents a locality not supported by a localized set of system profiles. |

## Remarks

English – United States (0x0409) is the default language. This method will also return NS_E_MOMATCHING_ELEMENT for all languages except US English if you have not moved the correct .prx file into the system root directory.

## See also

[IWMProfileManagerLanguage Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofilemanagerlanguage)

[IWMProfileManagerLanguage::GetUserLanguageID](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofilemanagerlanguage-getuserlanguageid)

[Localized System Profiles](https://learn.microsoft.com/windows/desktop/wmformat/localized-system-profiles)

[Working with Localized System Profiles](https://learn.microsoft.com/windows/desktop/wmformat/working-with-localized-system-profiles)