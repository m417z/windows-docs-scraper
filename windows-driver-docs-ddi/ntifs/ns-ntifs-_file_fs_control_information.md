# FILE_FS_CONTROL_INFORMATION structure

## Description

The **FILE_FS_CONTROL_INFORMATION** structure is used to query or set control information for the files in a directory.

## Members

### `FreeSpaceStartFiltering`

Minimum amount of free disk space, in bytes, that is required for the Content-Indexing daemon to begin document filtering.

### `FreeSpaceThreshold`

Minimum amount of free disk space, in bytes, required for the Indexing Service to continue to filter documents and merge word lists. If the amount of free disk space falls below this threshold, a warning message is written to the Microsoft Windows application event log. Filtering and merging are halted until space is freed.

### `FreeSpaceStopFiltering`

Minimum amount of free disk space, in bytes, that is required for the Content-Indexing daemon to continue document filtering. If the amount of free disk space falls below this threshold, document filtering is halted.

### `DefaultQuotaThreshold`

Default per-user disk quota warning threshold for the volume.

### `DefaultQuotaLimit`

Default per-user disk quota limit for the volume.

### `FileSystemControlFlags`

Bitmask of flags that control quota enforcement and logging of user-related quota events on the volume. Logging makes an entry in the Windows application event log. Compatible combination of one or more of the following:

| File System Control Flag | Meaning |
| ------------------------ | ------- |
| FILE_VC_CONTENT_INDEX_DISABLED | If set, content indexing is disabled. |
| FILE_VC_LOG_QUOTA_LIMIT | If set, an event log entry will be created when the user exceeds his or her assigned disk quota limit. |
| FILE_VC_LOG_QUOTA_THRESHOLD | If set, an event log entry will be created when the user exceeds his or her assigned quota warning threshold. |
| FILE_VC_LOG_VOLUME_LIMIT | If set, an event log entry will be created when the volume's free space limit is exceeded. |
| FILE_VC_LOG_VOLUME_THRESHOLD | If set, an event log entry will be created when the volume's free space threshold is exceeded. |
| FILE_VC_QUOTA_ENFORCE | If set, quotas are enforced on the volume. |
| FILE_VC_QUOTA_TRACK | If set, quotas are tracked on the volume. |
| FILE_VC_QUOTAS_INCOMPLETE | If set, the quota information for the volume is incomplete. |
| FILE_VC_QUOTAS_REBUILDING | If set, the file system is rebuilding the quota information for the volume. |

In addition, the following flag masks are defined. These are useful for testing flag values.

| Mask | Value |
| ---- | ----- |
|FILE_VC_QUOTA_MASK | FILE_VC_QUOTA_ENFORCE \| FILE_VC_QUOTA_TRACK |
| FILE_VC_QUOTA_NONE | ~FILE_VC_QUOTA_ENFORCE & ~FILE_VC_QUOTA_TRACK |
| FILE_VC_VALID_MASK | ORed combination of all flags in the above table. |

## Remarks

This information can be queried in either of the following ways:

* Call [**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile), passing FileFsControlInformation as the value of **FileInformationClass** and passing a caller-allocated, FILE_FS_CONTROL_INFORMATION-structured buffer as the value of **FileInformation**.

* Create an IRP with major function code IRP_MJ_QUERY_VOLUME_INFORMATION.

FILE_READ_DATA access to the volume is required to query this information.

This information can be set in either of the following ways:

* Call [**FltSetVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation) or [**ZwSetVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetvolumeinformationfile), passing FileFsControlInformation as the value of **FileInformationClass** and passing a caller-allocated, FILE_FS_CONTROL_INFORMATION-structured buffer as the value of **FileInformation**.
* Create an IRP with major function code IRP_MJ_SET_VOLUME_INFORMATION.

FILE_WRITE_DATA access to the volume is required to set this information.

The size of the buffer passed in the **FileInformation** parameter to [**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation), [**FltSetVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation), [**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile), or **ZwSetVolumeInformationFile** must be at least **sizeof** (FILE_FS_CONTROL_INFORMATION).

This structure must be aligned on a LONGLONG (8-byte) boundary.

## See also

[**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[**FltSetVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation)

[**IRP_MJ_QUERY_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information)

[**IRP_MJ_SET_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-volume-information)

[**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile)

[**ZwSetVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetvolumeinformationfile)