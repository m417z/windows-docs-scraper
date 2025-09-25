# IWMPPlayer::put_uiMode

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_uiMode** method specifies a value indicating which controls are shown in the user interface.

## Parameters

### `bstrMode` [in]

**BSTR** containing one of the following values.

| Value | Description | Audio example | Video example |
| --- | --- | --- | --- |
| invisible | Windows Media Player is embedded without any visible user interface (controls, video, or visualization window). | (Nothing is displayed.) | (Nothing is displayed.) |
| none | Windows Media Player is embedded without controls, and with only the video or visualization window displayed. | ![uiMode="none" with audio](https://learn.microsoft.com/windows/win32/api/wmp/images/uimode_none_audio_v11.png) | ![uiMode="none" with video](https://learn.microsoft.com/windows/win32/api/wmp/images/uimode_none_video_v11.png) |
| mini | Windows Media Player is embedded with the status window, play/pause, stop, mute, and volume controls shown in addition to the video or visualization window. | ![uiMode="mini" with audio](https://learn.microsoft.com/windows/win32/api/wmp/images/uimode_mini_audio_v11.png) | ![uiMode="mini" with video](https://learn.microsoft.com/windows/win32/api/wmp/images/uimode_mini_video_v11.png) |
| full | Default. Windows Media Player is embedded with the status window, seek bar, play/pause, stop, mute, next, previous, fast forward, fast reverse, and volume controls in addition to the video or visualization window. | ![uiMode="full" with audio](https://learn.microsoft.com/windows/win32/api/wmp/images/uimode_full_audio_v11.png) | ![uiMode="full" with video](https://learn.microsoft.com/windows/win32/api/wmp/images/uimode_full_video_v11.png) |
| custom | Windows Media Player is embedded with a custom user interface. Can only be used in C++ programs. | (Custom user interface is displayed.) | (Custom user interface is displayed.) |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method specifies the appearance of the embedded Windows Media Player. When the **BSTR** specified in **put_uiMode** is set to "none", "mini", or "full", a window is present for the display of video clips and audio visualizations. This window can be hidden in mini or full mode by setting the **height** attribute of the **OBJECT** tag to 40, which is measured from the bottom, and leaves the controls portion of the user interface visible. If no embedded interface is desired, set both the **width** and **height** attributes to zero.

If the **BSTR** specified in **put_uiMode** is set to "invisible", no user interface is displayed, but space is still reserved on the page as specified by **width** and **height**. This is useful for retaining page layout whenever the UI mode changes. Additionally, the reserved space is transparent, so any elements layered behind the control will be visible.

If the **BSTR** specified in **put_uiMode** is set to "full" or "mini", Windows Media Player displays transport controls in full-screen mode. If the **BSTR** specified in **put_uiMode** is set to "none", no controls are displayed in full-screen mode.

If the window is visible and audio content is being played, the visualization displayed will be the one most recently used in Windows Media Player.

If the **BSTR** specified in **put_uiMode** is set to "custom" in a C++ program that implements **IWMPRemoteMediaServices**, the skin file indicated by **IWMPRemoteMediaServices::GetCustomUIMode** is displayed.

During full-screen playback, Windows Media Player hides the mouse cursor when the **VARIANT_BOOL** retrieved from **IWMPPlayer::get_enableContextMenu** equals **FALSE** and the **BSTR** retrieved from **IWMPPlayer::get_uiMode** equals "none".

**Windows Media Player 10 Mobile:** This method only specifies a **BSTR** set to "none" or "full". On Smartphone devices, only playback status and a counter are displayed when setting **uiMode** to "full".

## See also

[IWMPPlayer Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayer)

[IWMPPlayer::get_enableContextMenu](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer-get_enablecontextmenu)

[IWMPPlayer::get_uiMode](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplayer-get_uimode)

[IWMPRemoteMediaServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpremotemediaservices)

[IWMPRemoteMediaServices::GetCustomUIMode](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpremotemediaservices-getcustomuimode)