# IFileSystemBindData2::SetFileID

## Description

Sets the unique file identifier for the current file.

## Parameters

### `liFileID` [in]

Type: **LARGE_INTEGER**

A unique file identifier for the current file. *liFileID* is a value that is a concatenation of the values *nFileIndexHigh* and *nFileIndexlow*, noted in structure [_by_handle_file_information](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-by_handle_file_information).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.