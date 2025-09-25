# IWMPLibrary2::getItemInfo

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getItemInfo** method retrieves the value of the **LibraryID** attribute.

## Parameters

### `bstrItemName` [in]

**BSTR** containing the attribute name. Set the value of this parameter to "LibraryID".

### `pbstrVal` [out]

Pointer to a **BSTR** that receives the value of the **LibraryID** attribute.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **LibraryID** attribute retrieved by this method is the same as the **LibraryID** attribute that [IWMPMedia::getItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-getiteminfo) retrieves for each media item in the library.

## See also

[IWMPLibrary2](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmplibrary2)