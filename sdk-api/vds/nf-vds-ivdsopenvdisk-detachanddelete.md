# IVdsOpenVDisk::DetachAndDelete

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Detaches a virtual disk and deletes the backing files.

## Parameters

### `Flags` [in]

An **DETACH_VIRTUAL_DISK_FLAG** enumeration value that specifies how the virtual disk is to be detached. Must be set to DETACH_VIRTUAL_DISK_FLAG_NONE.

### `ProviderSpecificFlags` [in]

Flags specific to the type of virtual disk being detached and deleted. For the Microsoft provider, this must be 0. This value must match the value that was specified for the *ProviderSpecificFlags* parameter of the [IVdsVdProvider::CreateVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvdprovider-createvdisk) method when the virtual disk was created.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## See also

[IVdsOpenVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsopenvdisk)