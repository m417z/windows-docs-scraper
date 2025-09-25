# IFileSystemBindData2::GetFileID

## Description

Gets the unique file identifier for the current file.

## Parameters

### `pliFileID` [out]

Type: **LARGE_INTEGER***

When this method returns successfully, receives a pointer to the unique file identifier for the current file. *pliFileID* is a pointer to a value that is a concatenation of the values *nFileIndexHigh* and *nFileIndexlow*, noted in structure [_by_handle_file_information](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-by_handle_file_information).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.