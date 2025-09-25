# _FILE_QUOTA_INFORMATION structure

## Description

The FILE_QUOTA_INFORMATION structure is used to query or set per-user quota information for each of the files in a directory.

## Members

### `NextEntryOffset`

Offset, in bytes, of the next quota entry in the list. If there are no more entries after the current one, this member is zero.

### `SidLength`

Length, in bytes, of the **Sid** member.

### `ChangeTime`

Time when this quota entry was last changed.

### `QuotaUsed`

Amount of disk space on this volume that is currently being used by the user.

### `QuotaThreshold`

Maximum mount of disk space on this volume that can be used by the user without triggering an event. For more information, see [FILE_FS_CONTROL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information).

### `QuotaLimit`

Maximum amount of disk space on this volume that can be used by the user.

### `Sid`

Security identifier (SID) of the user.

## Remarks

No specific access rights are required to query this information. To perform this query, create an IRP with major function code IRP_MJ_QUERY_QUOTA.

FILE_WRITE_DATA access to the volume is required to set this information. To perform this operation, create an IRP with major function code IRP_MJ_SET_QUOTA.

To check the validity of a buffer containing FILE_QUOTA_INFORMATION structure, call [IoCheckQuotaBufferValidity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckquotabuffervalidity).

On 32-bit platforms, this structure must be aligned on a LONG (4-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry, except the last, falls on a 4-byte boundary.

On 64-bit platforms, this structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry, except the last, falls on an 8-byte boundary.

## See also

[FILE_FS_CONTROL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_fs_control_information)

[IRP_MJ_QUERY_QUOTA](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-quota)

[IRP_MJ_SET_QUOTA](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-quota)

[IoCheckQuotaBufferValidity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckquotabuffervalidity)