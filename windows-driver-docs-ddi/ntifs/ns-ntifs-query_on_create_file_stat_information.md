## Description

The **QUERY_ON_CREATE_FILE_STAT_INFORMATION** structure is used to write file information when [**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion) is called with the **QoCFileStatInformation** flag set in the **InfoClassFlags** parameter.

## Members

### `FileId`

The ID of the file.

### `CreationTime`

The creation time of the file.

### `LastAccessTime`

The time that the file was last accessed.

### `LastWriteTime`

The last time that the file was written to.

### `ChangeTime`

The last time a file was changed.

### `AllocationSize`

The file allocation size, in bytes. Usually this value is a multiple of the sector or cluster size of the underlying physical device.

### `EndOfFile`

The absolute, new end-of-file position as a byte offset from the start of the file. **EndOfFile** specifies the byte offset to the end of the file. Because this value is zero-based, it actually refers to the first free byte in the file. In other words, **EndOfFile** is the offset to the byte immediately following the last valid byte in the file.

### `FileAttributes`

The file's attributes, which can be any valid combination of the following values.

| Attribute | Meaning |
| --------- | ------- |
| FILE_ATTRIBUTE_READONLY (0x00000001) | The file is read-only. |
| FILE_ATTRIBUTE_HIDDEN (0x00000002) | The file or directory is hidden. |
| FILE_ATTRIBUTE_SYSTEM (0x00000004) | The file or directory is partially or exclusively used by the operating system. |
| FILE_ATTRIBUTE_DIRECTORY (0x00000010) | Identifies a directory. |
| FILE_ATTRIBUTE_ARCHIVE (0x00000020) | A file or directory marked for archive. |
| FILE_ATTRIBUTE_NORMAL (0x00000080) | A file that does not have other attributes set. This attribute is valid only when used alone. |

### `ReparseTag`

Reparse point tag. See [About reparse points](https://learn.microsoft.com/windows-hardware/drivers/ifs/reparse-points) for more information.

### `NumberOfLinks`

The number of links to the file.

## Remarks

The file system allocates this structure and fills in the requested information, if supported, while it processes a file create. Filter Manager will free the allocated structure.

## See also

[**FILE_STAT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_stat_information)

[**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion)

[**FltRetrieveFileInfoOnCreateCompletionEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletionex)