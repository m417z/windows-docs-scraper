# IWMPErrorItem::get_errorContext

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_errorContext** method retrieves a value indicating the context of the error.

## Parameters

### `pvarContext` [out]

Pointer to a **VARIANT** containing the error context.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The error context is information that is used by Microsoft to provide additional information for technical support personnel.

**Windows Media Player 10 Mobile:** This method always retrieves a **VARIANT** with the **vt** field set to VT_EMPTY.

## See also

[IWMPErrorItem Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmperroritem)