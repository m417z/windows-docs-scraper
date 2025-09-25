# IWMPMetadataPicture::get_mimeType

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_mimeType** method retrieves a pointer to a string specifying the MIME type of the metadata image.

## Parameters

### `pbstrMimeType` [out]

Pointer to a **BSTR** containing the mime type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPMetadataPicture Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmetadatapicture)