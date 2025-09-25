# IWMPSettings::get_invokeURLs

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_invokeURLs** method retrieves a value indicating whether URL events should launch a Web browser.

## Parameters

### `pfInvokeURLs` [out]

Pointer to a **VARIANT_BOOL** indicating whether URL events should launch a Web browser. The default is **TRUE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Digital media files and streams can contain URL script commands. When a URL script command is sent to the Windows Media Player control, it is passed first to the **ScriptCommand** event handler regardless of the value retrieved by **get_invokeURLs**. After **ScriptCommand** exits, Windows Media Player checks the **VARIANT_BOOL** retrieved by **get_invokeURLs** to determine whether to launch the default Web browser with the URL. You can selectively display URLs by checking them in **ScriptCommand** and setting **put_invokeURLs** as needed.

**Windows Media Player 10 Mobile:** This method always retrieves a **VARIANT_BOOL** set to **FALSE**.

## See also

[IWMPEvents::ScriptCommand](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents-scriptcommand)

[IWMPSettigns::put_invokeURLs](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_invokeurls)

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)