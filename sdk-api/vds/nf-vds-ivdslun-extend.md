# IVdsLun::Extend

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Extends a LUN by a specified
number of bytes.

## Parameters

### `ullNumberOfBytesToAdd` [in]

The number of bytes by which to extend the LUN. The number of bytes is not required to be an even multiple
of the block or sector size of the drives. The provider can round the number of bytes up or down to meet
alignment requirements or other restrictions. In most cases, the provider rounds up, ensuring that, with rare
exceptions, the LUN is extended by at least the number of bytes requested.

### `pDriveIdArray` [in]

A pointer to an array of drive GUIDs. The provider uses these drives to extend the LUN. The drives are
used in the specified sequence; the provider uses all of the extents on one drive before moving on to the next
and stops when the LUN has been extended by the requested number of bytes.

Alternatively, the caller can direct the provider to select the drives automatically by passing
**NULL** in this parameter and zero in the *lNumberOfDrives*
parameter. Note that passing **NULL** is valid only if the
*lNumberOfDrives* parameter is zero.

### `lNumberOfDrives` [in]

The number of drives specified in the *pDriveIdArray* parameter. If the caller
passes zero, the provider selects the drives.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer,
which VDS initializes on return. Callers must release the interface. Use this interface to cancel, wait for, or
query the status of the operation.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | This return value signals a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The LUN object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The LUN is in a failed state and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress; this operation cannot proceed until the previous operation or operations are complete. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | Can be returned from any method that takes a **VDS_OBJECT_ID** constant. This return value indicates that the identifier does not refer to an existing object. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | This operation or combination of parameters is not supported by this provider. |
| **VDS_E_NOT_ENOUGH_SPACE**<br><br>0x8004240FL | There is not enough usable space for this operation. |
| **VDS_E_NOT_ENOUGH_DRIVE**<br><br>0x80042410L | Not enough free drives are present in the subsystem to complete this operation. |

## Remarks

Callers can specify a list of drives for the provider to use for extending the LUN, or direct
the provider to select the drives automatically.

After the LUN is extended, the caller should use the [IOCTL_DISK_UPDATE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_update_properties) control code to make the updated disk size visible on the computer to which the LUN is unmasked.

Implementers must return a pointer to the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)
interface for this method, regardless of whether the call initiates an asynchronous operation.

If the *ullNumberOfBytesToAdd* parameter is greater than the number of bytes available
on the drives specified in the *pDriveIdArray* parameter, use the specified drives first
and then select from whatever other drives are available. If there are not enough such drives to extend the LUN
by the requested number of bytes, return an error and do not extend the LUN.

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslun)

[IVdsLun::Shrink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-shrink)

[IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun)