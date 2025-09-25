# IWMPSettings2::requestMediaAccessRights

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **requestMediaAccessRights** method requests a specified level of access to the library.

## Parameters

### `bstrDesiredAccess` [in]

**BSTR** containing the one of the following values.

| Value | Description |
| --- | --- |
| none | Current item access rights only. |
| read | Read access rights only. |
| full | Read/Write access rights. |

### `pvbAccepted` [out]

Pointer to a **VARIANT_BOOL** indicating whether the requested access rights were granted.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

A webpage must first request permission from the user to read information from or write data to the library. Invoking this method prompts the user with a dialog box that requests the specified permission level. This means that certain methods, properties, and events will be inaccessible from code if the appropriate access rights have not been granted. The current access rights level can be retrieved by using **IWMPSettings2::get_mediaAccessRights**.

Applications running on the user's computer are not required to use this method.

**Windows Media Player 10 Mobile:** This method always retrieves a **VARIANT_BOOL** set to **TRUE**.

## See also

[IWMPSettings2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings2)

[IWMPSettings2::get_mediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-get_mediaaccessrights)