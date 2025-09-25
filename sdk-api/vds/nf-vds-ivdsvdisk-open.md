# IVdsVDisk::Open

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Opens a handle to the specified virtual disk file and returns an [IVdsOpenVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsopenvdisk) interface pointer to the object that represents the opened handle.

## Parameters

### `AccessMask` [in]

A bitmask of [VIRTUAL_DISK_ACCESS_MASK](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-virtual_disk_access_mask-r1) flags specifying the access rights to be applied to the opened virtual disk.

### `Flags` [in]

A bitmask of [OPEN_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-open_virtual_disk_flag) flags specifying how the virtual disk is to be opened.

### `ReadWriteDepth` [in]

The number of stores (backing files), beginning with the child, of the backing store chain to open read/write. The remaining stores in the differencing chain will be opened read-only. (This is necessary for merge operations to succeed.)

### `ppOpenVDisk` [out]

A pointer to a variable that receives an [IVdsOpenVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsopenvdisk) interface pointer to the newly created object that represents the handle opened to the virtual disk object. Callers must release the interface pointer when it is no longer needed by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## Remarks

Applications must initialize process-wide security by calling the [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) function. The *dwImpLevel* parameter should be set to **RPC_C_IMP_LEVEL_IMPERSONATE**.

**Windows Server 2008, Windows Vista and Windows Server 2003:** These actions are not required until Windows 7 and Windows Server 2008 R2.

## See also

[IVdsVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvdisk)