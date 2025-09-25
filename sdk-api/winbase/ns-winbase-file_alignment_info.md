# FILE_ALIGNMENT_INFO structure

## Description

Contains alignment information for a file. This structure is returned from the
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex) function when
**FileAlignmentInfo** is passed in the *FileInformationClass*
parameter.

## Members

### `AlignmentRequirement`

Minimum alignment requirement, in bytes.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[File Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/file-management-structures)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)