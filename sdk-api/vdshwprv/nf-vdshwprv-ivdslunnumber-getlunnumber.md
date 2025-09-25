# IVdsLunNumber::GetLunNumber

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Retrieves the LUN number for a LUN.

## Parameters

### `pulLunNumber` [out]

The address of a variable that receives the LUN number. This value is required and cannot be **NULL**.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## Remarks

This method returns the LUN number that the VDS hardware provider assigned to the LUN. This number identifies the LUN within the disk array. It is not the same as the "Logical Unit Number" in the disk's SCSI address. Each LUN in the disk array is assigned exactly one LUN number.

This method exists because the DiskRAID utility assigns its own index to each LUN when it enumerates the LUNs in a subsystem. But these indexes can change each time DiskRAID is run, if the hardware provider enumerates the LUNs in a different order. This can be confusing to end users. For disk arrays that have their own (provider-assigned) LUN numbers, this method gives the caller the ability to map the LUN numbers to the LUN indexes that are assigned by DiskRAID.

If a subsystem supports LUN numbering, it can indicate this support by setting the **VDS_SF_SUPPORTS_LUN_NUMBER** flag in the **ulFlags** member of the [VDS_SUB_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop) or [VDS_SUB_SYSTEM_PROP2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop2) structure. For more information about this flag, see the [VDS_SUB_SYSTEM_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_sub_system_flag) enumeration.

## See also

[IVdsLunNumber](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslunnumber)