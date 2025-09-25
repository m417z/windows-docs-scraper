# IVdsDisk::GetIdentificationData

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Retrieves information that uniquely identifies a disk.

## Parameters

### `pLunInfo` [out]

The address of the [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure allocated and passed in by the caller. VDS allocates memory for the **m_szVendorId**,
**m_szProductId**, **m_szProductRevision**,
and **m_szSerialNumber** member strings, as well as the **m_pbPort** and **m_pbAddress** member strings of each element in the array of [VDS_INTERCONNECT](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_interconnect) structures.
Callers must free the strings by using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The identification data was returned successfully. |

## Remarks

VDS implements this method. Callers can only extract LUN information from devices managed by a hardware provider.

## See also

[IVdsDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdisk)

[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)