# IWMPError::get_item

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_item** method retrieves a pointer to an **IWMPErrorItem** interface from the error queue.

## Parameters

### `dwIndex` [in]

**long** containing the index of the pointer to an **IWMPErrorItem** interface.

### `ppErrorItem` [out]

Pointer to a pointer to an **IWMPErrorItem** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Windows Media Player can generate a number of errors in response to an error condition. This method retrieves a specific error in the queue by using an index number. The index numbers for the error queue begin with zero.

You should set a **VARIANT_BOOL** to **FALSE** and pass it into **IWMPSettings::put_enableErrorDialogs** if you choose to display custom error messages.

## See also

[IWMPError Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmperror)

[IWMPErrorItem Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmperroritem)