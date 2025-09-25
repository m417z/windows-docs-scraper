# IVdsAdvancedDisk::QueryPartitions

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns the details of all partitions on the current disk.

## Parameters

### `ppPartitionPropArray` [out]

A pointer to the array of
[VDS_PARTITION_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_prop) structures passed in by the caller. Callers must free this array by using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

### `plNumberOfPartitions` [out]

A pointer to the number of elements in the array returned in the *ppPartitionPropArray* parameter.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The query was successful. |
| **S_FALSE** | The disk contains no partitions. |

## Remarks

If the disk contains extended partitions, this method returns only the first extended partition, regardless of how many extended partitions are on the disk.
A disk contains one extended partition for each logical drive. For more information about logical drives, see [Disk Object](https://learn.microsoft.com/windows/desktop/VDS/disk-object).

## See also

[Disk Object](https://learn.microsoft.com/windows/desktop/VDS/disk-object)

[IVdsAdvancedDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk)

[VDS_PARTITION_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_prop)