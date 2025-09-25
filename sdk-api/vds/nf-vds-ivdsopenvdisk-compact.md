# IVdsOpenVDisk::Compact

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Compacts the virtual disk to reduce the physical size of the backing file.

## Parameters

### `Flags` [in]

A **COMPACT_VIRTUAL_DISK_FLAG** enumeration value that specifies how the virtual disk is to be compacted. Must be set to COMPACT_VIRTUAL_DISK_FLAG_NONE.

### `Reserved` [in]

This parameter is reserved for system use.

### `ppAsync` [out]

A pointer to an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface that upon successful completion receives the **IVdsAsync** interface to monitor and control this operation. Callers must release the interface received when they have finished with it. If the [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) method is called on the interface and a success HRESULT value is returned, the interfaces returned in the [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure must be released by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## Remarks

A virtual disk can be compacted only if it is in one of the following states:

* Detached (offline mode)
* Attached and opened with read-only access (online mode)

If it is in any other state, the compact operation fails.

The virtual disk must be an expandable (also called dynamic) or differencing virtual disk.

The operation can be safely interrupted and re-run later. If the operation is interrupted and the backing file is reopened, the file's size may be reduced when the file is opened.

The operation can be CPU-intensive or I/O-intensive, or both, depending on how large the virtual disk is and how many unused blocks require manipulation.

This method reduces the size of the virtual disk's backing store file by reclaiming unused space. If this method is called for a virtual disk that is detached, it can only reclaim space in the file that was never used to write data. If it is called for a virtual disk that is attached and opened with read-only access, it is able to reclaim space that was once used, but was later freed. Calling this method for a virtual disk that is attached and opened with read-only access reclaims the maximum amount of free space in the backing store file.

## See also

[IVdsOpenVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsopenvdisk)