# IVdsVolume::Extend

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Expands the size of the current
volume by adding disk extents to each member of each plex.

## Parameters

### `pInputDiskArray` [in]

Pointer to an array of [VDS_INPUT_DISK](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_input_disk) structures;
one structure for each disk.

**Note** Callers should not use a default member index in conjunction with the
**Extend** method, unless the volume has only one
plex with only one member.

### `lNumberOfDisks` [in]

The total number of disks in the volume. Callers can pass zero when the volume plexes contain enough space to
extend the volume; *pInputDiskArray* must be **NULL**.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer, which VDS
initializes on return. Callers must release the interface. Use this pointer to cancel, wait for, or query the
status of the operation. If you call the
[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) method on this interface and a success HRESULT value is returned, you must
release the interfaces returned in the
[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer.
However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method competed successfully. |
| **VDS_E_CANNOT_EXTEND**<br><br>0x8004240EL | The volume cannot be extended because the file system on the volume does not support the operation. |
| **VDS_E_NOT_ENOUGH_SPACE**<br><br>0x8004240FL | There is not enough space to extend the volume. |
| **VDS_E_VOLUME_NOT_HEALTHY**<br><br>0x8004243EL | The volume is not healthy. |

## Remarks

This method extends a simple volume on the same disk, or creates a spanned volume by extending the volume to
multiple disks. Callers can extend a volume on a basic disk, however the disk extent must be contiguous with the
volume.

VDS automatically extends the file system to fit the extended volume size. The file system must support this
operation. VDS extends the file system, but not the volume, if a caller fails to specify the extents to be used.

Extend and [shrink](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeshrink-shrink) operations are supported only on NTFS and RAW volumes.

VDS applies the following rules when extending a volume:

* For simple and spanned plex types, VDS extends the sole member of the plex with any disk extent not already
  contributing to another plex—whether the extent is on the same disk or not. VDS uses disk extents in the order
  given by the caller, ignoring the member index of the extent. Unless on a basic disk, VDS can extend the sole
  member of a plex with any disk extent on the same disk or on a different disk.
* For striped and striped with parity plex types, VDS assigns an extent to the member of the plex as follows:
  + The extent goes to the member index specified by the caller.
  + The extent goes to the member index that occupies the same disk when the caller fails to specify a member ID.VDS never assigns an extent to multiple members on the same disk. The caller must specify a member for all
  extents or none; the caller cannot specify a member for some extents and not for others.

When the caller passes **NULL** for *pInputDiskArray* and zero for
*lNumberOfDisks*, VDS returns **S_FALSE** in the async object and
**S_OK** for the method. In this case, **S_OK** indicates that VDS
has started the operation, but the operation is synchronous.

Implementers must return a pointer to the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface for
this method, regardless of whether the call initiates an asynchronous operation.

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait)

[IVdsVolume](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume)

[IVdsVolumeShrink::Shrink](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeshrink-shrink)

[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output)

[VDS_INPUT_DISK](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_input_disk)