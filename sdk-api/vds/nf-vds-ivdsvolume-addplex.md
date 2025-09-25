# IVdsVolume::AddPlex

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Adds a volume as a plex to the
current volume.

## Parameters

### `VolumeId` [in]

The GUID of the volume to be added as a plex.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer, which VDS
initializes on return. Callers must release the interface. Use this pointer to cancel, wait for, or query the
status of the operation.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The plex was added successfully. |
| **VDS_S_GPT_BOOT_MIRRORED_TO_MBR**<br><br>0x80042469L | The boot volume on a GPT disk has been mirrored to an MBR disk. The new plex cannot be used to boot the computer. |
| **VDS_E_VOLUME_NOT_ONLINE**<br><br>0x8004243DL | The volume is not accessible. |
| **VDS_E_VOLUME_NOT_HEALTHY**<br><br>0x8004243EL | The volume is failing or has failed. |
| **VDS_E_VOLUME_SPANS_DISKS**<br><br>0x8004243FL | The volume spans multiple disks. |
| **VDS_E_REQUIRES_CONTIGUOUS_DISK_SPACE**<br><br>0x80042440L | The volume consists of multiple extents. |
| **VDS_E_INVALID_OPERATION**<br><br>0x80042415L | The source volume is smaller than the target volume. If the source volume is larger than the target volume, the target volume remains the same size and the operation succeeds. |

## Remarks

This operation is not valid for basic volumes, which have exactly one plex.

Use this method to add a volume as a plex to another volume. For example, a caller can create a volume (volume B),
specify volume B as a new plex to an existing volume (volume A), then remove volume B. The new plex of Volume A
occupies the same disk extents as did volume B.

**Note** VDS attempts to use the same extents, but cannot guarantee this behavior.

Callers can add a mirrored volume as a new plex to another volume. The resulting volume contains plexes equal in
number to the sum of the original volumes.

Implementers must return a pointer to the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface for
this method, regardless of whether the call initiates an asynchronous operation.

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsVolume](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume)

[Volume Plex Object](https://learn.microsoft.com/windows/desktop/VDS/volume-plex-object)