# IWMPLibraryServices::getLibraryByType

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getLibraryByType** method retrieves a pointer to an **IWMPLibrary** interface that represents the library that has the specified type and index.

## Parameters

### `wmplt` [in]

**WMPLibraryType** enumeration value that specifies the type of library to retrieve.

### `lIndex` [in]

A **long** containing the index of the library to retrieve.

### `ppIWMPLibrary` [out]

Address of a variable that receives a pointer to the retrieved **IWMPLibrary** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

There is only one local library and disc libraries are available only on data CDs and DVDs that contain media content.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPLibrary Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmplibrary)

[IWMPLibraryServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmplibraryservices)

[WMPLibraryType](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmplibrarytype)