# GET_FILEEX_INFO_LEVELS enumeration

## Description

Defines values that are used with the
[GetFileAttributesEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesexa) and
[GetFileAttributesTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileattributestransacteda) functions to
specify the information level of the returned data.

## Constants

### `GetFileExInfoStandard`

The [GetFileAttributesEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesexa) or
[GetFileAttributesTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileattributestransacteda) function
retrieves a standard set of attribute information. The data is returned in a
[WIN32_FILE_ATTRIBUTE_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_file_attribute_data)
structure.

### `GetFileExMaxInfoLevel`

One greater than the maximum value. Valid values for this enumeration will be less than this value.

## See also

[File Management Enumerations](https://learn.microsoft.com/windows/desktop/FileIO/file-management-enumerations)

[GetFileAttributesEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesexa)

[GetFileAttributesTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileattributestransacteda)

[WIN32_FILE_ATTRIBUTE_DATA](https://learn.microsoft.com/windows/desktop/api/fileapi/ns-fileapi-win32_file_attribute_data)