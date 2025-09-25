# FILE_STORAGE_RESERVE_ID_INFORMATION structure

## Description

The **FILE_STORAGE_RESERVE_ID_INFORMATION** structure is used by [**NtQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) and [**NtSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile) to query and set the storage reserve ID on a file or directory.

## Members

### `StorageReserveId`

A [**STORAGE_RESERVE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_storage_reserve_id) value that indicates the storage reserve ID for the file or directory. The file system uses this ID to change the disk space used by the file or directory as follows:

- To storage space that has been reserved by the operating system for special purposes (called storage reserve areas)
- To storage space that is available for all users and applications

## Remarks

Setting a storage reserve ID on a directory causes all files subsequently created inside that directory to inherit the storage reserve ID.

Attempting to set a storage reserve ID fails with STATUS_STORAGE_RESERVE_ID_INVALID if the value is greater than the maximum value supported by the file system.

Attempting to set a storage reserve ID fails with STATUS_STORAGE_RESERVE_DOES_NOT_EXIST if the corresponding storage reserve area has not been defined on the volume.

## See also

[**STORAGE_RESERVE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_storage_reserve_id)