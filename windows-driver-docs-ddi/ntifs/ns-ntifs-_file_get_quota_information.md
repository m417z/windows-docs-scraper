# _FILE_GET_QUOTA_INFORMATION structure

## Description

The FILE_GET_QUOTA_INFORMATION structure is used to query for quota information.

## Members

### `NextEntryOffset`

Offset, in bytes, of the next FILE_GET_QUOTA_INFORMATION-typed entry. This member is zero if no other entries follow this one.

### `SidLength`

Length, in bytes, of the **Sid** member.

### `Sid`

Security identifier ([SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)) whose quota information is to be returned.

## Remarks

The FILE_GET_QUOTA_INFORMATION structure is used to query for quota information. The quota information is returned in a [FILE_QUOTA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_quota_information)-structured buffer.

This structure must be aligned on a LONG (4-byte) boundary.

## See also

[FILE_QUOTA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_quota_information)

[IRP_MJ_QUERY_QUOTA](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-quota)

[IRP_MJ_SET_QUOTA](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-quota)

[IoCheckQuotaBufferValidity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckquotabuffervalidity)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)