# IVdsAsync::Wait

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns when the asynchronous
operation has either finished successfully or failed.

## Parameters

### `pHrResult` [out]

The address of an **HRESULT** passed in by the caller.

### `pAsyncOut` [out]

The address of a [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure
passed in by the caller.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used.

There are two **HRESULT** return values to examine. The one returned by the method
reports failures from the call. The **HRESULT** returned through
*pHrResult* is used to report failures with the asynchronous operation associated with
the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) object. Both values must be examined.

## Remarks

This method adds a reference to the contained object produced by the
[IVdsPack::CreateVolume](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-createvolume),
[IVdsVolume::BreakPlex](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-breakplex),
[IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun), and
[IVdsAdvancedDisk::CreatePartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-createpartition), and
[IVdsCreatePartitionEx::CreatePartitionEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdscreatepartitionex-createpartitionex)
methods. Callers must release the reference to the contained object.

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsLun::RemovePlex](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-removeplex)

[IVdsPack::CreateVolume](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-createvolume)

[IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun)

[IVdsVolume::BreakPlex](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-breakplex)

[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output)