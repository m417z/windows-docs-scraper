# IWMPClosedCaption::get_captioningId

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_captioningId** method retrieves the name of the element displaying the captioning.

## Parameters

### `pbstrCaptioningID` [out]

Pointer to a **BSTR** containing the captioning ID.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The element name specified can be any HTML element in the webpage as long as it supports the **innerHTML** attribute. If the webpage contains multiple frames, the element name can only refer to an element in the same frame as the Windows Media Player control.

**Windows Media Player 10 Mobile:** This method always retrieves a **BSTR** containing an empty string.

## See also

[Adding Closed Captions to Digital Media](https://learn.microsoft.com/windows/desktop/WMP/adding-closed-captions-to-digital-media)

[IWMPClosedCaption Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpclosedcaption)

[IWMPClosedCaption::put_captioningId](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpclosedcaption-put_captioningid)