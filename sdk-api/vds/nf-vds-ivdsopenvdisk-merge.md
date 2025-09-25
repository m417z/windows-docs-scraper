# IVdsOpenVDisk::Merge

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Merges a child virtual disk with its parents in the differencing chain.

## Parameters

### `Flags` [in]

A **MERGE_VIRTUAL_DISK_FLAG** enumeration value that specifies how the virtual disk is to be merged. Must be set to MERGE_VIRTUAL_DISK_FLAG_NONE.

### `MergeDepth` [in]

The number of parent disks in the differencing chain to merge together. The disk must have been open with a ReadWriteDepth at least equal to this value.

### `ppAsync` [out]

A pointer to an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface that upon successful completion receives the **IVdsAsync** interface to monitor and control this operation. Callers must release the interface received when they have finished with it. If the [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) method is called on the interface and a success HRESULT value is returned, the interfaces returned in the [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure must be released by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## Remarks

A virtual disk can be merged only if it is detached.

This method moves all data blocks from the child disk to the parent. However, it will not delete the invalidated child disks at the end of the operation.

The virtual disk must have been opened with read/write access.

## See also

[IVdsOpenVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsopenvdisk)