# DragQueryFileA function

## Description

Retrieves the names of dropped files that result from a successful drag-and-drop operation.

## Parameters

### `hDrop` [in]

Type: **HDROP**

Identifier of the structure that contains the file names of the dropped files.

### `iFile` [in]

Type: **UINT**

Index of the file to query. If the value of this parameter is 0xFFFFFFFF, **DragQueryFile** returns a count of the files dropped. If the value of this parameter is between zero and the total number of files dropped, **DragQueryFile** copies the file name with the corresponding value to the buffer pointed to by the *lpszFile* parameter.

### `lpszFile` [out]

Type: **LPTSTR**

The address of a buffer that receives the file name of a dropped file when the function returns. This file name is a null-terminated string. If this parameter is **NULL**, **DragQueryFile** returns the required size, in characters, of this buffer.

### `cch`

Type: **UINT**

The size, in characters, of the *lpszFile* buffer.

## Return value

Type: **UINT**

A nonzero value indicates a successful call.

When the function copies a file name to the buffer, the return value is a count of the characters copied, not including the terminating null character.

If the index value is 0xFFFFFFFF, the return value is a count of the dropped files. Note that the index variable itself returns unchanged, and therefore remains 0xFFFFFFFF.

If the index value is between zero and the total number of dropped files, and the *lpszFile* buffer address is **NULL**, the return value is the required size, in characters, of the buffer, *not including* the terminating null character.

## See also

[DragQueryPoint](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-dragquerypoint)

## Remarks

> [!NOTE]
> The shellapi.h header defines DragQueryFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).