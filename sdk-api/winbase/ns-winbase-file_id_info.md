# FILE_ID_INFO structure

## Description

Contains identification information for a file. This structure is returned from the
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex) function when
**FileIdInfo** is passed in the *FileInformationClass*
parameter.

## Members

### `VolumeSerialNumber`

The serial number of the volume that contains a file.

### `FileId`

The 128-bit file identifier for the file. The file identifier and the volume serial number uniquely identify
a file on a single computer. To determine whether two open handles represent the same file, combine the
identifier and the volume serial number for each file and compare them.

## See also

[FILE_ID_128](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-file_id_128)

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[File Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/file-management-structures)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)