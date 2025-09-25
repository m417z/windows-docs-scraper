# VDS_ASYNC_OUTPUT structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
output of an async object. Output elements vary depending on the operation type.

## Members

### `type`

Discriminant for the union enumerated by
[VDS_ASYNC_OUTPUT_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_async_output_type).

| Value | Meaning |
| --- | --- |
| ****VDS_ASYNCOUT_CREATEPARTITION****<br><br>10 | See the following description of the **cp** structure. |
| ****VDS_ASYNCOUT_CREATEVOLUME****<br><br>1 | See the following description of the **cv** structure. |
| ****VDS_ASYNCOUT_BREAKVOLUMEPLEX****<br><br>5 | See the following description of the **bvp** structure. |
| ****VDS_ASYNCOUT_CREATELUN****<br><br>50 | See the following description of the **cl** structure. |
| ****VDS_ASYNCOUT_CREATETARGET****<br><br>62 | See the following description of the **ct** structure. |
| ****VDS_ASYNCOUT_CREATEPORTALGROUP****<br><br>63 | See the following description of the **cpg** structure. |
| ****VDS_ASYNCOUT_CREATE_VDISK****<br><br>200 | See the following description of the **cvd** structure. |

### `cp`

Structure used for the
[IVdsAdvancedDisk::CreatePartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-createpartition) or
[IVdsCreatePartitionEx::CreatePartitionEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdscreatepartitionex-createpartitionex)
method.

### `cp.ullOffset`

Actual offset of the created partition. This may not be the same as the
*ullOffset* parameter passed to the
[IVdsAdvancedDisk::CreatePartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-createpartition) or
[IVdsCreatePartitionEx::CreatePartitionEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdscreatepartitionex-createpartitionex)
method.

### `cp.volumeId`

The ID of the [volume object](https://learn.microsoft.com/windows/desktop/VDS/volume-object) associated with the
created partition.

### `cv`

Structure used for the
[IVdsPack::CreateVolume](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-createvolume) method.

### `cv.pVolumeUnk`

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) for the volume object. For more information, see
[Volume Object](https://learn.microsoft.com/windows/desktop/VDS/volume-object).

### `bvp`

Structure used for the [IVdsVolume::BreakPlex](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-breakplex)
method.

### `bvp.pVolumeUnk`

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) for the volume object. For more information, see
[Volume Object](https://learn.microsoft.com/windows/desktop/VDS/volume-object).

### `sv`

Structure used for the [IVdsVolume::Shrink](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-shrink)
method.

### `sv.ullReclaimedBytes`

The number of bytes that were reclaimed by the shrink operation.

**Windows Server 2003:**  This member is not supported until Windows Server 2003 R2.

### `cl`

Structure used for the
[IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun) method.

### `cl.pLunUnk`

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) for the LUN object. For more information, see
[LUN Object](https://learn.microsoft.com/windows/desktop/VDS/lun-object).

### `ct`

Structure used for the
[IVdsSubSystemIscsi::CreateTarget](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystemiscsi-createtarget) method.

### `ct.pTargetUnk`

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) for the target object.
For more information, see the [Target Object](https://learn.microsoft.com/windows/desktop/VDS/target-object).

### `cpg`

Structure used for the
[IVdsIscsiTarget::CreatePortalGroup](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-createportalgroup) method.

### `cpg.pPortalGroupUnk`

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) for the portal group object.
For more information, see the [Portal Group Object](https://learn.microsoft.com/windows/desktop/VDS/portal-group-object).

### `cvd`

Structure used for the
[IVdsVdProvider::CreateVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvdprovider-createvdisk) method.

### `cvd.pVDiskUnk`

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) for the virtual disk object.

## Remarks

The [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) method returns this structure
and adds a reference to any contained object produced by each method.
Callers must release the reference to the contained object.

## See also

[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_ASYNC_OUTPUT_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_async_output_type)