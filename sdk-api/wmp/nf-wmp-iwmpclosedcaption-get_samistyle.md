# IWMPClosedCaption::get_SAMIStyle

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_SAMIStyle** method retrieves the closed captioning style.

## Parameters

### `pbstrSAMIStyle` [out]

Pointer to a **BSTR** containing the SAMI style.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

A SAMI file can contain several format style definitions. SAMI styles are defined between the <STYLE> and </STYLE> tags in the SAMI file. A style is defined with a text string preceded by a # character. For example, the following code specifies text formatting to be used for a style.

```

#Emphasis1 {Name: Big Bold Italic; font-size: 14pt; text-align: center;
            color: blue; font-family: sans-serif; font-weight: bold;
            font-style: italic;}

```

If no SAMI style is specified, the first style defined in the SAMI file is used by default.

**Windows Media Player 10 Mobile:** This method always retrieves a **BSTR** containing an empty string.

## See also

[Adding Closed Captions to Digital Media](https://learn.microsoft.com/windows/desktop/WMP/adding-closed-captions-to-digital-media)

[IWMPClosedCaption Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpclosedcaption)

[IWMPClosedCaption::put_SAMIStyle](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpclosedcaption-put_samistyle)