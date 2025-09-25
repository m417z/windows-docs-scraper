# IWMPClosedCaption2::getSAMIStyleName

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getSAMIStyleName** method retrieves the name of a style supported by the current SAMI file.

## Parameters

### `nIndex` [in]

**long** containing the index of the style name to retrieve.

### `pbstrName` [out]

Pointer to a **BSTR** containing the name of the style as specified in the SAMI file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The styles in a SAMI file are indexed in the order shown in the file, starting with zero.

This method cannot be used until a digital media file is open.

**Windows Media Player 10 Mobile:** This method always retrieves a **BSTR** containing an empty string.

## See also

[Adding Closed Captions to Digital Media](https://learn.microsoft.com/windows/desktop/WMP/adding-closed-captions-to-digital-media)

[IWMPClosedCaption2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpclosedcaption2)

[IWMPClosedCaption::get_SAMIStyle](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpclosedcaption-get_samistyle)