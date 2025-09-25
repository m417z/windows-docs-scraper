# FILE_ID_TYPE enumeration

## Description

Discriminator for the union in the
[FILE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_descriptor) structure.

## Constants

### `FileIdType`

Use the **FileId** member of the union.

### `ObjectIdType`

Use the **ObjectId** member of the union.

### `ExtendedFileIdType`

Use the **ExtendedFileId** member of the union.

**Windows XP, Windows Server 2003, Windows Vista, Windows Server 2008, Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012.

### `MaximumFileIdType`

This value is used for comparison only. All valid values are less than this value.

## See also

[FILE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_descriptor)

[File Management Enumerations](https://learn.microsoft.com/windows/desktop/FileIO/file-management-enumerations)

[OpenFileById](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilebyid)