# IVdsAdvancedDisk::GetPartitionProperties

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns the properties of the partition identified by the partition offset.

## Parameters

### `ullOffset` [in]

The partition offset.

### `pPartitionProp` [out]

The address of the [VDS_PARTITION_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_prop) structure allocated and passed in by the caller.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | The partition does not exist. |

## Remarks

This method returns information for all partition types.

## See also

[Disk Object](https://learn.microsoft.com/windows/desktop/VDS/disk-object)

[IVdsAdvancedDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk)

[VDS_PARTITION_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_prop)