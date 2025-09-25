# IVdsDisk::GetProperties

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns property
information for a disk.

## Parameters

### `pDiskProperties` [out]

The address of the [VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop) structure
allocated and passed in by the caller. VDS allocates memory for the **pwszDiskAddress**,
**pwszName**, **pwszFriendlyName**,
**pwszAdaptorName**, and **pwszDevicePath** member strings.
Callers must free the strings by using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The properties were returned successfully. |
| ****VDS_S_PROPERTIES_INCOMPLETE****<br><br>0x00042715L | Some but not all of the properties were successfully retrieved. Note that there are many possible reasons for failing to retrieve all properties, including device removal. |

## See also

[IVdsDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdisk)

[VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop)