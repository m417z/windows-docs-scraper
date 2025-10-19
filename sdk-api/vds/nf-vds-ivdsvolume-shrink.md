# IVdsVolume::Shrink

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Reduces the size of the volume
and all plexes, and returns the released extents to free space.

## Parameters

### `ullNumberOfBytesToRemove` [in]

The size of the reduction in bytes.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer. VDS
initializes the interface on return. Callers must release the interface. Use this interface to cancel, wait for,
or query the status of the operation. If
[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) is called and a success HRESULT value is returned, the interfaces returned in
the [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure must be released by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | The cache of the provider is corrupted. This indicates a software or communication problem inside a provider that caches information about the attached devices. The caller can use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_CANNOT_SHRINK**<br><br>0x8004251EL | The volume cannot be shrunk because the file system does not support it. |
| **VDS_E_DISK_REMOVEABLE**<br><br>0x8004255AL | The operation is not supported on removable media. |
| **VDS_E_SHRINK_SIZE_LESS_THAN_MIN**<br><br>0x80042573L | The specified shrink size is less than the minimum shrink size allowed. |
| **VDS_E_SHRINK_SIZE_TOO_BIG**<br><br>0x80042574L | The specified shrink size is too large and will cause the volume to be smaller than the minimum volume size. |

## Remarks

This method is a wrapper for the [IVdsVolumeShrink::Shrink](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeshrink-shrink) method. If you call **IVdsVolume::Shrink**, the value of the *uNumberOfBytesToRemove* parameter is used for the *ullDesiredNumberOfReclaimableBytes* and *ullMinNumberOfReclaimableBytes* parameters of **IVdsVolumeShrink::Shrink**.

Shrink and [extend](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-extend) operations are supported only on NTFS and RAW volumes.

Use this method to shrink the file system and volume. If VDS fails to shrink the volume, it stops the operation
without shrinking the file system.

Only one shrink or defragmentation operation can be performed at a time on each volume.**Windows Server 2008 and Windows Vista:** Only one shrink or defragmentation operation can be performed at a time on a computer.

If *uNumberOfBytesToRemove* is zero, the method fails. Otherwise, VDS rounds
*uNumberOfBytesToRemove* to a multiple of the file system cluster size.

Implementers must return a pointer to the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface for
this method, even if the call does not initiate an asynchronous operation.

You can use the [IVdsVolumeShrink::QueryMaxReclaimableBytes](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeshrink-querymaxreclaimablebytes) method to estimate the number of bytes to be reclaimed by the shrink operation. However, **QueryMaxReclaimableBytes** can return more bytes than are actually available.
## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsVolume](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume)

[IVdsVolume::Extend](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-extend)