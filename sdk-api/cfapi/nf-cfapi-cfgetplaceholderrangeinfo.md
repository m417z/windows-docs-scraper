# CfGetPlaceholderRangeInfo function

## Description

Gets range information about a placeholder file or folder.

## Parameters

### `FileHandle` [in]

The handle of the placeholder file to be queried.

### `InfoClass` [in]

Types of the range of placeholder data.

### `StartingOffset` [in]

Offset of the starting point of the range of data.

### `Length` [in]

Length of the range of data. A provider can specify `CF_EOF` for *Length* to indicate that range for which information is requested is from *StartingOffset* to end of the file.

### `InfoBuffer` [out]

Pointer to a buffer that will receive the data. The buffer is an array of **CF_FILE_RANGE** structures, which are offset/length pairs, describing the requested ranges.

### `InfoBufferLength` [in]

The length of *InfoBuffer* in bytes.

### `ReturnedLength` [out, optional]

The length of the returned range of placeholder data in the *InfoBuffer*.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code. Some common error codes are listed in the following table:

| Error code | Meaning |
|--------|--------|
| HRESULT_FROM_WIN32( ERROR_HANDLE_EOF ) | This means that *StartingOffset* >= the position of the end of the file. |
| HRESULT_FROM_WIN32( ERROR_MORE_DATA ) | This implies that the next **CF_FILE_RANGE** entry doesn't fit in the provided buffer. The caller should verify if any entry is received or not using the returned *InfoBufferWritten* value. |

## Remarks

Unlike most placeholder APIs that take a file handle, this one does not modify the file in any way, therefore the file handle only requires READ_ATTRIBUTES access.

## See also

[CfGetPlaceholderRangeInfoForHydration](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetplaceholderrangeinfoforhydration)