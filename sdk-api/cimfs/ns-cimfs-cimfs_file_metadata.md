## Description

Structure that specifies file metadata for the file to be added by CimCreateFile.

## Members

### `Attributes`

File attributes

### `FileSize`

Size of the file. The file can be written up to this size by CimWriteFile.

### `CreationTime`

Creation time

### `LastWriteTime`

Last write time

### `ChangeTime`

Change time

### `LastAccessTime`

Last access time

### `SecurityDescriptorBuffer`

Buffer containing the file security descriptor

### `SecurityDescriptorSize`

Size of the security descriptor buffer in bytes

### `ReparseDataBuffer`

Buffer containing the file reparse data

### `ReparseDataSize`

Size of the ReparseDataBuffer in bytes

### `EaBuffer`

Buffer containing a FILE_FULL_EA_INFORMATION structure for the file extended attributes

### `EaBufferSize`

Size of the EaBuffer in bytes

## Remarks

## See also