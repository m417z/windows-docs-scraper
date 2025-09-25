# IVdsOpenVDisk::Attach

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Attaches a virtual disk.

## Parameters

### `pStringSecurityDescriptor` [in]

A string that contains the security descriptor for the virtual disk. If not specified, the security descriptor in use is: "D:P(A;;GA;;;WD)" on Windows 7, and "D:P(A;;GA;;;WD)(A;;GA;;;AC)" on Windows 8.1 and later.

### `Flags` [in]

A bitmask of [ATTACH_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-attach_virtual_disk_flag) enumeration values specifying how the virtual disk is to be attached. Possible values include the following.

| Value | Meaning |
| --- | --- |
| **ATTACH_VIRTUAL_DISK_FLAG_NONE**<br><br>0x00000000 | No flags are specified. |
| **ATTACH_VIRTUAL_DISK_FLAG_READ_ONLY**<br><br>0x00000001 | Attach the virtual disk as read-only. |
| **ATTACH_VIRTUAL_DISK_FLAG_NO_DRIVE_LETTER**<br><br>0x00000002 | Mount all volumes on the attached virtual disk without assigning drive letters to them. |
| **ATTACH_VIRTUAL_DISK_FLAG_PERMANENT_LIFETIME**<br><br>0x00000004 | The VDS service automatically sets this flag so that the VHD remains attached until the [IVdsOpenVDisk::Detach](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsopenvdisk-detach) method is called to detach it. |
| **ATTACH_VIRTUAL_DISK_FLAG_NO_LOCAL_HOST**<br><br>0x00000008 | Reserved. Do not use. |

### `ProviderSpecificFlags` [in]

A bitmask of flags that are specific to the type of virtual disk that is being attached. These flags are provider-specific. For the Microsoft virtual disk provider, this parameter must be zero.

### `TimeoutInMs` [in]

This parameter is reserved for future use.

### `ppAsync` [out]

A pointer to an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface that upon successful completion receives the **IVdsAsync** interface to monitor and control this operation. Callers must release the interface received when they have finished with it. If the [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) method is called on the interface and a success HRESULT value is returned, the interfaces returned in the [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure must be released by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## Remarks

When a virtual disk is attached, the caller can receive one or all of the following notifications:

* If the caller is registered for VDS notifications, the caller receives a disk arrival notification. For more information, see [VDS Notifications](https://learn.microsoft.com/windows/desktop/VDS/vds-notification-model).
* If the caller is registered for PnP notifications, the caller receives a PnP disk arrival notification. For more information, see [RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa).

Applications must initialize process-wide security by calling the [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) function. The *dwImpLevel* parameter should be set to **RPC_C_IMP_LEVEL_IMPERSONATE**.

**Windows Server 2008, Windows Vista and Windows Server 2003:** These actions are not required until Windows 7 and Windows Server 2008 R2.

## See also

[IVdsOpenVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsopenvdisk)