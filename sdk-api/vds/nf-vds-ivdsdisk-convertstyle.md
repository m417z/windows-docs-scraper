# IVdsDisk::ConvertStyle

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Converts the partition style of an empty disk from one style to another.

## Parameters

### `NewStyle` [in]

The partition styles enumerated by [VDS_PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_style).

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The conversion completed successfully. |
| **VDS_E_INVALID_OPERATION**<br><br>0x80042415L | The disk style cannot be converted, as is the case for 1394 or USB disks and unallocated disks. |

## Remarks

An empty disk contains no user data, OEM partitions, ESP partitions, or unknown partitions. Only LDM metadata partitions and MSR partitions are valid on an empty disk.

## See also

[IVdsDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdisk)

[VDS_PARTITION_INFO_GPT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_gpt)

[VDS_PARTITION_INFO_MBR](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_mbr)

[VDS_PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_style)