# ZwSetQuotaInformationFile function

## Description

The **ZwSetQuotaInformationFile** routine changes quota entries for the volume associated with the **FileHandle** parameter. All of the quota entries in the specified buffer are applied to the volume.

## Parameters

### `FileHandle` [in]

A handle for the file object that represents the file or volume for which the quota information is to be modified.

### `IoStatusBlock` [out]

The address of the caller's I/O status block.

### `Buffer` [in]

A buffer containing the new quota entries that should be applied to the volume. The quota information must be formatted as one or more [**FILE_QUOTA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_quota_information) structures. The **NextEntryOffset** field in the **FILE_QUOTA_INFORMATION** structure contains the offset, in bytes, of the next quota entry in the list. If there are no more entries after the current one, this member is zero.

### `Length` [in]

The length in bytes of the buffer.

## Return value

The **ZwSetQuotaInformationFile** routine returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_INSUFFICIENT_RESOURCES | There were insufficient resources to complete the operation. This is an error code. |
| STATUS_INVALID_DEVICE_REQUEST | Quotas are not enabled on the volume. This is an error code. |
| STATUS_MEDIA_WRITE_PROTECTED | The volume is read only. This is an error code. |

## Remarks

The **ZwSetQuotaInformationFile** routine applies all of the quota entries in the specified **Buffer** parameter to the volume.

The **IoCheckQuotaBufferValidity** function can check whether the specified quota buffer passed as the **Buffer** parameter is valid.

A call to **ZwSetQuotaInformationFile** will result in an [**IRP_MJ_SET_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-quota) request being sent to the device object that is associated with the file object whose handle is stored in the **FileHandle** parameter.

If the underlying file system does not support quota information (FAT and CDFS file systems, for example), **ZwSetQuotaInformationFile** will fail returning STATUS_INVALID_DEVICE_REQUEST.

> [!NOTE]
> If the call to the **ZwSetQuotaInformationFile** function occurs in user mode, you should use the name "[**NtSetQuotaInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetquotainformationfile)" instead of "**ZwSetQuotaInformationFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**FILE_GET_QUOTA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_quota_information)

[**FILE_QUOTA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_quota_information)

[**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[**IRP_MJ_QUERY_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-quota)

[**IRP_MJ_SET_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-quota)

[**IoCheckQuotaBufferValidity**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckquotabuffervalidity)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[**ZwQueryQuotaInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryquotainformationfile)