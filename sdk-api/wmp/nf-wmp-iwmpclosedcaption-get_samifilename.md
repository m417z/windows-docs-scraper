# IWMPClosedCaption::get_SAMIFileName

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_SAMIFileName** method retrieves the name of the file containing the information needed for closed captioning.

## Parameters

### `pbstrSAMIFileName` [out]

Pointer to a **BSTR** containing the name of the Synchronized Accessible Media Interchange (SAMI) file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The SAMI file must use an .smi or .sami file name extension.

If you do not specify a value by using **IWMPClosedCaption::put_SAMIFileName**, the **get_SAMIFileName** method retrieves a **BSTR** containing the default file or URL associated with the current media item. This association can occur when a SAMI file is specified by using the *sami* URL parameter, or automatically when the SAMI file has the same name as the digital media file (except for the file name extension). If there is no default SAMI file associated with the current media, **get_SAMIFileName** retrieves an empty string ("").

If you want Windows Media Player to use the default SAMI file associated with a particular media item, call **IWMPClosedCaption::put_SAMIFileName** using an empty string ("") before you play the next media item.

**Windows Media Player 10 Mobile:** This method always retrieves a **BSTR** containing an empty string.

## See also

[Adding Closed Captions to Digital Media](https://learn.microsoft.com/windows/desktop/WMP/adding-closed-captions-to-digital-media)

[IWMPClosedCaption Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpclosedcaption)

[IWMPClosedCaption::put_SAMIFileName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpclosedcaption-put_samifilename)

[IWMPCore::close](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-close)