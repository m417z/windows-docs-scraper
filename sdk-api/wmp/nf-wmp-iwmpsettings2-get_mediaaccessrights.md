# IWMPSettings2::get_mediaAccessRights

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_mediaAccessRights** method retrieves a value indicating the permissions currently granted for library access.

## Parameters

### `pbstrRights` [out]

Pointer to a **BSTR** containing one of the following values.

| Value | Description |
| --- | --- |
| none | Current item access rights only. |
| read | Read access rights only. |
| full | Read/Write access rights. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

A webpage must first request permission from the user to read information from or write data to the library. This means that certain methods, properties, and events will be inaccessible from code if the appropriate access rights have not been granted. To obtain access rights, the application calls **IWMPSettings2::get_requestMediaAccessRights**, passing a parameter that specifies the desired access rights level.

Applications running on the user's computer always have full access rights.

**Windows Media Player 10 Mobile:** This method always retrieves a **BSTR** containing the string "full".

## See also

[IWMPSettings2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings2)

[IWMPSettings2::requestMediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-requestmediaaccessrights)