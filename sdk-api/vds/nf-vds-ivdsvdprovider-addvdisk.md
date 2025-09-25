# IVdsVdProvider::AddVDisk

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Creates a virtual disk object for an existing virtual disk file.

## Parameters

### `VirtualDeviceType` [in]

The address of a [VIRTUAL_STORAGE_TYPE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-virtual_storage_type) structure

### `pPath` [in]

A **NULL**-terminated wide-character string containing the name and directory path for the backing file for the virtual disk.

### `ppVDisk` [out]

A pointer to a variable that receives an [IVdsVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvdisk) interface pointer to the newly created virtual disk object. Callers must release the interface pointer when it is no longer needed by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## See also

[IVdsVdProvider](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvdprovider)