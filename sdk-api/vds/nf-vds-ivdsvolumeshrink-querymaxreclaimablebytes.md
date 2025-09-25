# IVdsVolumeShrink::QueryMaxReclaimableBytes

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Retrieves the maximum number of bytes that can be reclaimed from the current volume.

## Parameters

### `pullMaxNumberOfReclaimableBytes` [out]

Pointer to a variable that upon successful completion receives the maximum number of bytes which can be reclaimed from the current volume. This number will always be a multiple of the file system cluster size, which is in turn a multiple of the disk sector size. This parameter is required and cannot be null.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **VDS_E_CANNOT_SHRINK**<br><br>0x8004251EL | The volume cannot be shrunk because the file system does not support it. |
| **VDS_E_DISK_REMOVEABLE**<br><br>0x8004255AL | The operation is not supported on removable media. |
| **RPX_X_NULL_REF_POINTER**<br><br>0x800706F4 | The *pullMaxNumberOfReclaimableBytes* parameter was null on input. |

## Remarks

This method can return more reclaimable bytes than are actually available.

## See also

[IVdsVolumeShrink](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumeshrink)