# IVdsVolumeShrink::Shrink

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Shrinks the volume and all plexes and returns the released extents.

## Parameters

### `ullDesiredNumberOfReclaimableBytes` [in]

Maximum number of bytes by which to shrink the size of the volume. The value of this parameter must be greater than or equal to the value of the *ullMinNumberOfReclaimableBytes* parameter. If the number of bytes specified is not a multiple of the file system cluster size, the **Shrink** method will round this value up to the next multiple of the file system cluster size.

### `ullMinNumberOfReclaimableBytes` [in]

Minimum number of bytes by which to shrink the size of the volume. If the volume size cannot be shrunk by at least this number of bytes, the **Shrink** method fails. If the number of bytes specified is not a multiple of the file system cluster size, the **Shrink** method will round this value up to the next multiple of the file system cluster size. Specify zero to indicate that no minimum number of reclaimable bytes is required for the **Shrink** method to succeed.

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
| **VDS_E_CANNOT_SHRINK**<br><br>0x8004251EL | The volume cannot be shrunk because the file system does not support it. |
| **VDS_E_DISK_REMOVEABLE**<br><br>0x8004255AL | The operation is not supported on removable media. |
| **VDS_E_INTERNAL_ERROR**<br><br>0x80042448L | An internal error occurred. Check the event log for more details. |
| **VDS_S_NO_NOTIFICATION**<br><br>0x00042517L | No volume arrival notification was received. You may need to call [IVdsService::Refresh](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-refresh). |
| **VDS_E_SHRINK_SIZE_TOO_BIG**<br><br>0x80042574L | The specified shrink size is too large and will cause the volume to be smaller than the minimum volume size. |
| **VDS_E_SHRINK_SIZE_LESS_THAN_MIN**<br><br>0x80042573L | The specified shrink size is less than the minimum shrink size allowed. |
| **VDS_E_VOLUME_NOT_HEALTHY**<br><br>0x8004243EL | The volume is not healthy. |
| **VDS_E_VOLUME_SIMPLE_SPANNED**<br><br>0x80042589L | The operation is only supported on simple or spanned volumes. |

## Remarks

The **Shrink** method moves the files so that they are as close as possible to the beginning of the volume, in order to consolidate free space at the end of the volume. (The amount of free space that can be consolidated at the end of the volume determines how much the volume can be shrunk.) It then truncates the file system volume, reducing its size, and then truncates the partition or dynamic volume.

In almost all cases, there will be some files that are immovable (that is, files that cannot be moved). For example, file system and storage driver metadata files are likely to be immovable. For this reason, the amount by which a volume can be shrunk is usually less than the total amount of free space on the volume.

The number and placement of immovable files can vary from one computer to the next, even if both computers are configured identically.

It is possible for a file to be temporarily immovable. For this reason, an application may be able to recover additional space if it calls this method a second time with the same parameters.

If the *ullDesiredNumberOfReclaimableBytes* and *ullMinNumberOfReclaimableBytes* parameters are both zero, the **Shrink** method will shrink the volume by as much as possible.

Shrink and [extend](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-extend) operations are supported only on NTFS and RAW volumes.

Use this method to shrink the file system and volume. If VDS fails to shrink the volume, it stops the operation without shrinking the file system.

Only one shrink or defragmentation operation can be performed at a time on each volume.**Windows Server 2008 and Windows Vista:** Only one shrink or defragmentation operation can be performed at a time on a computer.

Implementers must return a pointer to the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface for this method, even if the call does not initiate an asynchronous operation.

This method is identical to the [IVdsVolume::Shrink](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-shrink) method.

You can use the [IVdsVolumeShrink::QueryMaxReclaimableBytes](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeshrink-querymaxreclaimablebytes) method to estimate the number of bytes to be reclaimed by the shrink operation. However, **QueryMaxReclaimableBytes** can return more bytes than are actually available.

## See also

[IVdsVolume::Extend](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-extend)

[IVdsVolumeShrink](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumeshrink)