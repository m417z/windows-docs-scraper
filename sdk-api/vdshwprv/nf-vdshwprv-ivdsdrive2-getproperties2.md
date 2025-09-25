# IVdsDrive2::GetProperties2

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns the properties of a drive object.

## Parameters

### `pDriveProp2` [out]

The address of the [VDS_DRIVE_PROP2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop2) structure
allocated and passed in by the caller. VDS allocates memory for the
**pwszFriendlyName** and **pwszIdentification** member strings.
Callers must free the strings by using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function. This parameter is required and cannot be **NULL**.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used.

## Remarks

This method must return zero (S_OK) to indicate success, or an implementation-specific nonzero error code to indicate failure.

## See also

[IVdsDrive2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsdrive2)