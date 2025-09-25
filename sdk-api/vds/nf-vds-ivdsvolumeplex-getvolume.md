# IVdsVolumePlex::GetVolume

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns the volume to which the current plex is a member.

## Parameters

### `ppVolume` [out]

The address of an [IVdsVolume](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume) interface pointer. The caller must release the pointer.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used.

## See also

[IVdsVolume](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume)

[IVdsVolumePlex](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumeplex)