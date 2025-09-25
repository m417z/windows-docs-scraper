# IWMPClosedCaption::put_SAMIFileName

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_SAMIFileName** method specifies the name of the file containing the information needed for closed captioning.

## Parameters

### `bstrSAMIFileName` [in]

**BSTR** containing the SAMI file name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The SAMI file must use an .smi or .sami file name extension.

Once you specify a value using **put_SAMIFileName**, that value persists until you specify a new value (or until a new media item is opened by using the *sami* URL parameter). Therefore, you must specify a new value with this method before you play each new media item. The new value will take effect when the next media item is opened (or when **IWMPCore::close** is called). Specifying a new value by using **put_SAMIFileName** has no effect on the current media item.

**Windows Media Player 10 Mobile:** This method always returns E_INVALIDARG.

## See also

[Adding Closed Captions to Digital Media](https://learn.microsoft.com/windows/desktop/WMP/adding-closed-captions-to-digital-media)

[IWMPClosedCaption Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpclosedcaption)

[IWMPClosedCaption::get_SAMIFileName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpclosedcaption-get_samifilename)

[IWMPCore::close](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-close)