# IWMPClosedCaption::get_SAMILang

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_SAMILang** method retrieves the language displayed for closed captioning.

## Parameters

### `pbstrSAMILang` [out]

Pointer to a **BSTR** containing the language.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

A SAMI file can contain text for one or many languages. The languages available for closed captioning are defined between the \<STYLE> and \</STYLE> tags in the SAMI file. A language identifier is specified by a unique alphanumeric string that is preceded by a period (.). The name specified for a language can be any string. For example, the following could be used to define US English:

```

.ENUSCC {Name:'English Captions' lang: en-US; SAMIType:CC;}

```

If no SAMI language is specified, the first language defined in the SAMI file is used by default.

The value you specify using **put_SAMILang** must match the **Name** attribute in the language specifier.

**Windows Media Player 10 Mobile:** This method always retrieves a **BSTR** containing an empty string.

## See also

[Adding Closed Captions to Digital Media](https://learn.microsoft.com/windows/desktop/WMP/adding-closed-captions-to-digital-media)

[IWMPClosedCaption Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpclosedcaption)

[IWMPClosedCaption::put_SAMILang](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpclosedcaption-put_samilang)