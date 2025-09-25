# IWMPCdromBurn::startBurn

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **startBurn** method burns the CD.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The burn state should be wmpbsReady or wmpbsStopped before calling this method.

This method will not work if the CD drive is not a burner, or if the disc in the drive is not writable. Use [IWMPCdromBurn::isAvailable](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcdromburn-isavailable) to determine whether a CD can be burned.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPCdromBurn Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromburn)

[IWMPCdromBurn::get_burnState](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcdromburn-get_burnstate)

[IWMPCdromBurn::stopBurn](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcdromburn-stopburn)