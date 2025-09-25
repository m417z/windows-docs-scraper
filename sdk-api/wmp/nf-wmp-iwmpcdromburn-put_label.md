# IWMPCdromBurn::put_label

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_label** method specifies the label string for the CD volume.

## Parameters

### `bstrLabel` [in]

**BSTR** that contains the label string for the CD volume.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Due to the way CD labels are stored, the label of the CD may be shorter than the length of *bstrLabel*. If *bstrLabel* is longer than the maximum length of a CD label, the text will be truncated.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPCdromBurn Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromburn)

[IWMPCdromBurn::get_label](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcdromburn-get_label)