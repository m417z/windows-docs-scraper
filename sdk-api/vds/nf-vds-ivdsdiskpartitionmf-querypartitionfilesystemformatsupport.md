# IVdsDiskPartitionMF::QueryPartitionFileSystemFormatSupport

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Retrieves the properties of the file systems that are supported for formatting a partition on the disk at a specified byte offset.

## Parameters

### `ullOffset` [in]

Byte offset of the partition from the beginning of the disk. This offset must be the offset of the start of a partition.

### `ppFileSystemSupportProps` [out]

A pointer to the array of [VDS_FILE_SYSTEM_FORMAT_SUPPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_format_support_prop) structures passed in by the caller. Upon successful completion, this array receives information about the properties of the supported file systems. Callers must free this array by using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

### `plNumberOfFileSystems` [out]

A pointer to a variable that upon successful completion receives the total number of elements in the *ppFileSystemSupportProps* parameter.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **VDS_E_BAD_PROVIDER_DATA**<br><br>0x80042441L | A provider returned bad data. |
| **VDS_E_DISK_REMOVEABLE**<br><br>0x8004255AL | The operation is not supported on removable media. |
| **VDS_E_MISSING_DISK**<br><br>0x80042454L | The disk is missing. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | The partition does not exist. |
| **VDS_E_PARTITION_NOT_OEM**<br><br>0x8004256FL | The operation is not supported on non-OEM partitions. |

## See also

[IVdsDiskPartitionMF](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdiskpartitionmf)

[VDS_FILE_SYSTEM_FORMAT_SUPPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_format_support_prop)