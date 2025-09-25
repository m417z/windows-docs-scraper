# IWMPRemoteMediaServices::GetScriptableObject

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetScriptableObject** method is called by Windows Media Player to retrieve a name and interface pointer for an object that can be called from the script code within a skin.

## Parameters

### `pbstrName` [out]

Pointer to a **BSTR** containing the name of the scriptable object.

### `ppDispatch` [out]

Pointer to a pointer to the **IDispatch** interface of the scriptable object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Value | Description |
| --- | --- |
| S_OK | The method succeeded. |

## Remarks

The user interface of an embedded control can be customized by using Windows Media Player skin technology. You must specify a skin file location by using the **IWMPRemoteMediaServices::GetCustomUIMode** method. Skins used in this way can communicate with the host of the control through a scriptable object retrieved automatically by Windows Media Player through the **IWMPRemoteMediaServices::GetScriptableObject** method.

The embedded Windows Media Player control does not have to be remoted to use this method.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPRemoteMediaServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpremotemediaservices)

[IWMPRemoteMediaServices::GetCustomUIMode](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpremotemediaservices-getcustomuimode)

[Using Skins with the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/using-skins-with-the-windows-media-player-control)