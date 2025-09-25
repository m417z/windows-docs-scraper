# IVdsStoragePool::GetProvider

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns the hardware provider that manages the [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object).

## Parameters

### `ppProvider` [out]

The address of a variable that receives an [IVdsProvider](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsprovider) interface pointer. Callers must release the interface when it is no longer needed by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## See also

[IVdsStoragePool](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsstoragepool)