# FILE_ID_DESCRIPTOR structure

## Description

Specifies the type of ID that is being used.

## Members

### `dwSize`

The size of this **FILE_ID_DESCRIPTOR**
structure.

### `Type`

The discriminator for the union indicating the type of identifier that is being passed.

| Value | Meaning |
| --- | --- |
| **FileIdType**<br><br>0 | Use the **FileId** member of the union. |
| **ObjectIdType**<br><br>1 | Use the **ObjectId** member of the union. |
| **ExtendedFileIdType**<br><br>2 | Use the **ExtendedFileId** member of the union.<br><br>**Windows XP, Windows Server 2003, Windows Vista, Windows Server 2008, Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.FileId`

The ID of the file to open.

### `DUMMYUNIONNAME.ObjectId`

The ID of the object to open.

### `DUMMYUNIONNAME.ExtendedFileId`

A [FILE_ID_128](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-file_id_128) structure containing the 128-bit file ID of the file. This is used on ReFS file systems.

**Windows XP, Windows Server 2003, Windows Vista, Windows Server 2008, Windows 7 and Windows Server 2008 R2:** This member is not supported before Windows 8 and Windows Server 2012.

## See also

[FILE_ID_128](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-file_id_128)

[FILE_ID_TYPE](https://learn.microsoft.com/windows/desktop/api/winbase/ne-winbase-file_id_type)

[File Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/file-management-structures)

[OpenFileById](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilebyid)