# CfGetPlaceholderStateFromFileInfo function

## Description

Gets a set of placeholder states based on the various information of the file.

## Parameters

### `InfoBuffer` [in]

An info buffer about the file.

### `InfoClass` [in]

A [FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/win32/api/minwinbase/ne-minwinbase-file_info_by_handle_class) class that helps the function interpret the data in *InfoBuffer*.

## Return value

Can include [CF_PLACEHOLDER_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_placeholder_state); the placeholder state.

## Remarks

The input is a buffer containing information returned by [GetFileInformationByHandleEx](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getfileinformationbyhandleex), and the corresponding *InfoClass* so the API knows how to interpret the buffer.

Not all information classes supported by [GetFileInformationByHandleEx](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getfileinformationbyhandleex) are supported by this API. If the *FileAttributes* and *ReparseTag* can’t be extracted from a given information class, this API will return **CF_PLACEHOLDER_STATE_INVALID** and set last error properly.

## See also

[CF_PLACEHOLDER_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_placeholder_state)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getfileinformationbyhandleex)