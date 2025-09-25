# _FILE_VALID_DATA_LENGTH_INFORMATION structure

## Description

The **FILE_VALID_DATA_LENGTH_INFORMATION** structure is used as an argument to [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile).

## Members

### `ValidDataLength`

Specifies the new valid data length for the file. This parameter must be a positive value that is greater than the current valid data length, but less than or equal to the current file size.

## Remarks

The **FILE_VALID_DATA_LENGTH_INFORMATION** structure is used to set a new valid data length for a file on an NTFS volume. A file's *valid data length* is the length, in bytes, of the data that has been written to the file. This *valid data* extends from the beginning of the file to the last byte in the file that has not been zeroed or left uninitialized.

Setting this information requires FILE_WRITE_DATA access to the file. In addition, nonadministrators and remote users must have **SeManageVolumePrivilege** (SE_MANAGE_VOLUME_PRIVILEGE) for the volume on which the file resides.

File system filter drivers can find it useful to set a valid data length in the following scenarios:

* When writing raw clusters directly to disk through a hardware channel. This allows the filter driver to inform the file system that this range contains valid data that can be returned to the user.
* When creating large files where performance is an issue. This avoids the time it takes to fill the file with zeros when the file is created or extended.
* When remotely extending a file and writing to disk on a served-metadata cluster file system.

The size of the *FileInformation* buffer passed to **ZwSetInformationFile** must be at least **sizeof**(**FILE_VALID_DATA_LENGTH_INFORMATION**).

This structure must be aligned on a LONGLONG (8-byte) boundary.

## See also

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)