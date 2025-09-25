# IWMReaderAdvanced2::SaveFileAs

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SaveFileAs** method saves the current file.

## Parameters

### `pwszFilename` [in]

Pointer to a wide-character null-terminated string containing the file name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ERROR_OPERATION_ABORTED** | The file was closed before the operation completed. A WMT_SAVEAS_STOP event is also generated in this case. |
| **ASF_E_INVALID_STATE** | The call to this method has been made before an **Open** call. |
| **NS_E_BUSY** | A previous **SaveFileAs** operation has not yet been completed. Saving files is sequential. |
| **NS_E_INVALID_REQUEST** | The play mode is not WMT_PLAY_MODE_DOWNLOAD. |
| **STG_E_MEDIUMFULL** | There is not enough free disk space. See the note in the Remarks below. |

## Remarks

This method can be used to save the content downloaded from a Web server to the local hard disk. Files can be saved when the reader is downloading from a Web server.

You can use this method to save a server-side playlist. When you do so, you specify the name to use for the playlist, and each file in the playlist will be saved automatically.

This operation is asynchronous; WMT_SAVEAS_STOP indicates that all the data has been saved. Closing the reader ends a save operation that has not been completed.

This method can take some time to complete, and a call can be made to [GetSaveAsProgress](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced2-getsaveasprogress) to determine progress.

**Note** It is possible to get the out of disk space error (STG_E_MEDIUMFULL) if the file being saved is greater than 1 MB. This is because Microsoft Internet Explorer has a maximum cache size of 1MB, and in this case the error does not refer to the amount of free disk space. This effectively limits the sizes of files that can be saved this way to those under 1 MB.

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)