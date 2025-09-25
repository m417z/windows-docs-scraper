# IVdsVolume::RemovePlex

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Removes one or more
specified plexes from the current volume, releasing the extents.

## Parameters

### `plexId` [in]

The GUID of the plex to be removed.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer, which VDS
initializes on return. Callers must release the interface. Use this pointer to cancel, wait for, or query the
status of the operation.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The plex was removed successfully. |
| **VDS_E_VOLUME_NOT_ONLINE**<br><br>0x8004243DL | The volume is not accessible. |
| **VDS_E_VOLUME_NOT_A_MIRROR**<br><br>0x80042445L | The volume is not a mirror. |

## Remarks

This operation cannot remove the last plex of a volume. Instead, use the
[IVdsVolume::Delete](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-delete) method to remove the last
remaining volume (the sole plex). This method is not valid for basic volumes, which have exactly one plex.

VDS does not dismount the volume when it removes a plex.

Implementers must return a pointer to the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface for
this method, regardless of whether the call initiates an asynchronous operation.

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsVolume](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume)

[IVdsVolume::Delete](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-delete)