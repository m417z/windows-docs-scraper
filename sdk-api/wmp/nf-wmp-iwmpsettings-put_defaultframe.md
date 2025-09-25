# IWMPSettings::put_defaultFrame

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_defaultFrame** method specifies the name of the frame used to display a URL that is received in a **ScriptCommand** event.

## Parameters

### `bstrDefaultFrame` [in]

**BSTR** containing the value of the name attribute of the target FRAME element.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If a target frame is specified in the **ScriptCommand** event itself, this method is ignored.

This method is ignored when using the Netscape Navigator Java applet. In Navigator, each URL script command received displays the URL in a new Web browser window, regardless of the value specified in **put_defaultFrame**.

**Windows Media Player 10 Mobile:** This method always returns E_INVALIDARG.

## See also

[IWMPEvents::ScriptCommand](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents-scriptcommand)

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)

[IWMPSettings::get_defaultFrame](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-get_defaultframe)