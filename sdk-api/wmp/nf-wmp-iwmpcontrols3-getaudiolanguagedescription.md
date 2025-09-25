# IWMPControls3::getAudioLanguageDescription

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getAudioLanguageDescription** method retrieves the description for the audio language corresponding to the specified one-based index.

## Parameters

### `lIndex` [in]

**long** specifying the one-based audio language index.

### `pbstrLangDesc` [out]

Pointer to a **BSTR** containing the description.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

For Windows Media-based content, properties and methods related to language selection support only a single output.

Use the **get_audioLanguageCount** method to retrieve the number of supported audio languages, and then access an audio language individually by using a one-based index.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPControls3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols3)

[IWMPControls3::getAudioLanguageID](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols3-getaudiolanguageid)

[IWMPControls3::getLanguageName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols3-getlanguagename)

[IWMPControls3::get_audioLanguageCount](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols3-get_audiolanguagecount)

[IWMPControls3::get_currentAudioLanguage](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols3-get_currentaudiolanguage)

[IWMPControls3::get_currentAudioLanguageIndex](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmp/nf-wmp-iwmpcontrols3-get_currentaudiolanguageindex)

[IWMPControls3::put_currentAudioLanguage](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols3-put_currentaudiolanguage)