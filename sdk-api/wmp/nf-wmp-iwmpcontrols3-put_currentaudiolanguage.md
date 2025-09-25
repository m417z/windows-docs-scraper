# IWMPControls3::put_currentAudioLanguage

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_currentAudioLanguage** method specifies the locale identifier (LCID) of the audio language for playback.

## Parameters

### `lLangID` [in]

**long** containing the LCID.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

An LCID uniquely identifies a particular language dialect, called a locale.

For Windows Media-based content, properties and methods related to language selection support only a single output.

When working with DVD content, specifying an LCID will cause the first available audio track having the specified language ID to be selected.

**Windows Media Player 10 Mobile:** This method only accepts a **long** set to 0 (the language-neutral LCID), otherwise an E_INVALIDARG **HRESULT** is returned.

## See also

[IWMPControls3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols3)

[IWMPControls3::getAudioLanguageDescription](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols3-getaudiolanguagedescription)

[IWMPControls3::getAudioLanguageID](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols3-getaudiolanguageid)

[IWMPControls3::getLanguageName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols3-getlanguagename)

[IWMPControls3::get_currentAudioLanguage](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols3-get_currentaudiolanguage)

[IWMPControls3::put_currentAudioLanguageIndex](https://learn.microsoft.com/previous-versions/aa388723(v=vs.85))