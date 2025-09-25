# IVdsVdProvider::CreateVDisk

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Creates a virtual disk.

## Parameters

### `VirtualDeviceType` [in]

A pointer to a [VIRTUAL_STORAGE_TYPE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-virtual_storage_type) structure that specifies the type of virtual disk to be created.

### `pPath` [in]

A **NULL**-terminated wide-character string containing the name and directory path for the backing file to be created for the virtual disk.

### `pStringSecurityDescriptor` [in]

A **NULL**-terminated wide-character string containing the security descriptor to be applied to
the virtual disk. If this parameter is **NULL**, the security descriptor in the caller's access token will be used.

### `Flags` [in]

A bitmask of [CREATE_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-create_virtual_disk_flag) enumeration values specifying how the virtual disk is to be created.

| Value | Meaning |
| --- | --- |
| **CREATE_VIRTUAL_DISK_FLAG_NONE**<br><br>0x00000000 | No flags are specified. |
| **CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION**<br><br>0x00000001 | Pre-allocate all physical space necessary for the virtual size of the virtual disk. This flag is valid only for a fixed-size virtual disk. |

### `ProviderSpecificFlags` [in]

A bitmask of flags that are specific to the type of virtual disk that is being created. These flags are provider-specific. For the Microsoft virtual disk provider, this parameter must be zero.

### `Reserved` [in]

The parameter is reserved and must be zero.

### `pCreateDiskParameters` [in]

A pointer to a [VDS_CREATE_VDISK_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_create_vdisk_parameters) structure that contains the virtual disk creation parameters.

### `ppAsync` [out]

A pointer to an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface that upon successful completion receives the **IVdsAsync** interface to monitor and control this operation. Callers must release the interface received when they are done with it. If the [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) method is called on the interface and a success HRESULT value is returned, the interfaces returned in the [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure must be released by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## Remarks

Applications must initialize process-wide security by calling the [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) function. The *dwImpLevel* parameter should be set to **RPC_C_IMP_LEVEL_IMPERSONATE**.

**Windows Server 2008, Windows Vista and Windows Server 2003:** These actions are not required until Windows 7 and Windows Server 2008 R2.

If the virtual disk with the specified file name does not exist, it is created. If the virtual disk already exists, the virtual disk provider returns an interface pointer to the existing virtual disk object without re-creating the file.

## See also

[IVdsVdProvider](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvdprovider)