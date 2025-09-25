# IWMReaderPlaylistBurn::GetInitResults

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetInitResults** method retrieves the results of the playlist file check.

## Parameters

### `cFiles` [in]

Number of files in the playlist. This is also the number of members in the array referenced by *phrStati*. This value must be the same as the number of files specified in the original call to [InitPlaylistBurn](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderplaylistburn-initplaylistburn).

### `phrStati` [out]

Address of an array of **HRESULT** values. The members of this array correspond to the file names passed in the original call to **InitPlaylistBurn**. On output, each member is set to S_OK if the corresponding file is approved for copying as part of the playlist. If a file in the playlist is not licensed for copying, or if an error is encountered, the corresponding member of this array is set to the appropriate **HRESULT** return code.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method should be called in response to a WMT_INIT_PLAYLIST_BURN message received by your implementation of the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) method. If you call **GetInitResults** without first calling **InitPlaylistBurn** and receiving the WMT_INIT_PLAYLIST_BURN message, **GetInitResults** will return an error code.

If, after calling this method, all members of the array referenced by *phrStati* are set to S_OK, you can begin copying the files in the playlist. However, you must use the same instance of the reader object for retrieving data that you used to get the **IWMReaderPlaylistBurn** interface.

## See also

[IWMReaderPlaylistBurn Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderplaylistburn)