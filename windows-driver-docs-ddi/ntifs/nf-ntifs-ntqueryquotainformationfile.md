# NtQueryQuotaInformationFile function

## Description

The **NtQueryQuotaInformationFile** routine retrieves quota entries associated with the volume specified by the **FileHandle** parameter.

## Parameters

### `FileHandle` [in]

A handle for the file object that represents the file or volume for which the quota information is requested.

### `IoStatusBlock` [out]

The address of the caller's I/O status block.

### `Buffer` [out]

A buffer to receive the quota information for the volume. The quota information is formatted as one or more [**FILE_QUOTA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_quota_information) structures. The **NextEntryOffset** field in the **FILE_QUOTA_INFORMATION** structure contains the offset, in bytes, of the next quota entry in the list. If there are no more entries after the current one, this member is zero.

### `Length` [in]

The length in bytes of the buffer.

### `ReturnSingleEntry` [in]

A Boolean value that indicates if only a single entry should be returned rather than filling the buffer with as many entries as possible.

### `SidList` [in, optional]

An optional list of SIDs whose quota information is to be returned. Each entry in the list is a [**FILE_GET_QUOTA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_quota_information) structure. The **NextEntryOffset** field in the **FILE_GET_QUOTA_INFORMATION** structure contains the offset, in bytes, of the next quota entry in the list. If there are no more entries after the current one, this member is zero.

### `SidListLength` [in]

The length in bytes of the **SID** list, if one was specified.

### `StartSid` [in, optional]

An optional pointer to the **SID** of the entry at which to begin scanning the quota information. This parameter should be set if the returned information is to start with an entry other than the first SID. This parameter is ignored if a **SidList** parameter is specified.

### `RestartScan` [in]

A Boolean value that indicates whether the scan of the quota information is to be restarted from the beginning. Set this parameter to **TRUE** if the scan of the quota information is to start at the first entry in the volume's quota information list. Set to **FALSE** if resuming the scan from a previous call to **NtQueryQuotaInformationFile**. The caller must set this parameter to **TRUE** when calling **NtQueryQuotaInformationFile** for the first time.

## Return value

The **NtQueryQuotaInformationFile** routine returns STATUS_SUCCESS if at least one [**FILE_QUOTA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_quota_information) structure is returned in the **Buffer** parameter or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_INSUFFICIENT_RESOURCES | There were insufficient resources to complete the operation. This is an error code. |
| STATUS_INVALID_DEVICE_REQUEST | Quotas are not enabled on the volume. This is an error code. |
| STATUS_INVALID_SID | The **StartSid** parameter did not contain a valid **SID**. This is an error code. |
| STATUS_QUOTA_LIST_INCONSISTENT | The **SidList** parameter did not contain a valid, properly formed list. This is an error code. |

## Remarks

The amount of information returned by **NtQueryQuotaInformationFile** is based on the size of the quota information associated with the volume, the size of the buffer, and whether a specific set of entries has been requested.

A call to **NtQueryQuotaInformationFile** will result in an [**IRP_MJ_SET_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-quota) request being sent to the device object that is associated with the file object whose handle is stored in the **FileHandle** parameter.

If the underlying file system does not support quota information (FAT and CDFS file systems, for example), **NtQueryQuotaInformationFile** will fail returning STATUS_INVALID_DEVICE_REQUEST.

> [!NOTE]
> If the call to the **NtQueryQuotaInformationFile** function occurs in kernel mode, you should use the name "[**ZwQueryQuotaInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryquotainformationfile)" instead of "**NtQueryQuotaInformationFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**FILE_GET_QUOTA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_quota_information)

[**FILE_QUOTA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_quota_information)

[**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[**IRP_MJ_QUERY_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-quota)

[**IRP_MJ_SET_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-quota)

[**IoCheckQuotaBufferValidity**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckquotabuffervalidity)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[**NtSetQuotaInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetquotainformationfile)