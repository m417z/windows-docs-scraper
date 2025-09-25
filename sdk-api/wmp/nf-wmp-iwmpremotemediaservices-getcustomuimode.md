# IWMPRemoteMediaServices::GetCustomUIMode

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCustomUIMode** method is called by Windows Media Player to retrieve the location of a skin file to apply to the Windows Media Player control.

## Parameters

### `pbstrFile` [out]

Pointer to a **BSTR** containing the location of the skin file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Value | Description |
| --- | --- |
| S_OK | The method succeeded. |

## Remarks

This method allows you to customize the user interface of the embedded control by using Windows Media Player skin technology. Skins used in this way can communicate with the host of the control through a scriptable object retrieved automatically by Windows Media Player through the **IWMPRemoteMediaServices::GetScriptableObject** method.

To apply a skin file to the embedded control, you must call **IWMPPlayer.put_uiMode** with a value of "custom". Your implementation of **GetCustomUIMode** must also return a value of "file://" followed by the path and file name of a skin definition file located on the local computer.

The embedded Windows Media Player control does not have to be remoted to use this method.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPRemoteMediaServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpremotemediaservices)

[IWMPRemoteMediaServices::GetScriptableObject](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpremotemediaservices-getscriptableobject)

[Using Skins with the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/using-skins-with-the-windows-media-player-control)