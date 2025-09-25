# IWMReaderPlaylistBurn::InitPlaylistBurn

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **InitPlaylistBurn** method initiates the playlist burning process, by checking the files in the playlist to ensure that they are licensed for copying as part of a playlist.

## Parameters

### `cFiles` [in]

Number of files in the playlist. This is also the number of members in the array of file names referenced by *pwszFilenames*.

### `ppwszFilenames` [in]

Address of an array of **WCHAR** strings. Each string contains the name of a file in the playlist. You must maintain the file order exactly as it exists in the playlist.

### `pCallback` [in]

Address of the **IWMStatusCallback** implementation that will receive the WMT_INIT_PLAYLIST_BURN status message.

### `pvContext` [in]

Generic pointer, for use by the application. This is passed to the application in calls to the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback. You can use this parameter to differentiate between messages from different objects when sharing a single status callback.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method executes asynchronously. When it is finished, a WMT_INIT_PLAYLIST_BURN message is sent to the [OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) method of the [IWMStatusCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstatuscallback) interface identified by the *pCallback* parameter.

The files are checked to determine whether they are DRM-protected. If a file is protected, its license is checked to verify that the license allows copying to CD as part of a playlist.

## See also

[IWMReaderPlaylistBurn Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderplaylistburn)